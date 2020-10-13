
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "targets.h"
#include "dshot.h"
#include "phaseouts.h"
#include "eeprom.h"
#include "sounds.h"
#include "ADC.h"
#include "WS2812.h"
#include "peripherals.h"
#include "functions.h"
#include "comparator.h"
#include "IO.h"

int Erik_count = 0;


uint8_t version_major = 1;
uint8_t version_minor = 57;

uint8_t device_name[12] = FIRMWARE_NAME ;

#define APPLICATION_ADDRESS 0x08001000
#define EEPROM_START_ADD  (uint32_t)0x0801F800


//#define TWO_COMP_TEST

uint16_t DEAD_TIME = 45;

int checkcount = 0;

//typedef enum
//{
//  GPIO_PIN_RESET = 0U,
//  GPIO_PIN_SET
//}GPIO_PinState;

char brake_on_stop = 0;
char dir_reversed = 0;
char bi_direction = 0;
char use_sin_start = 0;
char low_rpm_throttle_limit = 1;
uint16_t motor_kv = 2000;
char motor_poles = 14;
char VARIABLE_PWM = 0;
char lowkv = 0;
char comp_pwm = 1;
int min_startup_duty = 120;
int sin_mode_min_s_d = 100;
char bemf_timeout = 10;
char crawler_mode = 0;
char advance_level = 2;                // 7.5 degree increments 0 , 7.5, 15, 22.5)
char stuck_rotor_protection = 1;
char startup_boost = 25;
uint16_t minimum_duty_cycle = 64;
uint16_t TIMER1_MAX_ARR = 1499;

char low_kv_filter_level = 20;

char stall_protection = 0;
int duty_cycle_maximum = 1499;
int low_rpm_level  = 20;        // thousand erpm
int high_rpm_level = 70;      //
int throttle_max_at_low_rpm  = 500;
int throttle_max_at_high_rpm = 1499;

uint16_t commutation_intervals[6] = {0};
uint32_t average_interval = 0;
uint32_t last_average_interval;
int e_com_time;
char desync_check = 0;
uint16_t ADC_smoothed_input = 0;
uint8_t degrees_celsius;
uint16_t ADC_raw_temp;
uint16_t ADC_raw_volts;
uint16_t ADC_raw_current;
uint16_t ADC_raw_input;
int adc_counter = 0;
char send_telemetry = 0;
char telemetry_done = 0;
char prop_brake_active = 0;

uint8_t eepromBuffer[48] ={0};
uint32_t gcr[30] =  {0,0,0,0,0,0,0,0,0,0,0,64,0,0,0,0,64,0,0,0,0,64,0,0,0,64,64,0,64,0};
uint8_t gcr_size;
uint16_t process_time = 0;

char dshot_telemetry = 0;
char output = 0;
int dshot_frametime = 0;

uint16_t phase_a_interval = 0;
uint16_t phase_b_interval = 0;
uint16_t phase_c_interval = 0;
uint32_t current_EXTI_LINE;

int dshot_goodcounts = 0;
int dshot_badcounts = 0;
uint8_t last_dshot_command = 0;
char old_routine = 0;
int adjusted_input;

#define TEMP30_CAL_VALUE            ((uint16_t*)((uint32_t)0x1FFFF7B8))
#define TEMP110_CAL_VALUE           ((uint16_t*)((uint32_t)0x1FFFF7C2))

int temp110cal;
int temp30cal;
int smoothedinput = 0;
int voltageraw;

const int numReadings = 30;     // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;
int readings[30];
int tempraw = 0;
int temp_degrees = 0;

int bemf_timout_happened = 0;
int timeout_count = 0;
int bemf_timeout_threshold = 10;

int changeover_step = 5;
int filter_level = 5;
int running = 0;
int advance = 0;
int advancedivisor = 3;
int START_ARR=800;
char rising = 1;
int count = 0;

