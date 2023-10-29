################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/1_gpio_salida.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c 

C_DEPS += \
./src/1_gpio_salida.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d 

OBJS += \
./src/1_gpio_salida.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/1_gpio_salida.d ./src/1_gpio_salida.o ./src/cr_startup_lpc175x_6x.d ./src/cr_startup_lpc175x_6x.o ./src/crp.d ./src/crp.o

.PHONY: clean-src

