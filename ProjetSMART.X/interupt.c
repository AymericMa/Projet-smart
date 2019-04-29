
#include <pic16f18325.h>
#include "interupt.h"
#include "app.h"

extern buffer monBuffer ;
unsigned char RX_byte ;
uint16_t luxValue;

inline void EnableGlobalinterupts(void)
{
    INTCONbits.GIE = 1 ; 
}
inline void DisableGlobalinterupts(void)
{
    INTCONbits.GIE = 0 ; 
}

inline void EnablePeripheralInterupts(void)
{
    INTCONbits.PEIE = 1 ; 
}

inline void DisablePeripheralInterupts(void)
{
    INTCONbits.PEIE = 0 ; 
}

inline void EnableRXInterupts(void)
{
    PIE1bits.RCIE = 1 ; 
}

inline void DisableRXInterupts(void)
{
    PIE1bits.RCIE = 0 ; 
}



void __interrupt() interupt1(void)
{
    UART1_SendStr("coucou prout!!!\n");
    if(PIR1bits.RCIF) // si ils'agit d'une interuption RX
    {
       //---------------------------------------------------------------
       //uint32_t testemp;
       //BME280_goForceMode();
       //testemp = BME280_readTemperature();
       //UART1_SendStr("Temperature : %d \r\n");
       //printf("Temperature : %d \r\n",testemp/100);
       //TSL2561_write8(TSL2561_REGISTER_LUX,POWER_ON);
       //luxValue = TSL2561_read16(TSL2561_REGISTER_LUX);
       UART1_SendStr("coucou interruption!!!\n");
       //UART1_SendDec(luxValue);
       //---------------------------------------------------------------
       RX_byte = EUSART_Read();
       if(RX_byte == 0x0A) // si le caractere est "\n"
       {
          
          interpretation(); 
       }
       else // sinon on le stock
       {
           //printf("stock");
           monBuffer.data[monBuffer.len] = RX_byte; //on stock
           monBuffer.len++; //on incremente la position du buffer
            if(monBuffer.len > RX_BUFFER_SIZE) // si le buffer est plein les caractere suivant ecraserons les autres 
            {
                monBuffer.len = 0 ;
            }
       }
    }

    //autres interuptions ici !   
}