const int pwmSin[] = {180,183,186,189,193,196,199,202,
		205,208,211,214,217,220,224,227,
		230,233,236,239,242,245,247,250,
		253,256,259,262,265,267,270,273,
		275,278,281,283,286,288,291,293,
		296,298,300,303,305,307,309,312,
		314,316,318,320,322,324,326,327,
		329,331,333,334,336,337,339,340,
		342,343,344,346,347,348,349,350,
		351,352,353,354,355,355,356,357,
		357,358,358,359,359,359,360,360,
		360,360,360,360,360,360,360,359,
		359,359,358,358,357,357,356,355,
		355,354,353,352,351,350,349,348,
		347,346,344,343,342,340,339,337,
		336,334,333,331,329,327,326,324,
		322,320,318,316,314,312,309,307,
		305,303,300,298,296,293,291,288,
		286,283,281,278,275,273,270,267,
		265,262,259,256,253,250,247,245,
		242,239,236,233,230,227,224,220,
		217,214,211,208,205,202,199,196,
		193,189,186,183,180,177,174,171,
		167,164,161,158,155,152,149,146,
		143,140,136,133,130,127,124,121,
		118,115,113,110,107,104,101,98,
		95,93,90,87,85,82,79,77,
		74,72,69,67,64,62,60,57,
		55,53,51,48,46,44,42,40,
		38,36,34,33,31,29,27,26,
		24,23,21,20,18,17,16,14,
		13,12,11,10,9,8,7,6,
		5,5,4,3,3,2,2,1,
		1,1,0,0,0,0,0,0,
		0,0,0,1,1,1,2,2,
		3,3,4,5,5,6,7,8,
		9,10,11,12,13,14,16,17,
		18,20,21,23,24,26,27,29,
		31,33,34,36,38,40,42,44,
		46,48,51,53,55,57,60,62,
		64,67,69,72,74,77,79,82,
		85,87,90,93,95,98,101,104,
		107,110,113,115,118,121,124,127,
		130,133,136,140,143,146,149,152,
		155,158,161,164,167,171,174,177};


int sin_divider = 2;
int phase_A_position;
int phase_B_position;
int phase_C_position;
int step_delay  = 100;
char stepper_sine = 0;
int forward = 1;
int gate_drive_offset = 60;

int stuckcounter = 0;
int k_erpm;

uint16_t adjusted_duty_cycle;
uint16_t tim1_arr = 1499;
int bad_count = 0;
int dshotcommand;
int armed_count_threshold = 1000;

char armed = 0;
int zero_input_count = 0;

int input = 0;
int newinput =0;
char inputSet = 0;
char dshot = 0;
char proshot = 0;
char multishot = 0;
char oneshot42 = 0;
char oneshot125 = 0;
char servoPwm = 0;
int zero_crosses;

int zcfound = 0;

int bemfcounter;
int min_bemf_counts_up = 7;
int min_bemf_counts_down = 7;
int adc_timer = 600;
int lastzctime;
uint16_t thiszctime;
int phase = 1;
int duty_cycle = 0;
char step = 1;
uint16_t commutation_interval = 12500;
int pwm = 1;
int floating =2;
int lowside = 3;
int sensorless = 1;
int waitTime = 0;
int signaltimeout = 0;

uint8_t ubAnalogWatchdogStatus = RESET;


void loadEEpromSettings(){
	   read_flash_bin( eepromBuffer , EEPROM_START_ADD , 48);

	   if(eepromBuffer[17] == 0x01){
	 	  dir_reversed =  1;
	   }else{
		   dir_reversed = 0;
	   }
	   if(eepromBuffer[18] == 0x01){
	 	  bi_direction = 1;
	   }else{
		  bi_direction = 0;
	   }


	   if(eepromBuffer[19] == 0x01){
	 	  use_sin_start = 1;
	 	 min_startup_duty = sin_mode_min_s_d;
	   }
	   if(eepromBuffer[20] == 0x01){
	  	  comp_pwm = 1;
	    }else{
	    	comp_pwm = 0;
	    }
	   if(eepromBuffer[21] == 0x01){
		   VARIABLE_PWM = 1;
	    }else{
	    	VARIABLE_PWM = 0;
	    }

	   if(eepromBuffer[22] == 0x01){
		   stuck_rotor_protection = 1;
	    }else{
	    	stuck_rotor_protection = 0;
	    }

	   if(eepromBuffer[23] < 4){
		   advance_level = eepromBuffer[23];
	    }else{
	    	advance_level = 2;  // * 7.5 increments
	    }

	   if(eepromBuffer[24] < 49 && eepromBuffer[24] > 23){
		   TIMER1_MAX_ARR = map (eepromBuffer[24], 24, 48, 1499 ,999);
		   TIM1->ARR = TIMER1_MAX_ARR;
	    }else{
	    	tim1_arr = 1499;
	    	TIM1->ARR = tim1_arr;
	    }

	   if(eepromBuffer[25] < 151 && eepromBuffer[25] > 49){
		   min_startup_duty = eepromBuffer[25]/ 2 + 10 + startup_boost;
		   minimum_duty_cycle = eepromBuffer[25]/ 2 + 10;
	    }else{
	    	min_startup_duty = 150;
	    	minimum_duty_cycle = (min_startup_duty / 2) + 10;
	    }

       motor_kv = (eepromBuffer[26] * 40) + 20;
       motor_poles = eepromBuffer[27];


	   low_rpm_level  = motor_kv / 100;
	   high_rpm_level = 20 + (motor_kv / 50);


	if(!comp_pwm){
		bi_direction = 0;
	}

}

