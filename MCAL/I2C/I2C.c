#include "I2C_interface.h"

/**********************************************************************************************************************/
/*                                       Master Transmit/Receive APIs Implementation                                  */
/**********************************************************************************************************************/
                                                                                                                      //
void I2C_masterInit(void){                                                                                            //
	                                     /************************************************/                           //
	TWBR = BIT_RATE;                     /*  1 - Setting Bit Rate                        */                           //
	#if PRESCALER == PRESCALER_1         /*                                              */                           //
	TWSR = (0 << TWPS1) | (0 << TWPS0);  /*  2 - Prescaler Value Of 1                    */                           //
	#elif PRESCALER == PRESCALER_4       /*                                              */                           //
	TWSR = (0 << TWPS1) | (1 << TWPS0);  /*  3 - Prescaler Value Of 4                    */                           //
	#elif PRESCALER == PRESCALER_16      /*                                              */                           //
	TWSR = (1 << TWPS1) | (0 << TWPS0);  /*  4 - Prescaler Value Of 16                   */                           //
	#elif PRESCALER == PRESCALER_64      /*                                              */                           //
	TWSR = (1 << TWPS1) | (1 << TWPS0);  /*  5 - Prescaler Value Of 64                   */                           //
	#else                                /************************************************/                           //
	     #error "Invalid Prescaler"                                                                                   //
	#endif                                                                                                            //
}                                                                                                                     //
                                                                                                                      //
void I2C_masterStart(void){                                                                                           //
	                                                 /*****************************************************************/
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);/* 1 - Reset I2C interrupt flag, send start condition, enable I2C*/
	while(!(TWCR & (1 << TWINT)));                   /* 2 - Stay here until start condition has been transmitted      */
	while( (TWSR & 0xF8) != MASTER_START);           /* 3 - Check status register that start condition has been sent  */
}                                                    /*****************************************************************/
                                                                                                                       ////////
void I2C_repeatedStart(void){                                                                                          ////////
	                                                /*************************************************************************/
	TWCR= (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);/* 1 - Reset I2C interrupt flag, send start condition, enable I2C        */
	while(!(TWCR & (1 << TWINT)));                  /* 2 - Stay here until start condition has been transmitted              */
	while( (TWSR & 0xF8) != MASTER_REPEATED_START); /* 3 - Check status register that repeated start condition has been sent */
}                                                   /*************************************************************************//////////////////////////////
                                                                                                                              //////////////////////////////
void I2C_masterWriteToAddress(uint8_t u8_slaveAddress){                                                                       //////////////////////////////
	                                                          /********************************************************************************************/
	TWDR = (u8_slaveAddress << 1);                            /* 1 - Higher 7 - bits to represent slave address and LSB is set to 0 for writing operation */
	TWCR = (1 << TWINT) | (1 << TWEN);                        /* 2 - Reset I2C interrupt flag and enable I2C operation                                    */
	while (!(TWCR & (1 << TWINT)));                           /* 3 - Stay here until slave address has been transmitted                                   */                                                    
	while ( (TWSR & 0xF8) != SLAVE_ADDRESS_WRITE_TRANSMITTED);/* 4 - Check in status register that address has been transmitted and slave has acknowledged*/
}                                                             /********************************************************************************************/
                                                                                                                                                         ///
void I2C_masterReadFromAddress(uint8_t u8_slaveAddress){                                                                                                 ///
	                                                          /******************************************************************************************///
	TWDR = (u8_slaveAddress << 1);                            /* 1 - Higher 7 - bits to represent slave address                                         *///
	TWDR = (1 << 0);                                          /* 2 - Set LSB in TWD_R to 1 for reading operation                                        *///
	TWCR = (1 << TWINT) | (1 << TWEN);                        /* 3 - Reset I2C interrupt flag and enable I2C operation                                  *///
	while (!(TWCR & (1 << TWINT)));                           /* 4 - Stay here until slave address to read from has been transmitted                    *///
	while ( (TWSR & 0xF8) != SLAVE_ADDRESS_READ_TRANSMITTED); /* 5 - Check in status register that the address of slave to read has been transmitted    *///
}                                                             /******************************************************************************************///
                                                                                                                                           /////////////////
