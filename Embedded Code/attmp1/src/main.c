/*
 * attmp1.c
 *
 * Created: 25-08-2019 11:50:15 PM
 * Author : Harshal
 */ 

#include <avr/io.h>

#include <asf.h>
#include <board.h>
#include <dac.h>
//#include <nvm.h>
#include <stdio.h>
#include <string.h>
#include <tc.h>
#include <stdlib.h>
#include <adc_driver.h>

#include "config.h"
#include "sound.h"

// use std c libs to make the implementation more robust

uint8_t out_str[12];
uint8_t out_str_len = 12;
// uint8_t received_byte;   // send just one byte to make the buzzer on 
//uint8_t i;

// Timer Variables
uint8_t Counter1ms = 0;
uint8_t Counter10ms = 0;
uint8_t Counter100ms = 0;
uint8_t Counter1s = 0;
uint8_t Counter10s = 0;
uint8_t Counter1m = 0;
uint8_t Counter2m = 0;

//Temperature variables
uint16_t temp_array[10];    // to compare last 10 values
uint32_t avg_temp = 0;
//Temperature sensor calibration data.
static uint16_t tempsense;
//The final, computed temperature.
uint16_t final_temperature;
uint16_t final_temperature_c;
char final_temp_char[3];


// for light sensor
uint16_t ADC_result;    // has the 12 bit light sensor data
char light_data[5];     // max value 65something
int8_t offset;	
static float lightsense;   


uint8_t received_byte=0;
uint8_t receive_flag = 0;

char loop_arr[9] = "In loop\r\n";

uint8_t MySoundFlag = 0;


//brief Callback function for ADC interrupts
static void adc_handler(ADC_t *adc, uint8_t ch_mask, adc_result_t result)
{
	uint32_t temperature;

	//Compute current temperature in Kelvin
	temperature = (uint32_t)result * 358;
	temperature /= tempsense;

	// Store temperature in global variable.
	final_temperature = temperature & 0xffff;
	
	// Start next conversion.
	adc_start_conversion(adc, ch_mask);
}

static void adc_handler_light(ADC_t *adc, uint8_t ch_mask, adc_result_t result)
{
	uint32_t light;

	//Compute current temperature in Kelvin
	light = (uint32_t)result;

	// Linearly mapping light sensor data between 0 to 100
	lightsense = light & 0xffff;
	lightsense = (4095 - lightsense) / 4095;
	lightsense = lightsense * 100;
	
	/*
	for (int i = 0;i<9;i++){
		usart_putchar(USART_SERIAL, loop_arr[i]);
	}
	*/
	
	// Start next conversion.
	adc_start_conversion(adc, ch_mask);
}

void kelvintocelcius(uint16_t *temp){
	final_temperature_c = *temp - 273 - 10;
}



static void TimerCallback(void){
	Counter1ms++;
	
	if (Counter1ms >= 10){
		Counter10ms++;
		Counter1ms = 0;
		// string for the protocol: @:tempsensor(till 2 decimals):light_sensor_data:\r\n
	}
	
	if ( Counter10ms >= 10 ){
		Counter100ms++;       
		Counter10ms = 0;
		adc_start_conversion(&ADCA, ADC_CH0);
	}
	
	// check counters once
	if ( Counter100ms >= 10){  // going through this in 1 sec  => 1sec(real time) = 10sec(in code)
		Counter1s++;
		Counter100ms = 0;
		
	}
	
	if (Counter1s >= 5){
		MySoundFlag = 0;
		sound_stop_timer();
	}

	if (Counter1s >= 10){
		Counter1s = 0;
		Counter10s++;
		
		
		MySoundFlag = 1;
		// put these lines in the main
		kelvintocelcius(&final_temperature);
		
		memcpy(&temp_array[1], &temp_array[0], 9*sizeof(uint16_t));
		temp_array[0] = final_temperature_c;
		memset(&out_str[0],0x00,sizeof(uint8_t)*out_str_len);
		
		itoa(final_temperature_c,&final_temp_char[0],10);
		itoa(lightsense,&light_data[0],10);
		sprintf(&out_str[0],"@:%s:%s:\r\n",final_temp_char,light_data);
		//sprintf(&out_str[0],"<%s,%s>\n",final_temp_char,light_data);
		for (int i = 0;i<out_str_len;i++){
			usart_putchar(USART_SERIAL, out_str[i]);
		}
		
		//received_byte = usart_getchar(USART_SERIAL);
		
		for (int i=0;i<10;i++){
			avg_temp += temp_array[i];
		}
		avg_temp = avg_temp / 10;
		
		if (avg_temp < 20 && receive_flag == 0 && MySoundFlag == 1){
			//play sound 1
			sound_play_note(0x03);
			while (sound_is_playing() && MySoundFlag == 1);
		}
		else if (avg_temp > 30 && receive_flag == 0 && MySoundFlag == 1){
			//play sound 
			sound_play_note(0x01);
			while (sound_is_playing() && MySoundFlag == 1);
		}
		
		/*
		if (received_byte != '!'){
			sound_play_note(0x04);
			while (sound_is_playing());
			receive_flag = 1;
		}
		else{
			receive_flag = 0;
		}
		*/
		//sound_play_note(0x01);
		
	}
	
	if (Counter10s >= 6){
		Counter1m++;
		Counter10s = 0;
	}
	
	if (Counter1m >= 2){
		Counter1m = 0;
	}
	
	tc_clear_overflow(&TIMER_COUNTER0);    // is this line necessary?
}

struct adc_config         adc_conf;
struct adc_channel_config adcch_conf;

