
#include <pic16f18325.h>
#include "interupt.h"
#include "app.h"
extern bool FlaginterruptRx;
extern buffer monBuffer ;
unsigned char RX_byte ;

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
    //UART1_SendStr("coucou prout!!!\n");
    if(PIR1bits.RCIF) // si ils'agit d'une interuption RX
    {  
       FlaginterruptRx = 1;
       RX_byte = EUSART_Read();
    }

    //autres interuptions ici !   
}