void I2C_masterWriteData(uint8_t u8_data){                                                                                                 /////////////////
	                                                         /*****************************************************************************/
	TWDR = u8_data;                                          /* 1 - Load data to be transmitted                                           */
	TWCR = (1 << TWINT) | (1 << TWEN);                       /* 2 - Reset I2C interrupt flag and enable I2C operation                     */
	while (!(TWCR & (1 << TWINT)));                          /* 3 - Stay here until data is transmitted from master                       */
	while ( (TWSR & 0xF8) != MASTER_WRITE_DATA_TRANSMITTED); /* 4 - Check in status register that data has been transmitted               */
}                                                            /*****************************************************************************/
                                                                                                                                          //
uint8_t I2C_masterReadData(void){                                                                                                         //
	                                                       /*******************************************************************************/
	TWCR = (1 << TWINT) | (1 << TWEN);                     /* 1 - Reset I2C interrupt flag and enable I2C operation                       */
	while (!(TWCR & (1 << TWINT)));                        /* 2 - Stay here until data is received by master                              */
	while ( (TWSR & 0xF8) != MASTER_READ_DATA_TRANSMITTED);/* 3 - Check that data has been transmitted to master                          */
	return TWDR;                                           /* 4 - Return transmitted data                                                 */
}                                                          /*******************************************************************************/
                                                                                                                                          //
void I2C_masterStop(void){                                                                                                                //
	                                                  /************************************************************************************/
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO); /* 1 - Reset I2C interrupt flag, enable I2C operation and transmit a stop condition */
	while  (!(TWCR & (1<<TWSTO)));                    /* 2 - Stay here until stop condition is successfully transmitted                   */
}                                                     /************************************************************************************/
                                                                                                         
												
												
																										 
																										 
/******************************************************************************************************************************************/
/*                                             Slave Transmit/Receive APIs Implementation                                                 */
/******************************************************************************************************************************************/
                                                                                                                                          //
void I2C_slaveInit(uint8_t u8_ownAddress){                                                                                                //
	                             /*********************************************************************************************************/
	TWAR = (u8_ownAddress << 1); /* 1 - Higher 7 - bits to represent slave address, LSB is set to 0 to disable general call               */
}                                /*********************************************************************************************************/
                                                                                                                                          //
void I2C_slaveWrite(uint8_t u8_data){                                                                                                     //
	                                                  /************************************************************************************/
	TWDR = u8_data;                                   /* 1 - Load data to be transmitted                                                  */
	TWCR = (1 << TWEN) | (1 << TWINT);                /* 2 - Reset I2C interrupt flag and enable I2C operation                            */
	while  ((TWSR & 0xF8) != SLAVE_DATA_TRANSMITTED); /* 3 - Check in status register that slave data has been transmitted                */                                                                                       
}                                                     /************************************************************************************/
                                                                                                                                          //
void I2C_slaveAckWrite(void){                                                                                                             //
	                                                                                                                                      //
	while((TWSR & 0xF8) != SLAVE_READ_FROM_ADDRESS_TRANSMITTED){                                                                          //
		                                                 /*********************************************************************************/
		TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWINT); /* 1 - Enable acknowledgment, enable I2C operation and reset interrupt flag      */
		while  (!(TWCR & (1 << TWINT)));                 /* 2 - Stay here until acknowledgment                                            */
	}                                                    /*********************************************************************************/
}                                                                                                                                         //
                                                                                                                                          //
uint8_t I2C_slaveRead(void){                                                                                                              //
	                                                       /*******************************************************************************/
	TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);       /* 1 - Reset interrupt flag, Enable acknowledgment and enable I2C operation    */
	while  (!(TWCR & (1 << TWINT)));                       /* 2 - Stay here until acknowledgment                                          */
	while  ((TWSR & 0xF8) != SLAVE_READ_DATA_TRANSMITTED); /* 3 - Check status register that data is transmitted to slave                 */
	return TWDR;                                           /* 4 - Return transmitted data                                                 */
}                                                          /*******************************************************************************/
                                                                                                                                          //
void I2C_slaveAckRead(void){                                                                                                              //
	                                                            /**************************************************************************/
	while((TWSR & 0xF8) != SLAVE_WRITE_TO_ADDRESS_TRANSMITTED){ /* 1 - Stay here until address of slave to write to is transmitted        */
		                                                        /*                                                                        */
		TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWINT);        /* 2 - Enable acknowledgment, enable I2C operation, reset interrupt flag  */
		while  (!(TWCR & (1 << TWINT)));                        /* 3 - Stay here until acknowledgment                                     */
	}                                                           /**************************************************************************/
}                        

