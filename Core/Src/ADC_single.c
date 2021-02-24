///*
// * ADC.c
// *
// *  Created on: May 20, 2020
// *      Author: Alka
// */
//#include "ADC.h"
//
//extern uint16_t ADC_raw_temp;
//extern uint16_t ADC_raw_volts;
//extern uint16_t ADC_raw_current;
//extern uint16_t ADC_raw_input;
//
//#define ADC_DELAY_CALIB_ENABLE_CPU_CYCLES  (LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES * 64)
//
//void ADC_Init()
//{
//	__IO uint32_t wait_loop_index = 0U;
//  /* USER CODE BEGIN ADC1_Init 0 */
//
//  /* USER CODE END ADC1_Init 0 */
//
//  LL_ADC_REG_InitTypeDef ADC_REG_InitStruct = {0};
//  LL_ADC_InitTypeDef ADC_InitStruct = {0};
//
////  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//  /* Peripheral clock enable */
//  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_ADC);
//
// // LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
//  /**ADC1 GPIO Configuration
//  PA4   ------> ADC1_IN4
//  */
////  GPIO_InitStruct.Pin = LL_GPIO_PIN_4;
////  GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
////  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
////  LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
//  /* USER CODE BEGIN ADC1_Init 1 */
//
//  /* Configure NVIC to enable ADC1 interruptions */
//  NVIC_SetPriority(ADC1_COMP_IRQn, 0);
//  NVIC_EnableIRQ(ADC1_COMP_IRQn);
//
//  	  LL_ADC_SetCommonPathInternalCh(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_CHANNEL_TEMPSENSOR);
//      wait_loop_index = ((LL_ADC_DELAY_TEMPSENSOR_STAB_US * (SystemCoreClock / (100000 * 2))) / 10);
//      while(wait_loop_index != 0)
//      {
//        wait_loop_index--;
//      }
//
//
//  ADC_REG_InitStruct.TriggerSource = LL_ADC_REG_TRIG_SOFTWARE;
//  ADC_REG_InitStruct.SequencerLength = LL_ADC_REG_SEQ_SCAN_DISABLE;
//  ADC_REG_InitStruct.SequencerDiscont = LL_ADC_REG_SEQ_DISCONT_DISABLE;
//  ADC_REG_InitStruct.ContinuousMode = LL_ADC_REG_CONV_SINGLE;
//  ADC_REG_InitStruct.DMATransfer = LL_ADC_REG_DMA_TRANSFER_NONE;
//  ADC_REG_InitStruct.Overrun = LL_ADC_REG_OVR_DATA_OVERWRITTEN;
//  LL_ADC_REG_Init(ADC1, &ADC_REG_InitStruct);
//  LL_ADC_SetOverSamplingScope(ADC1, LL_ADC_OVS_DISABLE);
//  LL_ADC_SetTriggerFrequencyMode(ADC1, LL_ADC_CLOCK_FREQ_MODE_HIGH);
//  LL_ADC_REG_SetSequencerConfigurable(ADC1, LL_ADC_REG_SEQ_CONFIGURABLE);
//  LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_COMMON_1, LL_ADC_SAMPLINGTIME_39CYCLES_5);
//  LL_ADC_SetSamplingTimeCommonChannels(ADC1, LL_ADC_SAMPLINGTIME_COMMON_2, LL_ADC_SAMPLINGTIME_39CYCLES_5);
//  LL_ADC_DisableIT_EOC(ADC1);
//  LL_ADC_DisableIT_EOS(ADC1);
//  LL_ADC_SetCommonClock(__LL_ADC_COMMON_INSTANCE(ADC1), LL_ADC_CLOCK_ASYNC_DIV8);
//  ADC_InitStruct.Resolution = LL_ADC_RESOLUTION_12B;
//  ADC_InitStruct.DataAlignment = LL_ADC_DATA_ALIGN_RIGHT;
//  ADC_InitStruct.LowPowerMode = LL_ADC_LP_MODE_NONE;
//  LL_ADC_Init(ADC1, &ADC_InitStruct);
//  /** Configure Regular Channel
//  */
//  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_TEMPSENSOR);
//  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_TEMPSENSOR, LL_ADC_SAMPLINGTIME_COMMON_1);
//  /** Configure Regular Channel
//  */
////  LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_TEMPSENSOR);
////  LL_ADC_SetChannelSamplingTime(ADC1, LL_ADC_CHANNEL_TEMPSENSOR, LL_ADC_SAMPLINGTIME_COMMON_1);
//  /* USER CODE BEGIN ADC1_Init 2 */
//
//  /* Configuration of ADC interruptions */
//  /* Enable interruption ADC group regular overrun */
//  LL_ADC_EnableIT_OVR(ADC1);
//  /* USER CODE END ADC1_Init 2 */
//
//}
//
//
//
//
//
//
//void Activate_ADC(void)
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
//
//
//    while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0)
//    {
//
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
//
//    }
//
//  }
//}
