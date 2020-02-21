################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/services/ \
../src/ASF/common/services/clock/ \
../src/ASF/common/services/clock/xmega/ \
../src/ASF/common/services/gpio/ \
../src/ASF/common/services/gpio/xmega_gpio/ \
../src/ASF/common/services/ioport/ \
../src/ASF/common/services/ioport/xmega/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/ASF/common/utils/make/ \
../src/ASF/xmega/ \
../src/ASF/xmega/boards/ \
../src/ASF/xmega/boards/xmega_a1_xplained/ \
../src/ASF/xmega/drivers/ \
../src/ASF/xmega/drivers/cpu/ \
../src/ASF/xmega/drivers/pmic/ \
../src/ASF/xmega/drivers/usart/ \
../src/ASF/xmega/utils/ \
../src/ASF/xmega/utils/assembler/ \
../src/ASF/xmega/utils/bit_handling/ \
../src/ASF/xmega/utils/preprocessor/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/ASF/common/services/clock/xmega/sysclk.c \
../src/ASF/common/services/ioport/xmega/ioport_compat.c \
../src/ASF/xmega/boards/xmega_a1_xplained/init.c \
../src/ASF/xmega/drivers/usart/usart.c \
../src/usart_example.c


PREPROCESSING_SRCS +=  \
../src/ASF/xmega/drivers/cpu/ccp.s


ASM_SRCS += 


OBJS +=  \
src/ASF/common/services/clock/xmega/sysclk.o \
src/ASF/common/services/ioport/xmega/ioport_compat.o \
src/ASF/xmega/boards/xmega_a1_xplained/init.o \
src/ASF/xmega/drivers/cpu/ccp.o \
src/ASF/xmega/drivers/usart/usart.o \
src/usart_example.o

OBJS_AS_ARGS +=  \
src/ASF/common/services/clock/xmega/sysclk.o \
src/ASF/common/services/ioport/xmega/ioport_compat.o \
src/ASF/xmega/boards/xmega_a1_xplained/init.o \
src/ASF/xmega/drivers/cpu/ccp.o \
src/ASF/xmega/drivers/usart/usart.o \
src/usart_example.o

C_DEPS +=  \
src/ASF/common/services/clock/xmega/sysclk.d \
src/ASF/common/services/ioport/xmega/ioport_compat.d \
src/ASF/xmega/boards/xmega_a1_xplained/init.d \
src/ASF/xmega/drivers/cpu/ccp.d \
src/ASF/xmega/drivers/usart/usart.d \
src/usart_example.d

C_DEPS_AS_ARGS +=  \
src/ASF/common/services/clock/xmega/sysclk.d \
src/ASF/common/services/ioport/xmega/ioport_compat.d \
src/ASF/xmega/boards/xmega_a1_xplained/init.d \
src/ASF/xmega/drivers/cpu/ccp.d \
src/ASF/xmega/drivers/usart/usart.d \
src/usart_example.d

OUTPUT_FILE_PATH +=USART_EXAMPLE1.elf

