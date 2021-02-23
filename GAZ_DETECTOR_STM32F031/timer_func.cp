#line 1 "D:/ALL_PROJECTS/GAZ_DETECTOR/UZCAR_STM32F0/UZCAR_STM32F031_MC101_BTU/timer_func.c"
#line 1 "d:/all_projects/gaz_detector/uzcar_stm32f0/uzcar_stm32f031_mc101_btu/hider.h"
#line 1 "d:/all_projects/gaz_detector/uzcar_stm32f0/uzcar_stm32f031_mc101_btu/stm32f030x6.h"
#line 1 "c:/program files (x86)/mikroelektronika/mikroc pro for arm/include/built_in.h"
#line 24 "d:/all_projects/gaz_detector/uzcar_stm32f0/uzcar_stm32f031_mc101_btu/hider.h"
extern sfr sbit BOARD_HEATER;
extern sfr sbit FORWARD_HEATER;
extern sfr sbit BACKWARD_HEATER;

extern sfr sbit CAL_BUTTON;

extern sfr sbit BUZER;

extern sfr sbit LED_GREEN;
extern sfr sbit LED_RED;
#line 78 "d:/all_projects/gaz_detector/uzcar_stm32f0/uzcar_stm32f031_mc101_btu/hider.h"
typedef enum state_t{control_calibration = 1,error_calibration,read_data_for_cal,
 calibration,start_sound,preheat,ready_alarm,getV0,process,sensor_alarm,sensor_damage}state_n;
extern state_n state;
extern sfr sbit LED_GREEN;
extern char input_buffer[ 25  ];
extern char request_string[];

extern sfr sbit BOARD_HEATER;
extern sfr sbit FORWARD_HEATER;
extern sfr sbit BACKWARD_HEATER;

extern sfr sbit CAL_BUTTON;

extern sfr sbit BUZER;

extern sfr sbit LED_GREEN;
extern sfr sbit LED_RED;

extern sfr sbit LED_UART_TR;

struct flag {

 unsigned char ovf_flag;
 unsigned char board_sensor_status;
 unsigned char forward_sensor_status;
 unsigned char backward_sensor_status;
 unsigned char cal_button_status;
 unsigned char start_sensor_control;
 unsigned char heater_status;
 unsigned char ready_calibration_prog;
 unsigned char alarm_enable_status;
 unsigned char board_sensor_damage;
 unsigned char forward_sensor_damage;
 unsigned char backward_sensor_damage;
 unsigned char calibrate_status;
 unsigned char recalibrate;
 unsigned char board_cal_status;
 unsigned char forward_cal_status;
 unsigned char backward_cal_status;
 unsigned char enable_status;
 unsigned char request_uart_status;
 unsigned char start_process_status;
 unsigned char response_status;
 unsigned char process_start_status;
 unsigned char first_start;
 unsigned char alarm_sensor_status;
 };
extern struct flag flag_t;



struct parameters {
 unsigned int forward_sensor_v0_cal_data;
 unsigned int backward_sensor_v0_cal_data;
 unsigned int board_sensor_v0_cal_data;
 unsigned int forward_sensor_cal_data;
 unsigned int backward_sensor_cal_data;
 unsigned int board_sensor_cal_data;
 unsigned int forward_sensor_ready;
 unsigned int backward_sensor_ready;
 unsigned int board_sensor_ready;
 unsigned int board_sensor_koef;
 unsigned int forward_sensor_koef;
 unsigned int backward_sensor_koef;
 unsigned int crc_adc;
};
extern struct parameters parameters_t;

