################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./Driver_ADC.obj" \
"./Driver_GPIO.obj" \
"./Driver_IR.obj" \
"./Driver_Motor.obj" \
"./Driver_SPI.obj" \
"./Driver_UART.obj" \
"./Scan_IR.obj" \
"./main.obj" \
"./robot.obj" \
"../lnk_msp430g2553.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TP3\ 2553\ moteur.out \

EXE_OUTPUTS__QUOTED += \
"TP3 2553 moteur.out" \

BIN_OUTPUTS += \
TP3\ 2553\ moteur.hex \

BIN_OUTPUTS__QUOTED += \
"TP3 2553 moteur.hex" \


# All Target
all: TP3\ 2553\ moteur.out

# Tool invocations
TP3\ 2553\ moteur.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/bin/cl430" -vmsp -Ooff --define=__MSP430G2553__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"TP3 2553 moteur.map" --heap_size=80 --stack_size=80 -i"D:/code composant/ccsv6/ccs_base/msp430/include" -i"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/lib" -i"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="TP3 2553 moteur_linkInfo.xml" --rom_model -o "TP3 2553 moteur.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

TP3\ 2553\ moteur.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/bin/hex430" --memwidth=8 --romwidth=8 -o "TP3 2553 moteur.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Driver_ADC.pp" "Driver_GPIO.pp" "Driver_IR.pp" "Driver_Motor.pp" "Driver_SPI.pp" "Driver_UART.pp" "Scan_IR.pp" "main.pp" "robot.pp" 
	-$(RM) "Driver_ADC.obj" "Driver_GPIO.obj" "Driver_IR.obj" "Driver_Motor.obj" "Driver_SPI.obj" "Driver_UART.obj" "Scan_IR.obj" "main.obj" "robot.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

