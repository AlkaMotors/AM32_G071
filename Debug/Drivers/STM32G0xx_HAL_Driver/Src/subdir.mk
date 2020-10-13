################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_comp.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_tim.c \
../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.c 

OBJS += \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_comp.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_tim.o \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.o 

C_DEPS += \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_comp.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_tim.d \
./Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_adc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_comp.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_comp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_comp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_dma.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_exti.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_pwr.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_rcc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_tim.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_tim.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_tim.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.o: ../Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_ll_utils.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