extern volatile float BoardSensorValue, ForwardSensorValue, BackwardSensorValue;
extern volatile float BoardSensorPPM, ForwardSensorPPM,BackwardSensorPPM;
extern volatile float BoardSensorR0, ForwardSensorR0, BackwardSensorR0;
extern volatile float BoardSensorVrl,ForwardSensorVrl,BackwardSensorVrl;
extern volatile unsigned char analogStatusAllChanell;
extern volatile unsigned long bs_var;
extern volatile unsigned long fs_var;
extern volatile unsigned long bcs_var;
extern volatile unsigned long bs_fs_var;
extern volatile unsigned long fs_bcs_var;
extern volatile unsigned long bs_bcs_var;
extern volatile unsigned long bs_fs_bcs_var;
extern volatile unsigned char AnalogSensorDamageControl;
extern volatile float VrefIntVoltage;
extern volatile float temperature;
extern unsigned long ADDRESS;
extern unsigned long ADDRESS2;
extern float VsenseArray[ 100 ];

void Init_flags();
void Init_pin();
void Init_ADC_chanell();
void ReadAnalogInput();
unsigned long Read_ADC_chanell(unsigned char chanell,unsigned int samples);
void ControlAnalogFlags();
void one_level_comparator_sec(float reference,float value, float gisteresis,
 unsigned int delay_on_sec,unsigned int delay_off_sec,unsigned int ms_in_one_cycle,unsigned char* status,
 unsigned int* count_olc,unsigned int* count_olc1);
void two_level_comparator(float high_reference,float low_reference,float value,
 float gisteresis, unsigned int delay_on_sec_tlc,unsigned int delay_off_sec_tlc,
 unsigned int ms_in_one_cycle_tlc,unsigned char* status_tlc,unsigned int* count_tlc,
 unsigned int* count_tlc1);
void two_level_comparator_ms(float high_reference,float low_reference,float value,
 float gisteresis, unsigned int delay_on_ms_tlc,unsigned int delay_off_ms_tlc,
 unsigned int ms_in_one_cycle_tlc,unsigned char* status_tlc,unsigned int* count_tlc,
 unsigned int* count_tlc1);
void ControlDigitalFlags();
void ControlOut();
void ControlDigit_sec(unsigned char in_value, unsigned int delay_set,
 unsigned int delay_reset, unsigned int ms_in_one_cycle, unsigned char* status,
 unsigned int* count_ci, unsigned int* count_ci1);
void globalProcess();
void WDT_Init();
void clear_WDT();
void setPreloadValue(unsigned long value);
char save_data_to_eeprom(unsigned char len_array);
char read_data_from_eeprom(unsigned char len_array);
void StartTimer3_10ms();
void Init_flash_cal();
void setState(state_n newState);
state_n getState();
void ReadDataInEEPROM();
void controlCalibration();
void ErrorCalibration();
void Blink_buz_func(unsigned int blink_mode,char count_loop1,
 char out,char count_digit,char new_state,char enable_new_state,unsigned char after_count);
void Blink_leds_func(unsigned int blink_mode_led,unsigned char count_loop1,
 unsigned char out,unsigned char count_digit_led,unsigned char new_state,unsigned char enable_new_state,
 unsigned char after_count,unsigned char enable_buzzer);
void StartSound(unsigned char state);
void Preheat_f();
void Calibration_f();
void ReadyAlarm_f();
void Process_f();
void SensorAlarm();
void setAdcControlStatus(unsigned char status);
void setHeaterStatus(unsigned char state);
void heaterMode(unsigned char mode);
unsigned char getAdcStatus();
unsigned char getAdcControlStatus();
unsigned char getHeaterStatus();
void resetLB();
void setLB();
void resetAllHeater();
void setAllHeater();
void CalibrateADC();
void EnableADC(void);
void SetClockForADC(void);
void ControlDigit_ms(unsigned char in_value, unsigned int delay_set,
 unsigned int delay_reset, unsigned int ms_in_one_cycle, unsigned char* status,
 unsigned int* count_ci, unsigned int* count_ci1);
void one_level_comparator_ms(float reference,float value, float gisteresis,
 unsigned int delay_on_ms,unsigned int delay_off_ms,unsigned int ms_in_one_cycle,unsigned char* status,
 unsigned int* count_olc,unsigned int* count_olc1);