void setup_temp_adc(void){
	
	// Initialize configuration structures.
	adc_read_configuration(&ADCA, &adc_conf);
	adcch_read_configuration(&ADCA, ADC_CH0, &adcch_conf);

	//ADCCH_POS_PIN1

	//Configure ADC module
	adc_set_conversion_parameters(&adc_conf, ADC_SIGN_OFF, ADC_RES_12, ADC_REF_BANDGAP);
	adc_set_clock_rate(&adc_conf, 200000UL);
	adc_set_conversion_trigger(&adc_conf, ADC_TRIG_MANUAL, 1, 0);
	adc_enable_internal_input(&adc_conf, ADC_INT_TEMPSENSE);
	adc_write_configuration(&ADCA, &adc_conf);
	adc_set_callback(&ADCA, &adc_handler);

	// Configure ADC channel 0:
	adcch_set_input(&adcch_conf, ADCCH_POS_TEMPSENSE, ADCCH_NEG_NONE, 1);
	adcch_set_interrupt_mode(&adcch_conf, ADCCH_MODE_COMPLETE);
	adcch_enable_interrupt(&adcch_conf);
	adcch_write_configuration(&ADCA, ADC_CH0, &adcch_conf);

	// Get measurement for 85 degrees C (358 kelvin) from calibration data.
	tempsense = adc_get_calibration_data(ADC_CAL_TEMPSENSE);

	// Enable the ADC and start the first conversion.
	adc_enable(&ADCA);
	adc_start_conversion(&ADCA, ADC_CH0);
}

struct adc_config         adc_conf1;
struct adc_channel_config adcch_conf1;

void setup_light_sensor(void){
	// Initialize configuration structures.
	adc_read_configuration(&ADCB, &adc_conf1);
	adcch_read_configuration(&ADCB, ADC_CH1, &adcch_conf1);

	//ADCCH_POS_PIN1

	//Configure ADC module
	adc_set_conversion_parameters(&adc_conf1, ADC_SIGN_OFF, ADC_RES_12, ADC_REF_BANDGAP);
	adc_set_clock_rate(&adc_conf1, 200000UL);
	adc_set_conversion_trigger(&adc_conf1, ADC_TRIG_MANUAL, 1, 0);
	adc_enable_internal_input(&adc_conf1, ADC_INT_TEMPSENSE);
	adc_write_configuration(&ADCB, &adc_conf1);
	adc_set_callback(&ADCB, &adc_handler_light);

	// Configure ADC channel 0:
	adcch_set_input(&adcch_conf1, ADCCH_POS_PIN1, ADCCH_NEG_NONE, 1);
	adcch_set_interrupt_mode(&adcch_conf1, ADCCH_MODE_COMPLETE);
	adcch_enable_interrupt(&adcch_conf1);
	adcch_write_configuration(&ADCB, ADC_CH1, &adcch_conf1);

	// Get measurement for 85 degrees C (358 kelvin) from calibration data.
	lightsense = adc_get_calibration_data(ADC_CAL_TEMPSENSE);

	// Enable the ADC and start the first conversion.
	adc_enable(&ADCB);
	adc_start_conversion(&ADCB, ADC_CH1);
}

void InitializeSystem(void){
	pmic_init();       // enables interrupt controller
	sysclk_init();		// enables clock system
	cpu_irq_enable();		// enables interrupts
	board_init();
	irq_initialize_vectors();
	setup_temp_adc();
	sound_init();
}


int main(void)
{
	InitializeSystem();
	// for UART implementation
	static usart_rs232_options_t USART_SERIAL_OPTIONS = {
		.baudrate = USART_SERIAL_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits = USART_SERIAL_STOP_BIT
	};
	
	// Initialize usart driver in RS232 mode
	usart_init_rs232(USART_SERIAL, &USART_SERIAL_OPTIONS);
		
	// for timer
	tc_enable(&TIMER_COUNTER0);		//enables the timer module
	tc_set_overflow_interrupt_callback(&TIMER_COUNTER0,TimerCallback);		// sets the callback function
	tc_set_wgm(&TIMER_COUNTER0, TC_WG_NORMAL);		// sets waveform mode?
	tc_set_overflow_interrupt_level(&TIMER_COUNTER0, TC_INT_LVL_LO);	//
	tc_write_period(&TIMER_COUNTER0, 50000);  // changed the timer counter from 50000
	tc_set_resolution(&TIMER_COUNTER0, 500000);      // this corresponds to 2us  (100ms = 50000 * 2us)
	tc_write_clock_source(&TIMER_COUNTER0, TC_CLKSEL_DIV1_gc);		// sets clock source, after this timer starts counting (this line was not in the example)
		
	setup_light_sensor();
	
	TimerCallback();
	
	char loop_arr1[9] = "In loo1\r\n";
	while(1){
		
		// for debugging
		/*
		for (int i = 0;i<9;i++){
			usart_putchar(USART_SERIAL, loop_arr1[i]);
		}
		*/
		
		if (Counter1s == 0){   // change 1s counter to 2m counter later
			for (int i=0;i<10;i++){
				avg_temp += temp_array[i];
			}
			avg_temp = avg_temp / 10;
			if (avg_temp < 20 && MySoundFlag == 1){
				//play sound 1
				sound_play_note(0x01);
				while (sound_is_playing() && MySoundFlag == 1);
			}
			else if (avg_temp > 30 && MySoundFlag == 1){
				//play sound 2
				sound_play_note(0x02);
				while (sound_is_playing() && MySoundFlag == 1);
			}
			
			// unable to send data(understood from the response string)
			//play sound 3
		}

		//delay_ms(5);
	}
		
}
	


