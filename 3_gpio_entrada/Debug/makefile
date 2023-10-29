################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 3_gpio_entrada
BUILD_ARTIFACT_EXTENSION := axf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: 3_gpio_entrada.axf

# Tool invocations
3_gpio_entrada.axf: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\2001t\Documents\MCUXpressoIDE_11.8.0_1165\workspace\CMSISv2p00_LPC17xx\Debug" -Xlinker -Map="3_gpio_entrada.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "3_gpio_entrada_Debug.ld" -o "3_gpio_entrada.axf" $(OBJS) $(USER_OBJS) $(LIBS) -lCMSISv2p00_LPC17xx
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 3_gpio_entrada.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "3_gpio_entrada.axf"; # arm-none-eabi-objcopy -v -O binary "3_gpio_entrada.axf" "3_gpio_entrada.bin" ; # checksum -p LPC1769 -d "3_gpio_entrada.bin";
	-@echo ' '

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
