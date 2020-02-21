/*
 * config.h
 *
 * Created: 30-08-2019 09:21:38 PM
 *  Author: Harshal
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#define TIMER_COUNTER0 TCC1
#define SOUND_TIMER_MODULE     TCC0
#define SOUND_TIMER_EVENT      EVSYS_CHMUX_TCC0_OVF_gc


// UART params
#define USART_SERIAL             &USARTC0
#define USART_SERIAL_BAUDRATE    115200
#define USART_SERIAL_CHAR_LENGTH         USART_CHSIZE_8BIT_gc
#define USART_SERIAL_PARITY              USART_PMODE_DISABLED_gc
#define USART_SERIAL_STOP_BIT            false

// Light sensor params
#define LIGHT_SAMPLE_RATE   (10)   /* Light sensor sample rate (Hz) */
#define PROX_SAMPLE_RATE    (10)   /* Proximity sensor sample rate (Hz) */

#define SET_PROX_THRESHOLD  (true) /* If true, manually set proximity
	                            * threshold */
#define PROX_THRESHOLD      (100)  /* Manual prox sensor threshold for "near" */

#define SET_PROX_CURRENT    (true) /* If true, manually set proximity current */
#define PROX_CURRENT_mA     (50)   /* Current for proximity sensor LEDs (mA) */

#define PRINT_BANNER        (true) /* If true, print sensor config
	                            * information */
#define SCALED_DATA         (true) /* If true, convert sensor data to standard
	                            * units. */

//! \note This is pin 2 on port A.
#define SOUNDMODE_SENSE_PIN    IOPORT_CREATE_PIN(PORTA, 2)
//! \note This is pin 3 on port A.
#define SOUNDMODE_GROUND_PIN   IOPORT_CREATE_PIN(PORTA, 3)

// for light sensor
#define ADC_INPUT ADC_CH_MUXPOS_PIN1_gc


// Function prototypes
extern void InitializeSystem(void);
extern void kelvintocelcius(uint16_t *temp);
extern void setup_temp_adc(void);
extern void setup_light_sensor(void);

#endif /* CONFIG_H_ */