void saveEEpromSettings(){


   if(dir_reversed == 1){
	   eepromBuffer[17] = 0x01;
   }else{
	   eepromBuffer[17] = 0x00;
   }
   if(bi_direction == 1){
	   eepromBuffer[18] = 0x01;
      }else{
    	  eepromBuffer[18] = 0x00;
      }
   if(use_sin_start == 1){
	   eepromBuffer[19] = 0x01;
      }else{
    	  eepromBuffer[19] = 0x00;
      }


   if(comp_pwm == 1){
	   eepromBuffer[20] = 0x01;
      }else{
    	  eepromBuffer[20] = 0x00;
      }
   if(VARIABLE_PWM == 1){
	   eepromBuffer[21] = 0x01;
      }else{
    	  eepromBuffer[21] = 0x00;
      }
   if(stuck_rotor_protection == 1){
	   eepromBuffer[22] = 0x01;
      }else{
    	  eepromBuffer[22] = 0x00;
      }


   eepromBuffer[23] = advance_level;

   save_flash_nolib(eepromBuffer, 48, EEPROM_START_ADD);
}


void initAfterJump(){

	SCB->VTOR = 0x08001000;
    do {
       volatile uint32_t tmpreg;
       ((((RCC_TypeDef *) ((((uint32_t)0x40000000U) + 0x00020000) + 0x00001000))->AHBENR) |= ((0x1U << (0U))));
           /* Delay after an RCC peripheral clock enabling */
      tmpreg = ((((RCC_TypeDef *) ((((uint32_t)0x40000000U) + 0x00020000) + 0x00001000))->AHBENR) & ((0x1U << (0U))));
         ((void)(tmpreg));
          } while(0U);
  //	  /* Remap SRAM at 0x00000000 */
    do {((SYSCFG_TypeDef *) (((uint32_t)0x40000000U) + 0x00010000))->CFGR1 &= ~((0x3U << (0U)));
        ((SYSCFG_TypeDef *) (((uint32_t)0x40000000U) + 0x00010000))->CFGR1 |= ((0x1U << (0U)) | (0x2U << (0U)));
      }while(0);

    if (SysTick_Config(SystemCoreClock / 1000))
     {
       /* Capture error */
       while (1)
       {
       }
     }
    __enable_irq();
}



void getBemfState(){

    if (rising){
    	if (LL_COMP_ReadOutputLevel(COMP2) == LL_COMP_OUTPUT_LEVEL_LOW){
    		bemfcounter++;
    		bad_count = 0;
    		}else{

    			bad_count++;
    			if(bad_count > 2){
    				bemfcounter = 0;
    			}
    		}
    }else{
    	if(LL_COMP_ReadOutputLevel(COMP2) == LL_COMP_OUTPUT_LEVEL_HIGH){
    		bemfcounter++;
    		bad_count = 0;
    	}else{

    		bad_count++;
    	    			if(bad_count > 2){
    	    				bemfcounter = 0;
    	    			}
    	}
    }
}



void commutate(){
	commutation_intervals[step-1] = commutation_interval;
	e_com_time = (commutation_intervals[0] + commutation_intervals[1] + commutation_intervals[2] + commutation_intervals[3] + commutation_intervals[4] +commutation_intervals[5]) >> 1;  // COMMUTATION INTERVAL IS 0.5US INCREMENTS

//	TIM14->CNT = 0;
	if (forward == 1){
		step++;
		if (step > 6) {
			step = 1;
			desync_check = 1;
		}
		rising = step % 2;
	}else{
		step--;
		if (step < 1) {
			step = 6;
			desync_check = 1;
		}
		rising = !(step % 2);
	}
	comStep(step);
	changeCompInput();

if(commutation_interval > 4000 && crawler_mode){
	old_routine = 1;
}
	bemfcounter = 0;
	zcfound = 0;
	timeout_count = 0;
}




