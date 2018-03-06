################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Driver_Motor_IR.obj: ../Driver_Motor_IR.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/bin/cl430" -vmsp -Ooff --include_path="D:/code composant/ccsv6/ccs_base/msp430/include" --include_path="D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/include" --define=__MSP430G2231__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Driver_Motor_IR.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Driver_SPI.obj: ../Driver_SPI.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/bin/cl430" -vmsp -Ooff --include_path="D:/code composant/ccsv6/ccs_base/msp430/include" --include_path="D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/include" --define=__MSP430G2231__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Driver_SPI.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

init.obj: ../init.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/bin/cl430" -vmsp -Ooff --include_path="D:/code composant/ccsv6/ccs_base/msp430/include" --include_path="D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/include" --define=__MSP430G2231__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="init.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/bin/cl430" -vmsp -Ooff --include_path="D:/code composant/ccsv6/ccs_base/msp430/include" --include_path="D:/code composant/ccsv6/tools/compiler/ti-cgt-msp430_17.9.0.STS/include" --define=__MSP430G2231__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


