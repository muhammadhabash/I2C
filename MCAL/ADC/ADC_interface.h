#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_private.h"

/********************************************/
/*            Options for VREF              */
/********************************************/
/*  1 - VCC      (5V)                       */
/*  2 - INTERNAL (2.56V)                    */
/*  3 - EXTERNAL (VCC external at AREF pin) */
/********************************************/
#define VREF VCC

/**********************************************/
/*            Options for PRESCALE            */
/**********************************************/
/*  1 - PRESCALE_2   (Division factor of 2  ) */
/*  2 - PRESCALE_4   (Division factor of 4  ) */
/*  3 - PRESCALE_8   (Division factor of 8  ) */
/*  4 - PRESCALE_16  (Division factor of 16 ) */
/*  5 - PRESCALE_32  (Division factor of 32 ) */
/*  6 - PRESCALE_64  (Division factor of 64 ) */
/*  7 - PRESCALE_128 (Division factor of 128) */
/**********************************************/  
#define PRESCALE  PRESCALE_128



#endif 