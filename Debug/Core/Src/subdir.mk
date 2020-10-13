################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ADC.c \
../Core/Src/IO.c \
../Core/Src/WS2812.c \
../Core/Src/comparator.c \
../Core/Src/dshot.c \
../Core/Src/eeprom.c \
../Core/Src/functions.c \
../Core/Src/main.c \
../Core/Src/peripherals.c \
../Core/Src/phaseouts.c \
../Core/Src/serial_telemetry.c \
../Core/Src/sounds.c \
../Core/Src/stm32g0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32g0xx.c 

OBJS += \
./Core/Src/ADC.o \
./Core/Src/IO.o \
./Core/Src/WS2812.o \
./Core/Src/comparator.o \
./Core/Src/dshot.o \
./Core/Src/eeprom.o \
./Core/Src/functions.o \
./Core/Src/main.o \
./Core/Src/peripherals.o \
./Core/Src/phaseouts.o \
./Core/Src/serial_telemetry.o \
./Core/Src/sounds.o \
./Core/Src/stm32g0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32g0xx.o 

C_DEPS += \
./Core/Src/ADC.d \
./Core/Src/IO.d \
./Core/Src/WS2812.d \
./Core/Src/comparator.d \
./Core/Src/dshot.d \
./Core/Src/eeprom.d \
./Core/Src/functions.d \
./Core/Src/main.d \
./Core/Src/peripherals.d \
./Core/Src/phaseouts.d \
./Core/Src/serial_telemetry.d \
./Core/Src/sounds.d \
./Core/Src/stm32g0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32g0xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ADC.o: ../Core/Src/ADC.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/ADC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/IO.o: ../Core/Src/IO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/IO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/WS2812.o: ../Core/Src/WS2812.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/WS2812.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/comparator.o: ../Core/Src/comparator.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/comparator.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/dshot.o: ../Core/Src/dshot.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/dshot.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/eeprom.o: ../Core/Src/eeprom.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/eeprom.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/functions.o: ../Core/Src/functions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/functions.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/main.o: ../Core/Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/peripherals.o: ../Core/Src/peripherals.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/peripherals.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/phaseouts.o: ../Core/Src/phaseouts.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/phaseouts.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/serial_telemetry.o: ../Core/Src/serial_telemetry.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/serial_telemetry.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/sounds.o: ../Core/Src/sounds.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sounds.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/stm32g0xx_it.o: ../Core/Src/stm32g0xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/stm32g0xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/syscalls.o: ../Core/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/sysmem.o: ../Core/Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/system_stm32g0xx.o: ../Core/Src/system_stm32g0xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DSTM32G071xx '-DHSE_VALUE=8000000' '-DLSI_VALUE=32000' '-DHSE_STARTUP_TIMEOUT=100' '-DHSI_VALUE=16000000' -DDEBUG '-DLSE_STARTUP_TIMEOUT=5000' '-DLSE_VALUE=32768' '-DDATA_CACHE_ENABLE=1' '-DVDD_VALUE=3300' '-DINSTRUCTION_CACHE_ENABLE=1' '-DEXTERNAL_CLOCK_VALUE=48000' -DUSE_FULL_LL_DRIVER '-DPREFETCH_ENABLE=0' -c -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32G0xx/Include -I../Drivers/STM32G0xx_HAL_Driver/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/system_stm32g0xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