OUTPUT_FILE_PATH_AS_ARGS +=USART_EXAMPLE1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
src/ASF/common/services/clock/xmega/sysclk.o: ../src/ASF/common/services/clock/xmega/sysclk.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DIOPORT_XMEGA_COMPAT -DBOARD=XMEGA_A1_XPLAINED  -I"D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\include" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/xmega/utils/preprocessor" -I"../src/ASF/xmega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/common/boards" -I"../src/ASF/xmega/drivers/usart" -I"../src/ASF/common/services/clock" -I"../src/ASF/xmega/drivers/cpu" -I"../src/ASF/xmega/drivers/pmic" -I"../src/ASF/xmega/boards/xmega_a1_xplained" -I"../src/ASF/xmega/boards" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/common/services/ioport/xmega/ioport_compat.o: ../src/ASF/common/services/ioport/xmega/ioport_compat.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DIOPORT_XMEGA_COMPAT -DBOARD=XMEGA_A1_XPLAINED  -I"D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\include" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/xmega/utils/preprocessor" -I"../src/ASF/xmega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/common/boards" -I"../src/ASF/xmega/drivers/usart" -I"../src/ASF/common/services/clock" -I"../src/ASF/xmega/drivers/cpu" -I"../src/ASF/xmega/drivers/pmic" -I"../src/ASF/xmega/boards/xmega_a1_xplained" -I"../src/ASF/xmega/boards" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/xmega/boards/xmega_a1_xplained/init.o: ../src/ASF/xmega/boards/xmega_a1_xplained/init.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DIOPORT_XMEGA_COMPAT -DBOARD=XMEGA_A1_XPLAINED  -I"D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\include" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/xmega/utils/preprocessor" -I"../src/ASF/xmega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/common/boards" -I"../src/ASF/xmega/drivers/usart" -I"../src/ASF/common/services/clock" -I"../src/ASF/xmega/drivers/cpu" -I"../src/ASF/xmega/drivers/pmic" -I"../src/ASF/xmega/boards/xmega_a1_xplained" -I"../src/ASF/xmega/boards" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/ASF/xmega/drivers/usart/usart.o: ../src/ASF/xmega/drivers/usart/usart.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DIOPORT_XMEGA_COMPAT -DBOARD=XMEGA_A1_XPLAINED  -I"D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\include" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/xmega/utils/preprocessor" -I"../src/ASF/xmega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/common/boards" -I"../src/ASF/xmega/drivers/usart" -I"../src/ASF/common/services/clock" -I"../src/ASF/xmega/drivers/cpu" -I"../src/ASF/xmega/drivers/pmic" -I"../src/ASF/xmega/boards/xmega_a1_xplained" -I"../src/ASF/xmega/boards" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/usart_example.o: ../src/usart_example.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -DDEBUG -DIOPORT_XMEGA_COMPAT -DBOARD=XMEGA_A1_XPLAINED  -I"D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\include" -I"../src/ASF/common/services/gpio" -I"../src/ASF/common/services/ioport" -I"../src/ASF/xmega/utils/preprocessor" -I"../src/ASF/xmega/utils" -I"../src/ASF/common/utils" -I"../src/ASF/common/boards" -I"../src/ASF/xmega/drivers/usart" -I"../src/ASF/common/services/clock" -I"../src/ASF/xmega/drivers/cpu" -I"../src/ASF/xmega/drivers/pmic" -I"../src/ASF/xmega/boards/xmega_a1_xplained" -I"../src/ASF/xmega/boards" -I"../src" -I"../src/config"  -O1 -fdata-sections -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g3 -Wall -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler
src/ASF/xmega/drivers/cpu/ccp.o: ../src/ASF/xmega/drivers/cpu/ccp.s
	@echo Building file: $<
	@echo Invoking: AVR/GNU Assembler : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -mrelax -DBOARD=XMEGA_A1_XPLAINED -DIOPORT_XMEGA_COMPAT -I "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\include" -I "../src/ASF/common/services/gpio" -I "../src/ASF/common/services/ioport" -I "../src/ASF/xmega/utils/preprocessor" -I "../src/ASF/xmega/utils" -I "../src/ASF/common/utils" -I "../src/ASF/common/boards" -I "../src/ASF/xmega/drivers/usart" -I "../src/ASF/common/services/clock" -I "../src/ASF/xmega/drivers/cpu" -I "../src/ASF/xmega/drivers/pmic" -I "../src/ASF/xmega/boards/xmega_a1_xplained" -I "../src/ASF/xmega/boards" -I "../src" -I "../src/config"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	





ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="USART_EXAMPLE1.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atxmega128a1 -B "D:\Program Files in D\Atmel\Studio\7.0\Packs\atmel\XMEGAA_DFP\1.1.68\gcc\dev\atxmega128a1" -Wl,--relax -Wl,--section-start=.BOOT=0x20000  
	@echo Finished building target: $@
	"D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "USART_EXAMPLE1.elf" "USART_EXAMPLE1.hex"
	"D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "USART_EXAMPLE1.elf" "USART_EXAMPLE1.eep" || exit 0
	"D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "USART_EXAMPLE1.elf" > "USART_EXAMPLE1.lss"
	"D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "USART_EXAMPLE1.elf" "USART_EXAMPLE1.srec"
	"D:\Program Files in D\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "USART_EXAMPLE1.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "USART_EXAMPLE1.elf" "USART_EXAMPLE1.a" "USART_EXAMPLE1.hex" "USART_EXAMPLE1.lss" "USART_EXAMPLE1.eep" "USART_EXAMPLE1.map" "USART_EXAMPLE1.srec" "USART_EXAMPLE1.usersignatures"
	