void tenKhzRoutine(){
	TIM1->ARR = tim1_arr;

	TIM1->CCR1 = adjusted_duty_cycle;
	TIM1->CCR2 = adjusted_duty_cycle;
	TIM1->CCR3 = adjusted_duty_cycle;

average_interval = e_com_time / 3;
if(desync_check){
//	if(step==6){       // desync check
		if(getAbsDif(average_interval,last_average_interval) > average_interval >> 1 && (zero_crosses > 40)){ //throttle resitricted before zc 40.
			zero_crosses = 6;
running = 0;
old_routine = 1;
		}
		last_average_interval = average_interval;
		desync_check = 0;
		//getSmoothedInput();
	}
	if(send_telemetry){
//	  makeTelemPackage(degrees_celsius,
//	  		              ADC_raw_volts,
//	  					  1250,
//	  					  200,
//	  					  k_erpm);
//	  send_telem_DMA();
	}

//	if(commutation_interval > 400){
//		   NVIC_SetPriority(IC_DMA_IRQ_NAME, 0);
//		   NVIC_SetPriority(ADC1_COMP_IRQn, 1);
//	}else{
//		NVIC_SetPriority(IC_DMA_IRQ_NAME, 1);
//		NVIC_SetPriority(ADC1_COMP_IRQn, 0);
//	}

		signaltimeout++;
		if(signaltimeout > 2500) { // quarter second timeout when armed;
			if(armed){
				allOff();
				armed = 0;
				input = 0;
				inputSet = 0;
				zero_input_count = 0;
			//	smallestnumber = 20000;
				TIM1->CCR1 = 0;
			    TIM1->CCR2 = 0;
				TIM1->CCR3 = 0;
				IC_TIMER_REGISTER->PSC = 0;
				IC_TIMER_REGISTER->CNT = 0;
				for(int i = 0; i < 64; i++){
					dma_buffer[i] = 0;
				}
				NVIC_SystemReset();
			}

		if (signaltimeout > 15000){     // 1.5 second
			allOff();
			armed = 0;
			input = 0;
			inputSet = 0;
			zero_input_count = 0;
		//	smallestnumber = 20000;
			TIM1->CCR1 = 0;
		    TIM1->CCR2 = 0;
			TIM1->CCR3 = 0;
			IC_TIMER_REGISTER->PSC = 0;
			IC_TIMER_REGISTER->CNT = 0;
			for(int i = 0; i < 64; i++){
				dma_buffer[i] = 0;
			}
			NVIC_SystemReset();
		}
			}
}





void interruptRoutine(){

/// todo move all desync error checking to main loop, doesn't need to be done every interrupt.

if ((TIM2->CNT < 125) && (duty_cycle < 600) && (zero_crosses < 500)){    //should be impossible, desync?exit anyway

	return;
}
thiszctime = TIM2->CNT;

	if (commutation_interval > 50){
	//	delayMicros(filter_delay);
stuckcounter++;             // stuck at 100 interrupts before the main loop happens again.
if (stuckcounter > 100){
	maskPhaseInterrupts();
	zero_crosses = 0;
	return;
}
			if (rising){

				for (int i = 0; i < filter_level; i++){
					if(LL_COMP_ReadOutputLevel(COMP2) == LL_COMP_OUTPUT_LEVEL_HIGH){
											return;
										}
				}
			}else{
				for (int i = 0; i < filter_level; i++){
					if(LL_COMP_ReadOutputLevel(COMP2) == LL_COMP_OUTPUT_LEVEL_LOW){
											return;
										}
				}
			}
	}
							maskPhaseInterrupts();
							LL_EXTI_ClearRisingFlag_0_31(LL_EXTI_LINE_18);
							LL_EXTI_ClearFallingFlag_0_31(LL_EXTI_LINE_18);
							Erik_count++;
			TIM2->CNT = 0;
			TIM14->CNT = 0;
			TIM14->ARR = waitTime;
			TIM14->SR = 0x00;
			TIM14->DIER |= (0x1UL << (0U));             // enable TIM14 interrupt
}

