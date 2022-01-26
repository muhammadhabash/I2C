#include "MCAL/I2C/I2C_interface.h"


#define  PORTA_DIRECTION (*((volatile uint8_t*) 0x3A))
#define  PORTA_DATA      (*((volatile uint8_t*) 0x3B))
#define  OUTPUT          (0xFF)

int main(void)
{
	PORTA_DIRECTION = OUTPUT;
	I2C_slaveInit(0x20); 
	while(1)
	{
		I2C_slaveAckRead();
		PORTA_DATA = I2C_slaveRead(); 
	}
}
