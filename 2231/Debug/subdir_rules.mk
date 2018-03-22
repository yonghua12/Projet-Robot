################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Motor.obj: ../Motor.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_18.1.1.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="D:/code composant/ccsv6/ccs_base/msp430/include" --include_path="D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_18.1.1.LTS/include" --advice:power=all --define=__MSP430G2231__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Motor.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_18.1.1.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="D:/code composant/ccsv6/ccs_base/msp430/include" --include_path="D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_18.1.1.LTS/include" --advice:power=all --define=__MSP430G2231__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


