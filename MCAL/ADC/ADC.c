#include "ADC_interface.h"
#include "../../Libraries/ATMEGA32.h"
#include "../../Libraries/BIT_manipulation.h"
#include "../../Libraries/ERROR_states.h"

void ADC_init()
{
	ADCSA_R |= (1 << ADCEN);
	
	#if VREF == VCC
	ADMUX_R |= (1 << REFS0);
	#elif VREF == INTERNAL
	ADMUX_R |= (1 << REFS1) | (1 << REFS0);
	#elif VREF == EXTERNAL
	BIT_CLEAR(ADMUX_R,REFS0);
	BIT_CLEAR(ADMUX_R,REFS1);
	#else
	     #error "VREF not selected properly"
    #endif
	
	#if PRESCALE == PRESCALE_2
	ADCSA_R |= (1 << ADPS0);
	#elif PRESCALE == PRESCALE_4
	ADCSA_R |= (1 << ADPS1);
	#elif PRESCALE == PRESCALE_8
	ADCSA_R |= (1 << ADPS0) | (1 << ADPS1);
	#elif PRESCALE == PRESCALE_16
	ADCSA_R |= (1 << ADPS2);
	#elif PRESCALE == PRESCALE_32
	ADCSA_R |= (1 << ADPS0) | (1 << ADPS2);
	#elif PRESCALE == PRESCALE_64
	ADCSA_R |= (1 << ADPS1) | (1 << ADPS2);
	#elif PRESCALE == PRESCALE_128
	ADCSA_R |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	#else
	     #error "ADC prescale not selected properly"
    #endif	
}

uint16_t ADC_read(uint8_t u8_channel)
{
	uint16_t ADC = 0;
	if (u8_channel >= ADC0 && u8_channel <= ADC7)
	{
		REG_SET(ADMUX_R,u8_channel);
	}
	else
		return WRONG_CHANNEL;
	
	ADCSA_R |= (1 << ADSC);            
	while (ADCSA_R & (1<<ADSC));
	ADC = (ADCL_R) | (ADCH_R << 8);
	return ADC;
}