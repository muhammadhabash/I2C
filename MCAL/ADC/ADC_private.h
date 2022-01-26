#ifndef ADC_H_
#define ADC_H_

#include "../../Libraries/STD_types.h"
/****************************************************************************/
/*                               ADC Channels                               */
/****************************************************************************/
#define ADC0 (0)
#define ADC1 (1)
#define ADC2 (2)
#define ADC3 (3)
#define ADC4 (4)
#define ADC5 (5)
#define ADC6 (6)
#define ADC7 (7)

/****************************************************************************/
/*                      Reference Voltage Source                            */
/****************************************************************************/
#define EXTERNAL (20)
#define VCC      (21)
#define INTERNAL (22)

/****************************************************************************/
/*                      ADC Control Register Bits                           */
/****************************************************************************/
#define ADPS0    (0)
#define ADPS1    (1)
#define ADPS2    (2)
#define ADIE     (3)
#define ADIF     (4)
#define ADATE    (5)
#define ADSC     (6)
#define ADCEN    (7)

/****************************************************************************/
/*                      ADC VREF Selection Bits                             */
/****************************************************************************/

#define REFS0    (6)
#define REFS1    (7)

/****************************************************************************/
/*                      ADC Clock Prescale Values                           */
/****************************************************************************/

#define PRESCALE_2   (10)
#define PRESCALE_4   (11)
#define PRESCALE_8   (12)
#define PRESCALE_16  (13)
#define PRESCALE_32  (14)
#define PRESCALE_64  (15)
#define PRESCALE_128 (16)

/****************************************************************************/
/*                               Prototypes                                 */
/****************************************************************************/

void ADC_init(void);
uint16_t ADC_read(uint8_t u8_channel);



#endif