void advanceincrement(){

if (!forward){
	phase_A_position ++;
    if (phase_A_position > 359){
	   phase_A_position = 0 ;
    }

	    phase_B_position ++;
	     if (phase_B_position > 359){
		phase_B_position = 0 ;
	}
	    phase_C_position ++;
	     if (phase_C_position > 359){
		phase_C_position = 0 ;
	}
}else{
	phase_A_position --;
	    if (phase_A_position < 0){
		   phase_A_position = 359 ;
	    }

		    phase_B_position --;
		     if (phase_B_position < 0){
			phase_B_position = 359;
		}
		    phase_C_position --;
		     if (phase_C_position < 0){
			phase_C_position = 359 ;
		}
}


    TIM1->CCR1 = (pwmSin[phase_A_position]/2)+gate_drive_offset;
    TIM1->CCR2 = (pwmSin[phase_B_position]/2)+gate_drive_offset;
    TIM1->CCR3 = (pwmSin[phase_C_position]/2)+gate_drive_offset;

}


void PeriodElapsedCallback(){
			count++;
			TIM14->DIER &= ~((0x1UL << (0U)));             // disable interrupt
			commutate();
			commutation_interval = ((commutation_interval) + thiszctime)>>1;
            advance = (commutation_interval>>3) * advance_level;   // 60 divde 8 7.5 degree increments
			waitTime = (commutation_interval >>1)  - advance;
			//	blanktime = commutation_interval / 8; // no blanktime /demag , if the motor is accelerating fast the next zc can happen right after commutation
#ifdef TWO_COMP_TEST
			if (step == 2 || step == 5) {
				TIM14->ARR = commutation_interval- advance;
				TIM14->SR = 0x00;
				TIM14->DIER |= (0x1UL << (0U));             // enable TIM14 interrupt
			}else{
				if(!old_routine){
							EXTI->IMR1 |= (1 << 18);     // enable comp interrupt
							}
			}
#else

			if(!old_routine){
									EXTI->IMR1 |= (1 << 18);     // enable comp interrupt
									}
#endif
			zero_crosses++;
}

void startMotor() {
	if (running == 0){
	commutate();
	commutation_interval = 10000;
	TIM2->CNT = 5000;
	running = 1;
	}
	EXTI->IMR1 |= (1 << 18);
	sensorless = 1;
}

void zcfoundroutine(){
	thiszctime = TIM2->CNT;
	TIM2->CNT = 0;
	commutation_interval = (thiszctime + (3*commutation_interval)) / 4;
	advance = commutation_interval / advancedivisor;
	waitTime = commutation_interval /2  - advance;

	while (TIM2->CNT - thiszctime < waitTime - advance){

	}
	commutate();
    bemfcounter = 0;
    bad_count = 0;
    zcfound = 0;
    zero_crosses++;
    if(crawler_mode){
    	 if (zero_crosses >= 100 && adjusted_input > 400) {
    	    	old_routine = 0;
    	    	EXTI->IMR1 |= (1 << 18);          // enable interrupt
    	 }
    }else{
    if (zero_crosses >= 20) {
    	old_routine = 0;
    	EXTI->IMR1 |= (1 << 18);          // enable interrupt
    }
    }

}



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	initAfterJump();
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* System interrupt init*/

  LL_SYSCFG_EnablePinRemap(LL_SYSCFG_PIN_RMP_PA11);
  LL_SYSCFG_EnablePinRemap(LL_SYSCFG_PIN_RMP_PA12);

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
//  MX_ADC1_Init();
  MX_COMP2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM14_Init();
  MX_TIM17_Init();
  MX_TIM6_Init();
  MX_IWDG_Init();
  /* USER CODE BEGIN 2 */

  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH1N);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH2N);
  LL_TIM_CC_EnableChannel(TIM1, LL_TIM_CHANNEL_CH3N);

  /* Enable counter */
  LL_TIM_EnableCounter(TIM1);
  LL_TIM_EnableAllOutputs(TIM1);
  /* Force update generation */
  LL_TIM_GenerateEvent_UPDATE(TIM1);

  LL_TIM_EnableCounter(TIM6);               // commutation_timer priority 0
  LL_TIM_GenerateEvent_UPDATE(TIM6);
  LL_TIM_EnableIT_UPDATE(TIM6);

  LL_TIM_EnableCounter(TIM14);               // commutation_timer priority 0
  LL_TIM_GenerateEvent_UPDATE(TIM14);
  TIM14->SR = 0x00;
  LL_TIM_EnableIT_UPDATE(TIM14);

  TIM14->DIER &= ~((0x1UL << (0U)));         // disable for now.

  LL_TIM_EnableCounter(TIM17);                 // delay timer
  LL_TIM_GenerateEvent_UPDATE(TIM17);

  LL_TIM_EnableCounter(TIM2);                 // zero cross timing timer
  LL_TIM_GenerateEvent_UPDATE(TIM2);

  __IO uint32_t wait_loop_index = 0;

  /* Enable comparator */
  LL_COMP_Enable(COMP2);
  wait_loop_index = ((LL_COMP_DELAY_STARTUP_US * (SystemCoreClock / (100000 * 2))) / 10);
  while(wait_loop_index != 0)
  {
    wait_loop_index--;
  }
