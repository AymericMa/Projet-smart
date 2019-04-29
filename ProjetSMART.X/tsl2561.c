#include "tsl2561.h"

inline int16_t TSL2561_read16(uint8_t reg)
{
    uint32_t temp ; 
    I2C_Master_Start();
    I2C_Master_Write(TSL2561_ADDRESS_WRITE); //selection registre
    I2C_Master_Wait();
    I2C_Master_Write(reg); //selection registre
    I2C_Master_Wait();
    //I2C_Master_ReStart();
    I2C_Master_Stop();
    I2C_Master_Start();
    I2C_Master_Write(TSL2561_ADDRESS_READ); //lecture
    I2C_Master_Wait();
    temp = I2C_Master_Read(I2C_ACK);
    //temp<<=8;
    temp |= I2C_Master_Read(I2C_NACK);
    I2C_Master_Wait();
    I2C_Master_Stop();
    
    return temp;    
    
}

inline int8_t TSL2561_read8(uint8_t reg)
{
    int8_t temp ; 
    I2C_Master_Start();
    I2C_Master_Write(TSL2561_ADDRESS_WRITE); //selection egistre
    I2C_Master_Wait();
    I2C_Master_Write(reg); //selection egistre
    I2C_Master_Wait();
    I2C_Master_Stop();
    I2C_Master_Start();
    I2C_Master_Write(TSL2561_ADDRESS_READ); //lecture
    I2C_Master_Wait();
    temp = I2C_Master_Read(I2C_NACK);
    I2C_Master_Wait();
    I2C_Master_Stop();
    
    return temp;
    
}

inline int8_t TSL2561_write8(uint8_t reg,uint8_t value)
{
    I2C_Master_Start();
    I2C_Master_Write(TSL2561_ADDRESS_WRITE); //selection registre
    //I2C_Master_Wait();
    I2C_Master_Write(reg); //selection registre
    //I2C_Master_Wait();
    I2C_Master_Write(value); //selection registre
    //I2C_Master_Wait();
    I2C_Master_Stop();
    
}