#include "LM35.h"
#include "../../MCAL/ADC/ADC_private.h"

uint8_t temperature(void){
	
	f32_t   f32_stepSize;
	uint8_t u8_scaleFactor, u8_temp1, u8_temp2, u8_temp3, u8_temp4, u8_temp5, u8_tempAvg;
	
	f32_stepSize   = (VREF / (ADC_RESOLUTION*1.0))*1000;
	u8_scaleFactor = SENSITIVITY / f32_stepSize;
	
	u8_temp1 = ADC_read(ADC0)/u8_scaleFactor;
	u8_temp2 = ADC_read(ADC0)/u8_scaleFactor;
	u8_temp3 = ADC_read(ADC0)/u8_scaleFactor;
	u8_temp4 = ADC_read(ADC0)/u8_scaleFactor;
	u8_temp5 = ADC_read(ADC0)/u8_scaleFactor;
	
	u8_tempAvg = (u8_temp1 + u8_temp2 + u8_temp3 + u8_temp4 + u8_temp5)/5;
	
	return u8_tempAvg;
}