playStartupTune();
  receiveDshotDma();
  maskPhaseInterrupts();
  MX_IWDG_Init();
   LL_IWDG_ReloadCounter(IWDG);
//   ADC_Init();
//
//   activateADC();
//   enableADC_DMA();
   Configure_DMA();
   Configure_ADC();
    activateADC();

    WS2812_Init();

    loadEEpromSettings();

   if(version_major != eepromBuffer[3]  && version_minor > eepromBuffer[4]){
 	  eepromBuffer[3] = version_major;
 	  eepromBuffer[4] = version_minor;
 	  for(int i = 0; i < 12 ; i ++){
 		  eepromBuffer[5+i] = device_name[i];
 	  }
 	  saveEEpromSettings();
   }

 	if (dir_reversed == 1){
 			forward = 0;
 		}else{
 			forward = 1;
 		}
 	tim1_arr = TIMER1_MAX_ARR;
 	send_LED_RGB(30, 0, 20);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


	  adc_counter++;
	 	  if(adc_counter>500){   // for testing adc and telemetry
	 		  degrees_celsius = __LL_ADC_CALC_TEMPERATURE(3000,  ADC_raw_temp, LL_ADC_RESOLUTION_12B);
	 		// degrees_celsiuss = __LL_ADC_CALC_TEMPERATURE(VDDA_APPLI, ADC_raw_temp, LL_ADC_RESOLUTION_12B);
	 		  LL_ADC_REG_StartConversion(ADC1);

	 		  adc_counter = 0;
	 #ifdef USE_ADC_INPUT
	 		  if(ADC_raw_input < 10){
	 			  zero_input_count++;
	 		  }else{
	 			  zero_input_count=0;
	 		  }
	 #endif
	 	  }
	 #ifdef USE_ADC_INPUT

	 signaltimeout = 0;
	 ADC_smoothed_input = (((10*ADC_smoothed_input) + ADC_raw_input)/11);
	 newinput = ADC_smoothed_input / 2;
	 if(newinput > 2000){
	 	newinput = 2000;
	 }
	 #endif
	 	  stuckcounter = 0;
	 	  LL_IWDG_ReloadCounter(IWDG);
	   		  if (zero_input_count > armed_count_threshold && !armed){
	   			  armed = 1;
	 #ifdef tmotor55
	   			GPIOB->BRR = LL_GPIO_PIN_3;    // turn off red
	   			GPIOA->BSRR = LL_GPIO_PIN_15;   // turn on green
	 #endif
	   			  playInputTune();
	   		  }
	   		  if (bi_direction == 1 && proshot == 0 && dshot == 0){
	 				if (newinput > 1100) {
	 					if (forward == dir_reversed) {
	 				adjusted_input = 0;

	 				forward = 1 - dir_reversed;
	 				}
	 				adjusted_input = (newinput - 1099) * 3;

	 				}
	 				if (newinput < 760) {
	 				if (forward == (1 - dir_reversed)) {

	 				adjusted_input = 0;
	 				forward = dir_reversed;
	 					}
	 			adjusted_input = ((760 - newinput) * 3);
	 								}
	 									if (newinput >= 760 && newinput < 1100) {
	 										adjusted_input = 0;
	 									}

	  		}else if ((proshot || dshot) && bi_direction) {
	   					if (newinput > 1047) {

	   						if (forward == dir_reversed) {
	   							if(commutation_interval > 1500 || stepper_sine){
	   							forward = 1 - dir_reversed;
	   							zero_crosses = 0;
	   							old_routine = 1;
	   							}else{
	   								newinput = 0;

	   							}
	   						}
	   						adjusted_input = (newinput - 1048) * 2 + 47;

	   					}
	   					if (newinput <= 1047 && newinput > 0) {
	   					//	startcount++;

	   						if (forward == (1 - dir_reversed)) {
	   							if(commutation_interval > 1500 || stepper_sine){
	   							zero_crosses = 0;
	   							old_routine = 1;
	   							forward = dir_reversed;
	   							}else{
	   								newinput = 0;

	   							}
	  						}
	   						adjusted_input = (newinput - 47) * 2 + 47;
	   					}
	   					if ( newinput < 48) {
	   						adjusted_input = 0;
	   					}


	   	  				}else{
	   		 adjusted_input = newinput;
	   	 }
	 	 	 if ((zero_crosses > 1000) || (adjusted_input == 0)){
	  	 		bemf_timout_happened = 0;
	  	 	 }
	 	 	 if(zero_crosses > 100 && adjusted_input < 200){
	 	 		bemf_timout_happened = 0;
	 	 	 }
	 	 	 if(use_sin_start && adjusted_input < 160){
	 	 		bemf_timout_happened = 0;
	 	 	 }

	  	 	 if(crawler_mode){
	  	 		if (adjusted_input < 400){
	  	 			bemf_timout_happened = 0;
	  	 		}
	  	 	 }else{
	  	 		if (adjusted_input < 150){              // startup duty cycle should be low enough to not burn motor
	  	 			bemf_timeout = 100;
	  	 	 	 }else{
	  	 	 		bemf_timeout = 10;
	  	 	 	 }
	  	 	 }
	 	  if(bemf_timout_happened > bemf_timeout * ( 1 + (crawler_mode*100))&& stuck_rotor_protection){
	 	 		 allOff();
	 	 		 maskPhaseInterrupts();
	 	 		 input = 0;
	 	 		bemf_timout_happened = 102;

	 	 	  }else{
	 	 		 input=adjusted_input;

	 	 	  }

	 		  if ( stepper_sine == 0){

	 	  if (input >= 47 +(90*stepper_sine) && armed){
	 		  if (running == 0){
	 			  if(!old_routine){
	 			 startMotor();
	 			  }
	 //			 send_LED_RGB(0, 0, 20);
	 			  running = 1;
	 #ifdef tmotor55
	 			  GPIOB->BRR = LL_GPIO_PIN_3;  // off red
	 			  GPIOA->BRR = LL_GPIO_PIN_15; // off green
	 			  GPIOB->BSRR = LL_GPIO_PIN_5;  // on blue
	 #endif

	 		  }
	 	 //	 running = 1;
	 	 	 duty_cycle = map(input, 47, 2047, minimum_duty_cycle, 1499) - (40*use_sin_start);
	 	  }
	 	  if (input < 47 + (90*stepper_sine)){

	  		  if(!comp_pwm){
	  			duty_cycle = 0;
	  			if(!running){
	  				old_routine = 1;
	  				zero_crosses = 0;
	  			}
	  		  }else{
			  if (!running){

			  if(brake_on_stop){
				  fullBrake();

			  }else{
				  allOff();
			  }
				  old_routine = 1;
			  }


		 //	 running = 0;
		 	 duty_cycle = 0;
		 	  phase_A_position = 0;
		 	  phase_B_position = 119;
		 	  phase_C_position = 239;
		 	  if(use_sin_start == 1){
		 	 stepper_sine = 1;

		 	  }
		 	zero_crosses = 0;
		 //	fullBrake();
	 		  }
	 		  }

	    if (zero_crosses < 40){
	 	   if (duty_cycle < min_startup_duty){
	 	   duty_cycle = min_startup_duty;

	 	   }
	 	   if (duty_cycle > 400){
	 		   duty_cycle = 400;
	 	   }
	    }

	   if (duty_cycle < 160 && running){
	   	 if(duty_cycle < minimum_duty_cycle){
	 	  duty_cycle = minimum_duty_cycle;
	   	 }
	   	 if(stall_protection && zero_crosses > 50){  // this boosts throttle as the rpm gets lower, for crawlers and rc cars only, do not use for multirotors.
	 	 if(commutation_interval > 7000){
	 		    	 duty_cycle = duty_cycle + map(commutation_interval, 7000, 9000, 1, 80);
	 		     }
	   	 }
	    }

	    k_erpm = ((1000000/ e_com_time) * 60) / 1000; // ecom time is time for one electrical revolution in microseconds
	    if(low_rpm_throttle_limit){     // some hardware doesn't need this, its on by default to keep hardware / motors protected but can slow down the response in the very low end a little.

	   duty_cycle_maximum = map(k_erpm, low_rpm_level, high_rpm_level, throttle_max_at_low_rpm, throttle_max_at_high_rpm);   // for more performance lower the high_rpm_level, set to a consvervative number in source.
	    }

	 	 if (duty_cycle > duty_cycle_maximum){
	 		 duty_cycle = duty_cycle_maximum;
	 	 }


			if (armed && running && (input > 47)){
					if(VARIABLE_PWM){
					tim1_arr = map(commutation_interval, 96, 200, 1000, TIMER1_MAX_ARR);
			        advance_level = eepromBuffer[23];
					}
				    adjusted_duty_cycle = (duty_cycle * tim1_arr)/1499;


	 	  }else{           // not armed

	 		 adjusted_duty_cycle = 0;
	 	  }

	 if (zero_crosses < 150 || commutation_interval > 900 || duty_cycle < 400) {
	 		advancedivisor = 4;
	 		filter_level = 16;

	 	} else {
	 		advancedivisor = 4;         // 15 degree advance
	 		filter_level = 6;


	 	}
	 	if (duty_cycle > 900 && zero_crosses > 100 && commutation_interval < 900){
	 		filter_level = 3;

	 	}

	 	if (commutation_interval < 90 && duty_cycle > 800){
	 		filter_level = 2;

	 	}

	 if(lowkv){

	 	filter_level = low_kv_filter_level;
	 }

	 /**************** old routine*********************/
	 if (old_routine && running){
		 maskPhaseInterrupts();
#ifdef TWO_COMP_TEST
		 if(step == 2 || step == 5){
			 if(TIM2->CNT > commutation_interval>>1){
				 zcfoundroutine();
			 }
		 }else{
	 	//old_routine = 1;
#endif
	 	 		 getBemfState();                                      // uncomment to make run !!!!!!!!!!!!!!!
	 	 	  if (!zcfound){
	 	 		  if (rising){
	 	 		 if (bemfcounter > min_bemf_counts_up){

	 	 			 zcfound = 1;
	 	 		//	 bemfcounter = 0;
	 	 			 zcfoundroutine();
	 	 		//	 break;

	 	 		}
	 	 		  }else{
	 	 			  if (bemfcounter > min_bemf_counts_down){

	 	 			  			 zcfound = 1;
	 	 			//  			 bemfcounter = 0;
	 	 			  			 zcfoundroutine();
	 	 			  //			 break;

	 	 			  		}
	 	 		  }
	 	 	  }
#ifdef TWO_COMP_TEST
		 }
#endif
	 }
	 	 	  if (TIM2->CNT > 40000 && running == 1){
	 bemf_timout_happened ++;
	 	 		  zcfoundroutine();
	 	 		  maskPhaseInterrupts();
	 //	 		send_LED_RGB(30, 0, 0);
	 	 		  old_routine = 1;
	 	 		   running = 0;
	 	 		   zero_crosses = 0;
	 	 		  timeout_count = 0;

	 	 	//	  }
	 	 	  }
	 	 	  }else{            // stepper sine

	 if(input > 60 && armed){
	 	 		  if (input > 60 && input < 140){// sine wave stepper
	 	 			 maskPhaseInterrupts();
	 	 			 allpwm();
	 	 		 advanceincrement();

	 		 	//  count = 0;
	              step_delay = map (input, 60, 140, 500, 100);
	 	 		 delayMicros(step_delay);

	 	 		  }else{
	 	 			 advanceincrement();
	 	 			  if(input > 200){
	 	 				 phase_A_position = 0;
	 	 				 step_delay = 80;
	 	 			  }

	 	 			 delayMicros(step_delay);
	 	 			  if (phase_A_position == 0){
	 	 			  stepper_sine = 0;
	 	 			  running = 1;
	 	 			 zero_crosses = 0;
	 	 			  step = changeover_step;                    // rising bemf on a same as position 0.
	 	 			LL_TIM_GenerateEvent_UPDATE(TIM1);
	 	 			  zcfoundroutine();
	 	 			  }
	 	 		  }
	 }else{
	 	TIM1->CCR1 = 0;												// set duty cycle to 50 out of 768 to start.
	 	TIM1->CCR2 = 0;
	 	TIM1->CCR3 = 0;
	 	fullBrake();
	 }
	 	 	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
