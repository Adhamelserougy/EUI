################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./Applications/Brightness_Control/Brightness_Control.obj" \
"./Applications/Calculator/Calculator.obj" \
"./Applications/Edge_Time_Capture/Edge_Time_Capture.obj" \
"./Applications/Periodic_Delay/Periodic_Delay.obj" \
"./Applications/Stopwatch/Stopwatch.obj" \
"./HAL/Keypad/Keypad.obj" \
"./HAL/LCD/LCD.obj" \
"./MCAL/GPIO_Drivers/GPIO_CTRL.obj" \
"./MCAL/GPIO_Drivers/GPIO_Interrupts.obj" \
"./MCAL/Interrupts/Interrupt_Handlers.obj" \
"./MCAL/Interrupts/NVIC.obj" \
"./MCAL/Timer_Drivers/Timer.obj" \
"./UTILS/Delay.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Applications/Brightness_Control/subdir_vars.mk
-include Applications/Calculator/subdir_vars.mk
-include Applications/Edge_Time_Capture/subdir_vars.mk
-include Applications/Periodic_Delay/subdir_vars.mk
-include Applications/Stopwatch/subdir_vars.mk
-include HAL/Keypad/subdir_vars.mk
-include HAL/LCD/subdir_vars.mk
-include MCAL/GPIO_Drivers/subdir_vars.mk
-include MCAL/Interrupts/subdir_vars.mk
-include MCAL/Timer_Drivers/subdir_vars.mk
-include UTILS/subdir_vars.mk
-include subdir_rules.mk
-include Applications/Brightness_Control/subdir_rules.mk
-include Applications/Calculator/subdir_rules.mk
-include Applications/Edge_Time_Capture/subdir_rules.mk
-include Applications/Periodic_Delay/subdir_rules.mk
-include Applications/Stopwatch/subdir_rules.mk
-include HAL/Keypad/subdir_rules.mk
-include HAL/LCD/subdir_rules.mk
-include MCAL/GPIO_Drivers/subdir_rules.mk
-include MCAL/Interrupts/subdir_rules.mk
-include MCAL/Timer_Drivers/subdir_rules.mk
-include UTILS/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Drivers2.out \

EXE_OUTPUTS__QUOTED += \
"Drivers2.out" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Drivers2.out"

# Tool invocations
Drivers2.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: Arm Linker'
	"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"Drivers2.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/lib" -i"C:/ti/ccs1230/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="Drivers2_linkInfo.xml" --rom_model -o "Drivers2.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "Applications\Brightness_Control\Brightness_Control.obj" "Applications\Calculator\Calculator.obj" "Applications\Edge_Time_Capture\Edge_Time_Capture.obj" "Applications\Periodic_Delay\Periodic_Delay.obj" "Applications\Stopwatch\Stopwatch.obj" "HAL\Keypad\Keypad.obj" "HAL\LCD\LCD.obj" "MCAL\GPIO_Drivers\GPIO_CTRL.obj" "MCAL\GPIO_Drivers\GPIO_Interrupts.obj" "MCAL\Interrupts\Interrupt_Handlers.obj" "MCAL\Interrupts\NVIC.obj" "MCAL\Timer_Drivers\Timer.obj" "UTILS\Delay.obj" 
	-$(RM) "main.d" "tm4c123gh6pm_startup_ccs.d" "Applications\Brightness_Control\Brightness_Control.d" "Applications\Calculator\Calculator.d" "Applications\Edge_Time_Capture\Edge_Time_Capture.d" "Applications\Periodic_Delay\Periodic_Delay.d" "Applications\Stopwatch\Stopwatch.d" "HAL\Keypad\Keypad.d" "HAL\LCD\LCD.d" "MCAL\GPIO_Drivers\GPIO_CTRL.d" "MCAL\GPIO_Drivers\GPIO_Interrupts.d" "MCAL\Interrupts\Interrupt_Handlers.d" "MCAL\Interrupts\NVIC.d" "MCAL\Timer_Drivers\Timer.d" "UTILS\Delay.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

