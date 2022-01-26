#include "MCAL/I2C/I2C_interface.h"

int main(void)
{
	I2C_masterInit();  
	while(1){
		
		I2C_masterStart();
		I2C_masterWriteToAddress(0x20); 
		I2C_masterWriteData(0xf0); //41    
		I2C_masterStop(); 
	}
}
