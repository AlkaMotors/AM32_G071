///*
// * ADC.c
// *
// *  Created on: May 20, 2020
// *      Author: Alka
// */
//#include "ADC.h"
//
//
//#ifdef USE_ADC_INPUT
//uint16_t ADCDataDMA[4];
//#else
//uint16_t ADCDataDMA[3];
//#endif
//
//
//extern uint16_t ADC_raw_temp;
//extern uint16_t ADC_raw_volts;
//extern uint16_t ADC_raw_current;
//extern uint16_t ADC_raw_input;
//
//#define ADC_DELAY_CALIB_ENABLE_CPU_CYCLES  (LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES * 64)
//
//
//
//void ADC_DMA_Callback(){  // read dma buffer and set extern variables
//
//#ifdef USE_ADC_INPUT
//	ADC_raw_temp =    ADCDataDMA[3];
//	ADC_raw_volts  = ADCDataDMA[1]/2;
//	ADC_raw_current =ADCDataDMA[2];
//	ADC_raw_input = ADCDataDMA[0];
//
//
//#else
//ADC_raw_temp =    ADCDataDMA[2];
//ADC_raw_volts  = ADCDataDMA[1];
//ADC_raw_current =ADCDataDMA[0];
//#endif
//}
////
////
////
////
////
////
////
//
//void Configure_DMA(void)
//{
//  /*## Configuration of NVIC #################################################*/
//  /* Configure NVIC to enable DMA interruptions */
//		NVIC_SetPriority(DMA1_Channel2_3_IRQn, 1);
//		NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
//
//  /*## Configuration of DMA ##################################################*/
//  /* Enable the peripheral clock of DMA */
//  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
//
//  /* Configure the DMA transfer */
//  /*  - DMA transfer in circular mode to match with ADC configuration:        */
//  /*    DMA unlimited requests.                                               */
//  /*  - DMA transfer from ADC without address increment.                      */
//  /*  - DMA transfer to memory with address increment.                        */
//  /*  - DMA transfer from ADC by half-word to match with ADC configuration:   */
//  /*    ADC resolution 12 bits.                                               */
//  /*  - DMA transfer to memory by half-word to match with ADC conversion data */
//  /*    buffer variable type: half-word.                                      */
//  LL_DMA_ConfigTransfer(DMA1,
//                        LL_DMA_CHANNEL_2,
//                        LL_DMA_DIRECTION_PERIPH_TO_MEMORY |
//                        LL_DMA_MODE_CIRCULAR              |
//                        LL_DMA_PERIPH_NOINCREMENT         |
//                        LL_DMA_MEMORY_INCREMENT           |
//                        LL_DMA_PDATAALIGN_HALFWORD        |
//                        LL_DMA_MDATAALIGN_HALFWORD        |
//                        LL_DMA_PRIORITY_HIGH               );
//
//
//  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_2, LL_DMAMUX_REQ_ADC1);
//  /* Set DMA transfer addresses of source and destination */
//  LL_DMA_ConfigAddresses(DMA1,
//                         LL_DMA_CHANNEL_2,
//                         LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
//                         (uint32_t)&ADCDataDMA,
//                         LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
//
//  /* Set DMA transfer size */
//  LL_DMA_SetDataLength(DMA1,
//                       LL_DMA_CHANNEL_2,
//                       3);
//
//  /* Enable DMA transfer interruption: transfer complete */
//  LL_DMA_EnableIT_TC(DMA1,
//                       LL_DMA_CHANNEL_2);
//
//  /* Enable DMA transfer interruption: transfer error */
//  LL_DMA_EnableIT_TE(DMA1,
//                     LL_DMA_CHANNEL_2);
//
//  /*## Activation of DMA #####################################################*/
//  /* Enable the DMA transfer */
//  LL_DMA_EnableChannel(DMA1,
//                       LL_DMA_CHANNEL_2);
//}
//
//
////void enableADC_DMA(){    // enables channel
////
////	NVIC_SetPriority(DMA1_Channel2_3_IRQn, 3);
////	NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
////
////  LL_DMA_ConfigAddresses(DMA1,
////                         LL_DMA_CHANNEL_2,
////                         LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
////                         (uint32_t)&ADCDataDMA,
////                         LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
////
////  /* Set DMA transfer size */
////#ifdef USE_ADC_INPUT
////  LL_DMA_SetDataLength(DMA1,
////                       LL_DMA_CHANNEL_2,
////                       4);
////#else
////  LL_DMA_SetDataLength(DMA1,
////                       LL_DMA_CHANNEL_2,
////                       3);
////
////#endif
////  /* Enable DMA transfer interruption: transfer complete */
////  LL_DMA_EnableIT_TC(DMA1,
////                     LL_DMA_CHANNEL_2);
////
////  /* Enable DMA transfer interruption: transfer error */
////  LL_DMA_EnableIT_TE(DMA1,
////                     LL_DMA_CHANNEL_2);
////
////  /*## Activation of DMA #####################################################*/
////  /* Enable the DMA transfer */
////  LL_DMA_EnableChannel(DMA1,
////                       LL_DMA_CHANNEL_2);
////}
////
////
////void activateADC(){          // called right after enable regular conversions are started by software and DMA interrupt happens at end of transfer
////
////	  __IO uint32_t wait_loop_index = 0;
////
////
////	  LL_ADC_EnableInternalRegulator(ADC1);
////	    wait_loop_index = (LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES);
////	    while(wait_loop_index != 0)
////	    {
////	      wait_loop_index--;
////	    }
////	    LL_ADC_StartCalibration(ADC1);
////
////	    /* Poll for ADC effectively calibrated */
////
////
////	    while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0)
////	    {
////
////	    }
////
////	    /* Delay between ADC end of calibration and ADC enable.                   */
////	    /* Note: Variable divided by 2 to compensate partially                    */
////	    /*       CPU processing cycles (depends on compilation optimization).     */
////	    wait_loop_index = (LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES);
////	    while(wait_loop_index != 0)
////	    {
////	      wait_loop_index--;
////	    }
////
////	    /* Enable ADC */
////	    LL_ADC_Enable(ADC1);
////
////	    /* Poll for ADC ready to convert */
////
////
////	    while (LL_ADC_IsActiveFlag_ADRDY(ADC1) == 0)
////	    {
////
////	    }
////
////	    /* Note: ADC flag ADRDY is not cleared here to be able to check ADC       */
////	    /*       status afterwards.                                               */
////	    /*       This flag should be cleared at ADC Deactivation, before a new    */
////	    /*       ADC activation, using function "LL_ADC_ClearFlag_ADRDY()".       */
////}
////
//void activateADC(void)
//{
//  __IO uint32_t wait_loop_index = 0U;
//  __IO uint32_t backup_setting_adc_dma_transfer = 0U;
//  #if (USE_TIMEOUT == 1)
//  uint32_t Timeout = 0U; /* Variable used for timeout management */
//  #endif /* USE_TIMEOUT */
//
//  /*## Operation on ADC hierarchical scope: ADC instance #####################*/
//
//  /* Note: Hardware constraint (refer to description of the functions         */
//  /*       below):                                                            */
//  /*       On this STM32 serie, setting of these features is conditioned to   */
//  /*       ADC state:                                                         */
//  /*       ADC must be disabled.                                              */
//  /* Note: In this example, all these checks are not necessary but are        */
//  /*       implemented anyway to show the best practice usages                */
//  /*       corresponding to reference manual procedure.                       */
//  /*       Software can be optimized by removing some of these checks, if     */
//  /*       they are not relevant considering previous settings and actions    */
//  /*       in user application.                                               */
//  if (LL_ADC_IsEnabled(ADC1) == 0)
//  {
//    /* Enable ADC internal voltage regulator */
//    LL_ADC_EnableInternalRegulator(ADC1);
//
//    /* Delay for ADC internal voltage regulator stabilization.                */
//    /* Compute number of CPU cycles to wait for, from delay in us.            */
//    /* Note: Variable divided by 2 to compensate partially                    */
//    /*       CPU processing cycles (depends on compilation optimization).     */
//    /* Note: If system core clock frequency is below 200kHz, wait time        */
//    /*       is only a few CPU processing cycles.                             */
//    wait_loop_index = ((LL_ADC_DELAY_INTERNAL_REGUL_STAB_US * (SystemCoreClock / (100000 * 2))) / 10);
//    while(wait_loop_index != 0)
//    {
//      wait_loop_index--;
//    }
//
//    /* Disable ADC DMA transfer request during calibration */
//    /* Note: Specificity of this STM32 serie: Calibration factor is           */
//    /*       available in data register and also transfered by DMA.           */
//    /*       To not insert ADC calibration factor among ADC conversion data   */
//    /*       in DMA destination address, DMA transfer must be disabled during */
//    /*       calibration.                                                     */
//    backup_setting_adc_dma_transfer = LL_ADC_REG_GetDMATransfer(ADC1);
//    LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_NONE);
//
//    /* Run ADC self calibration */
//    LL_ADC_StartCalibration(ADC1);
//
//    /* Poll for ADC effectively calibrated */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_CALIBRATION_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//
//    /* Restore ADC DMA transfer request after calibration */
//    LL_ADC_REG_SetDMATransfer(ADC1, backup_setting_adc_dma_transfer);
//
//    /* Delay between ADC end of calibration and ADC enable.                   */
//    /* Note: Variable divided by 2 to compensate partially                    */
//    /*       CPU processing cycles (depends on compilation optimization).     */
//    wait_loop_index = (ADC_DELAY_CALIB_ENABLE_CPU_CYCLES >> 1);
//    while(wait_loop_index != 0)
//    {
//      wait_loop_index--;
//    }
//
//    /* Enable ADC */
//    LL_ADC_Enable(ADC1);
//
//    /* Poll for ADC ready to convert */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_ENABLE_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsActiveFlag_ADRDY(ADC1) == 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//
//    /* Note: ADC flag ADRDY is not cleared here to be able to check ADC       */
//    /*       status afterwards.                                               */
//    /*       This flag should be cleared at ADC Deactivation, before a new    */
//    /*       ADC activation, using function "LL_ADC_ClearFlag_ADRDY()".       */
//  }
//
//  /*## Operation on ADC hierarchical scope: ADC group regular ################*/
//  /* Note: No operation on ADC group regular performed here.                  */
//  /*       ADC group regular conversions to be performed after this function  */
//  /*       using function:                                                    */
//  /*       "LL_ADC_REG_StartConversion();"                                    */
//
//  /*## Operation on ADC hierarchical scope: ADC group injected ###############*/
//  /* Note: Feature not available on this STM32 serie */
//
//}
//void ADC_Init(void)
//{
//
//  /* USER CODE BEGIN ADC1_Init 0 */
//
//  /* USER CODE END ADC1_Init 0 */
//
//  LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
//  LL_ADC_InitTypeDef ADC_InitStruct = {0};
//
//  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//  /* Peripheral clock enable */
//  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC);
//
//  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
//  /**ADC1 GPIO Configuration
//  PA4   ------> ADC1_IN4
//  PA6   ------> ADC1_IN6
//  */
//  GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
//  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
//  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
//  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//  GPIO_InitStruct.Pin = LL_GPIO_PIN_6;
//  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
//  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
//  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//  /* ADC1 DMA Init */
//
//  /* ADC1 Init */
//  LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_2, LL_DMAMUX_REQ_ADC1);
//
//  LL_DMA_SetDataTransferDirection(DMA1, LL_DMA_CHANNEL_2, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
//
//  LL_DMA_SetChannelPriorityLevel(DMA1, LL_DMA_CHANNEL_2, LL_DMA_PRIORITY_HIGH);
//
//  LL_DMA_SetMode(DMA1, LL_DMA_CHANNEL_2, LL_DMA_MODE_CIRCULAR);
//
//  LL_DMA_SetPeriphIncMode(DMA1, LL_DMA_CHANNEL_2, LL_DMA_PERIPH_NOINCREMENT);
//
//  LL_DMA_SetMemoryIncMode(DMA1, LL_DMA_CHANNEL_2, LL_DMA_MEMORY_INCREMENT);
//
//  LL_DMA_SetPeriphSize(DMA1, LL_DMA_CHANNEL_2, LL_DMA_PDATAALIGN_HALFWORD);
//
//  LL_DMA_SetMemorySize(DMA1, LL_DMA_CHANNEL_2, LL_DMA_MDATAALIGN_HALFWORD);
//
//  /* USER CODE BEGIN ADC1_Init 1 */
//
//  /* USER CODE END ADC1_Init 1 */
//  /** Configure Regular Channel
//  */
//  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_CHANNEL_TEMPSENSOR);
//  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
//  */
//  ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
//  ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS;
//  ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
//  ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
//  ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_UNLIMITED;
//  ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_PRESERVED;
//  LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
//  LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
//  LL_ADC_SetTriggerFrequencyMode(ADC1, LL_ADC_CLOCK_FREQ_MODE_LOW);
//  LL_ADC_REG_SetSequencerConfigurable(ADC1, LL_ADC_REG_SEQ_CONFIGURABLE);
//  LL_ADC_SetClock(ADC1, LL_ADC_CLOCK_SYNC_PCLK_DIV4);
//  LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_COMMON_1, LL_ADC_SAMPLINGTIME_160CYCLES_5);
//  LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_COMMON_2, LL_ADC_SAMPLINGTIME_160CYCLES_5);
//  LL_ADC_DisableIT_EOC(ADC1);
//  LL_ADC_DisableIT_EOS(ADC1);
//
//  ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
//  ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
//  ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
//  LL_ADC_Init(ADC1, &ADC_InitStruct);
//  /** Configure Regular Channel
//  */
//  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_4);
//  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_4, LL_ADC_SAMPLINGTIME_COMMON_1);
// // LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_6, LL_ADC_SAMPLINGTIME_COMMON_1);
//  /** Configure Regular Channel
//  */
//  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_6);
// LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_6, LL_ADC_SAMPLINGTIME_COMMON_1);
// // LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_6, LL_ADC_SAMPLINGTIME_COMMON_1);
//  /** Configure Regular Channel
//  */
//  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_3, LL_ADC_CHANNEL_TEMPSENSOR);
//  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_TEMPSENSOR, LL_ADC_SAMPLINGTIME_COMMON_1);
//  /* USER CODE BEGIN ADC1_Init 2 */
//
//  /* USER CODE END ADC1_Init 2 */
//
//}
//void Configure_ADC(void)
//{
//  __IO uint32_t wait_loop_index = 0U;
//  #if (USE_TIMEOUT == 1)
//  uint32_t Timeout = 0U; /* Variable used for timeout management */
//  #endif /* USE_TIMEOUT */
//
//  /*## Configuration of GPIO used by ADC channels ############################*/
//
//  /* Note: On this STM32 device, ADC1 channel 4 is mapped on GPIO pin PA.04 */
//
//  /* Enable GPIO Clock */
//  LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
//
//  /* Configure GPIO in analog mode to be used as ADC input */
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_INPUT);
//  LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_INPUT);
//
//  LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_4, LL_GPIO_PULL_UP);
//  LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_6, LL_GPIO_PULL_UP);
//  /*## Configuration of NVIC #################################################*/
//  /* Configure NVIC to enable ADC1 interruptions */
//  NVIC_SetPriority(ADC1_COMP_IRQn, 0); /* ADC IRQ greater priority than DMA IRQ */
//  NVIC_EnableIRQ(ADC1_COMP_IRQn);
//
//  /*## Configuration of ADC ##################################################*/
//
//  /*## Configuration of ADC hierarchical scope: common to several ADC ########*/
//
//  /* Enable ADC clock (core clock) */
//  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC);
//
//  /* Note: Hardware constraint (refer to description of the functions         */
//  /*       below):                                                            */
//  /*       On this STM32 serie, setting of these features is conditioned to   */
//  /*       ADC state:                                                         */
//  /*       All ADC instances of the ADC common group must be disabled.        */
//  /* Note: In this example, all these checks are not necessary but are        */
//  /*       implemented anyway to show the best practice usages                */
//  /*       corresponding to reference manual procedure.                       */
//  /*       Software can be optimized by removing some of these checks, if     */
//  /*       they are not relevant considering previous settings and actions    */
//  /*       in user application.                                               */
//  if(__LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE() == 0)
//  {
//    /* Note: Call of the functions below are commented because they are       */
//    /*       useless in this example:                                         */
//    /*       setting corresponding to default configuration from reset state. */
//
//    /* Set ADC clock (conversion clock) common to several ADC instances */
//    /* Note: On this STM32 serie, ADC common clock asynchonous prescaler      */
//    /*       is applied to each ADC instance if ADC instance clock is         */
//    /*       set to clock source asynchronous                                 */
//    /*       (refer to function "LL_ADC_SetClock()" below).                   */
//    // LL_ADC_SetCommonClock(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_CLOCK_ASYNC_DIV1);
//
//    /* Set ADC measurement path to internal channels */
//	  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_CHANNEL_TEMPSENSOR);
//    /* Delay for ADC temperature sensor stabilization time.                   */
//    /* Compute number of CPU cycles to wait for, from delay in us.            */
//    /* Note: Variable divided by 2 to compensate partially                    */
//    /*       CPU processing cycles (depends on compilation optimization).     */
//    /* Note: If system core clock frequency is below 200kHz, wait time        */
//    /*       is only a few CPU processing cycles.                             */
//    /* Note: This delay is implemented here for the purpose in this example.  */
//    /*       It can be optimized if merged with other delays                  */
//    /*       during ADC activation or if other actions are performed          */
//    /*       in the meantime.                                                 */
//    wait_loop_index = ((LL_ADC_DELAY_TEMPSENSOR_STAB_US * (SystemCoreClock / (100000 * 2))) / 10);
//    while(wait_loop_index != 0)
//    {
//      wait_loop_index--;
//    }
//
//  /*## Configuration of ADC hierarchical scope: multimode ####################*/
//
//    /* Note: Feature not available on this STM32 serie */
//
//  }
//
//
//  /*## Configuration of ADC hierarchical scope: ADC instance #################*/
//
//  /* Note: Hardware constraint (refer to description of the functions         */
//  /*       below):                                                            */
//  /*       On this STM32 serie, setting of these features is conditioned to   */
//  /*       ADC state:                                                         */
//  /*       ADC must be disabled.                                              */
//  if (LL_ADC_IsEnabled(ADC1) == 0)
//  {
//    /* Note: Call of the functions below are commented because they are       */
//    /*       useless in this example:                                         */
//    /*       setting corresponding to default configuration from reset state. */
//
//    /* Set ADC clock (conversion clock) */
//	  LL_ADC_SetCommonClock(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_CLOCK_ASYNC_DIV256);
//
//    /* Set ADC data resolution */
//    // LL_ADC_SetResolution(ADC1, LL_ADC_RESOLUTION_12B);
//
//    /* Set ADC conversion data alignment */
//    // LL_ADC_SetResolution(ADC1, LL_ADC_DATA_ALIGN_RIGHT);
//
//    /* Set ADC low power mode */
//    // LL_ADC_SetLowPowerMode(ADC1, LL_ADC_LP_MODE_NONE);
//
//    /* Set ADC channels sampling time */
//    /* Note: On this STM32 serie, sampling time is common to groups           */
//    /*       of severals channels within ADC instance.                        */
//    /*       Therefore, groups of sampling sampling times are configured      */
//    /*       here under ADC instance scope.                                   */
//    /*       Then, sampling time of channels are configured below             */
//    /*       among group of sampling times available, at channel scope.       */
//    LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_COMMON_1, LL_ADC_SAMPLINGTIME_160CYCLES_5);
//
//  }
//
//  if ((LL_ADC_IsEnabled(ADC1) == 0)||(LL_ADC_REG_IsConversionOngoing(ADC1) == 0))
//  {
//    /* Set ADC group regular trigger source */
//    LL_ADC_REG_SetTriggerSource(ADC1, LL_ADC_REG_TRIG_SOFTWARE);
//
//    /* Set ADC group regular trigger polarity */
//    // LL_ADC_REG_SetTriggerEdge(ADC1, LL_ADC_REG_TRIG_EXT_RISING);
//
//    /* Set ADC group regular continuous mode */
//    LL_ADC_REG_SetContinuousMode(ADC1, LL_ADC_REG_CONV_SINGLE);
//
//    /* Set ADC group regular conversion data transfer */
//    LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_UNLIMITED);
//
//    /* Set ADC group regular overrun behavior */
//    LL_ADC_REG_SetOverrun(ADC1, LL_ADC_REG_OVR_DATA_OVERWRITTEN);
//
//    /* Set ADC group regular sequencer */
//    /* Note: On this STM32 serie, ADC group regular sequencer has             */
//    /*       two settings:                                                    */
//    /*       - Sequencer configured to fully configurable:                    */
//    /*         sequencer length and each rank                                 */
//    /*         affectation to a channel are configurable.                     */
//    /*         Channels selection is limited to channels 0 to 14.             */
//    /*       - Sequencer configured to not fully configurable:                */
//    /*         sequencer length and each rank affectation to a channel        */
//    /*         are fixed by channel HW number.                                */
//    /*         Channels selection is not limited (channels 0 to 18).          */
//    /*       Refer to description of function                                 */
//    /*       "LL_ADC_REG_SetSequencerConfigurable()".                         */
//
//    /* Clear flag ADC channel configuration ready */
//    LL_ADC_ClearFlag_CCRDY(ADC1);
//
//    /* Set ADC group regular sequencer configuration flexibility */
//    LL_ADC_REG_SetSequencerConfigurable(ADC1, LL_ADC_REG_SEQ_CONFIGURABLE);
//
//    /* Poll for ADC channel configuration ready */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_CHANNEL_CONF_RDY_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsActiveFlag_CCRDY(ADC1) == 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//    /* Clear flag ADC channel configuration ready */
//    LL_ADC_ClearFlag_CCRDY(ADC1);
//
//    /* Set ADC group regular sequencer length and scan direction */
//    LL_ADC_REG_SetSequencerLength(ADC1, LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS);
//
//    /* Poll for ADC channel configuration ready */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_CHANNEL_CONF_RDY_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsActiveFlag_CCRDY(ADC1) == 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//    /* Clear flag ADC channel configuration ready */
//    LL_ADC_ClearFlag_CCRDY(ADC1);
//
//    /* Set ADC group regular sequencer discontinuous mode */
//    // LL_ADC_REG_SetSequencerDiscont(ADC1, LL_ADC_REG_SEQ_DISCONT_DISABLE);
//
//    /* Set ADC group regular sequence: channel on the selected sequence rank. */
//    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_3, LL_ADC_CHANNEL_4);
//    /* Poll for ADC channel configuration ready */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_CHANNEL_CONF_RDY_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsActiveFlag_CCRDY(ADC1) == 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//    /* Clear flag ADC channel configuration ready */
//    LL_ADC_ClearFlag_CCRDY(ADC1);
//
//    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_2, LL_ADC_CHANNEL_6);
//    /* Poll for ADC channel configuration ready */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_CHANNEL_CONF_RDY_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsActiveFlag_CCRDY(ADC1) == 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//    /* Clear flag ADC channel configuration ready */
//    LL_ADC_ClearFlag_CCRDY(ADC1);
//
//    LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_TEMPSENSOR);
//    /* Poll for ADC channel configuration ready */
//    #if (USE_TIMEOUT == 1)
//    Timeout = ADC_CHANNEL_CONF_RDY_TIMEOUT_MS;
//    #endif /* USE_TIMEOUT */
//
//    while (LL_ADC_IsActiveFlag_CCRDY(ADC1) == 0)
//    {
//    #if (USE_TIMEOUT == 1)
//      /* Check Systick counter flag to decrement the time-out value */
//      if (LL_SYSTICK_IsActiveCounterFlag())
//      {
//        if(Timeout-- == 0)
//        {
//        /* Time-out occurred. Set LED to blinking mode */
//        LED_Blinking(LED_BLINK_ERROR);
//        }
//      }
//    #endif /* USE_TIMEOUT */
//    }
//    /* Clear flag ADC channel configuration ready */
//    LL_ADC_ClearFlag_CCRDY(ADC1);
//  }
//  /*## Configuration of ADC hierarchical scope: ADC group injected ###########*/
//
//    /* Note: Feature not available on this STM32 serie */
//
//
//    /*## Configuration of ADC hierarchical scope: channels #####################*/
//
//    /* Note: Hardware constraint (refer to description of the functions         */
//    /*       below):                                                            */
//    /*       On this STM32 serie, setting of these features is conditioned to   */
//    /*       ADC state:                                                         */
//    /*       ADC must be disabled or enabled without conversion on going        */
//    /*       on either groups regular or injected.                              */
//    if ((LL_ADC_IsEnabled(ADC1) == 0)               ||
//        (LL_ADC_REG_IsConversionOngoing(ADC1) == 0)   )
//    {
//      /* Set ADC channels sampling time */
//      /* Note: On this STM32 serie, sampling time is common to groups           */
//      /*       of severals channels within ADC instance.                        */
//      /*       See sampling time configured above, at ADC instance scope.       */
//      LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_4, LL_ADC_SAMPLINGTIME_COMMON_1);
//      LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_6, LL_ADC_SAMPLINGTIME_COMMON_1);
//      LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_TEMPSENSOR, LL_ADC_SAMPLINGTIME_COMMON_1);
//
//    }
//
//
//    /*## Configuration of ADC transversal scope: analog watchdog ###############*/
//
//    /* Set ADC analog watchdog channels to be monitored */
//    // LL_ADC_SetAnalogWDMonitChannels(ADC1, LL_ADC_AWD1, LL_ADC_AWD_DISABLE);
//
//    /* Set ADC analog watchdog thresholds */
//    // LL_ADC_ConfigAnalogWDThresholds(ADC1, LL_ADC_AWD1, 0xFFF, 0x000);
//
//
//    /*## Configuration of ADC transversal scope: oversampling ##################*/
//
//    /* Set ADC oversampling scope */
//    // LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
//
//    /* Set ADC oversampling parameters */
//    // LL_ADC_ConfigOverSamplingRatioShift(ADC1, LL_ADC_OVS_RATIO_2, LL_ADC_OVS_SHIFT_NONE);
//
//
//    /*## Configuration of ADC interruptions ####################################*/
//    /* Enable interruption ADC group regular end of sequence conversions */
//   // LL_ADC_EnableIT_EOS(ADC1);
////
////    /* Enable interruption ADC group regular overrun */
//  //   LL_ADC_EnableIT_OVR(ADC1);
//
//    /* Note: in this example, ADC group regular end of conversions              */
//    /*       (number of ADC conversions defined by DMA buffer size)             */
//    /*       are notified by DMA transfer interruptions).                       */
//    /*       ADC interruptions of end of conversion are enabled optionally,     */
//    /*       as demonstration purpose in this example.                          */
//
//}
