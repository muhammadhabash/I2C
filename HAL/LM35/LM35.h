#ifndef LM35_H_
#define LM35_H_

#include "../../Libraries/STD_types.h"

#define ADC_RESOLUTION (1024)
#define SENSITIVITY    (10  )
#define VREF           (5   )

uint8_t temperature(void);



#endif