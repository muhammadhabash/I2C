#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*********************************************/
/*             Files Inclusions              */
/*********************************************/

#include "../../Libraries/ATMEGA32.h"

/*********************************************/
/*                 TWC_R BITS                */
/*********************************************/

#define TWIE  (0)
#define TWEN  (2)
#define TWWC  (3)
#define TWSTO (4)
#define TWSTA (5)
#define TWEA  (6)
#define TWINT (7)

/*********************************************/
/*                 TWS_R BITS                */
/*********************************************/

#define TWPS0 (0)
#define TWPS1 (1)
#define TWS3  (3)
#define TWS4  (4)
#define TWS5  (5)
#define TWS6  (6)
#define TWS7  (7)

/*********************************************/
/*                 TWA_R BITS                */
/*********************************************/

#define TWGCE (0)

/*********************************************/
/*                SLC Prescaler              */
/*********************************************/

#define PRESCALER_1  (1)
#define PRESCALER_4  (4)
#define PRESCALER_16 (16)
#define PRESCALER_64 (64)

/*********************************************/
/*             TWS_R Status Codes            */
/*********************************************/

#define MASTER_START                        (0x08)
#define MASTER_REPEATED_START               (0x10)
#define SLAVE_ADDRESS_WRITE_TRANSMITTED     (0x18)
#define MASTER_WRITE_DATA_TRANSMITTED       (0x28)
#define SLAVE_ADDRESS_READ_TRANSMITTED      (0x40)
#define MASTER_READ_DATA_TRANSMITTED        (0x58)
#define SLAVE_READ_DATA_TRANSMITTED         (0x80)
#define SLAVE_DATA_TRANSMITTED              (0xC0)
#define SLAVE_READ_FROM_ADDRESS_TRANSMITTED (0xA8)
#define SLAVE_WRITE_TO_ADDRESS_TRANSMITTED  (0x60)


/*****************************************************/
/*            Protoypes for I2C Master               */
/*****************************************************/

void I2C_masterInit(void);
void I2C_masterStart(void);
void I2C_repeatedStart(void);
void I2C_masterWriteToAddress(uint8_t);
void I2C_masterReadFromAddress(uint8_t);
void I2C_masterWriteData(uint8_t);
uint8_t I2C_masterReadData(void);
void I2C_masterStop(void);

/*****************************************************/
/*             Protoypes for I2C Slave               */
/*****************************************************/

void I2C_slaveInit(uint8_t u8_ownAddress);
void I2C_slaveAckRead(void);
uint8_t I2C_slaveRead(void);
void I2C_slaveAckWrite(void);
void I2C_slaveWrite(uint8_t u8_data);


#endif