#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../Libraries/STD_types.h"

#define HIGH              (1)
#define LOW               (0)
#define ONE               (1)
#define NINE              (9)
#define FIRST_ROW         (2)
#define FIRST_COLUMN      (5)
#define ROWS              (4)
#define COLUMNS           (7)
#define NO_BUTTON_PRESSED (0)

void keypad_init(void);
uint8_t keypad_scan(void);


#endif