void Sequence(unsigned char* seq_data,unsigned char count_digit_led,unsigned char buz_en);
void WriteVarToArray(unsigned char* data_ar_local, unsigned long var,unsigned char num_of_char);
unsigned int Read_ADC_sample(unsigned char chanell);
void bs_alarm_signal();
void fs_alarm_signal();
void bcs_alarm_signal();
void bs_fs_alarm_signal();
void fs_bcs_alarm_signal();
void bs_bcs_alarm_signal();
void bs_fs_bcs_alarm_signal();
void bs_damage_signal();
void fs_damage_signal();
void bcs_damage_signal();
void bs_fs_damage_signal();
void fs_bcs_damage_signal();
void bs_bcs_damage_signal();
void bs_fs_bcs_damage_signal();
double calculatePPM(double adcValue,double R0,double cal_data);
float getR0(float Rl,float adcValue,float koef, float volt, float adcRange);
void Calibrate();
void GetAllPPM();
double map(double x, double in_min, double in_max, double out_min, double out_max);
void SensorDamage();
void ControlSensorDamage();
unsigned char getDamageSensorStatus();
void InitVar();
void Recalibrate();
void ReadVrefIntValue();
void ControlV0(unsigned int* v0_data,unsigned int* tmp,unsigned int offset,unsigned char* flag);
void ControlVs(unsigned int* v0_data,unsigned int* tmp,unsigned int* vs_data,unsigned char* flag);
void ComputeTemperature();
void ReadTempAndVoltage();
void ControlCalibrate(long delay_sec);
void CalculateVsense(float* sense_adc_value,unsigned int time,float* out_value);
unsigned int read_from_eeprom_one(unsigned long adr);
char save_data_to_eeprom_one(unsigned long adr,unsigned char sample,unsigned char* status);
void ChekTrue();
void RestartCalibration(unsigned long delay_rcal);
void ControlRecalFlags();
unsigned char getRcalAdcStatus();
float NegativeLimiter(float value);

char FLASH_ReadOutProtection(unsigned char new_state);
char FLASH_WaitForLastOperation();
void ControlReadOutProtection();

void InitUartModuleBTU();
void Clear_buffer(char* buf,unsigned int len);
void ControlInputData();
void WriteDataToAndroid();
unsigned char ControlData();
#line 4 "D:/ALL_PROJECTS/GAZ_DETECTOR/UZCAR_STM32F0/UZCAR_STM32F031_MC101_BTU/timer_func.c"
void StartTimer3_10ms(){
 RCC_APB1ENRbits.TIM3EN =  1 ;
 TIM3_CR1bits.CEN =  0 ;
 TIM3_PSC = 7;
 TIM3_ARR = 59999;
 NVIC_IntEnable(IVT_INT_TIM3);
 TIM3_DIERbits.UIE =  1 ;
 TIM3_CR1bits.CEN =  1 ;
}


void Timer3_10ms_int() iv IVT_INT_TIM3 ics ICS_AUTO
{
 static unsigned char tim_count = 0;
 static unsigned int msec = 0,sec = 0,min = 0,hour = 0;
 TIM3_SRbits.UIF = 0;
 flag_t.ovf_flag =  1 ;
#line 69 "D:/ALL_PROJECTS/GAZ_DETECTOR/UZCAR_STM32F0/UZCAR_STM32F031_MC101_BTU/timer_func.c"
}

void WDT_Init()
{
 RCC_CSRbits.LSION = 1;
 while(!RCC_CSRbits.LSIRDY);
 IWDG_KR = 0x5555;
 IWDG_PRbits.PR = 0x00;
 IWDG_KR = 0xCCCC;
 IWDG_KR = 0xAAAA;










}

void clear_WDT()
{
 IWDG_KR = 0xAAAA;
}
