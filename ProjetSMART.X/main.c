


// Configuration bits: selected in the GUI

// CONFIG1
#pragma config FEXTOSC = OFF    // FEXTOSC External Oscillator mode Selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINT1    // Power-up default value for COSC bits->HFINTOSC (1MHz)
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit->CLKOUT function is disabled; I/O or oscillator function on OSC2
#pragma config CSWEN = ON    // Clock Switch Enable bit->Writing to NOSC and NDIV is allowed
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor is enabled

// CONFIG2
#pragma config MCLRE = ON    // Master Clear Enable bit->MCLR/VPP pin function is MCLR; Weak pull-up enabled
#pragma config PWRTE = OFF    // Power-up Timer Enable bit->PWRT disabled
#pragma config WDTE = OFF   // Watchdog Timer Enable bits->WDT enabled; SWDTEN 
#pragma config LPBOREN = OFF    // Low-power BOR enable bit->ULPBOR disabled
#pragma config BOREN = ON    // Brown-out Reset Enable bits->Brown-out Reset enabled, SBOREN bit ignored
#pragma config BORV = LOW    // Brown-out Reset Voltage selection bit->Brown-out voltage (Vbor) set to 2.45V
#pragma config PPS1WAY = ON    // PPSLOCK bit One-Way Set Enable bit->The PPSLOCK bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a Reset
#pragma config DEBUG = OFF    // Debugger enable bit->Background debugger disabled

// CONFIG3
#pragma config WRT = OFF    // User NVM self-write protection bits->Write protection off
#pragma config LVP = ON    // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored.

// CONFIG4
#pragma config CP = OFF    // User NVM Program Memory Code Protection bit->User NVM code protection disabled
#pragma config CPD = OFF    // Data NVM Memory Code Protection bit->Data NVM code protection disabled

#include "xc.h"
#include "system.h"
#include "eusart.h"
#include "I2C1.h"
#include "interupt.h"
#include <stdio.h>
#include "app.h"

//variables globales
    float f_temp;
    float f_humi;
    float f_press;
    bool FlaginterruptRx=0;

void main()
{
    SYSTEM_Initialize();
    __delay_ms(2000);
    
    // Init sensors-----------------------------------------------------------
    //TSL2561_write8(TSL2561_COMMAND_BIT,POWER_ON);
    InitBME280andPowerDown();
    readSensorCoefficients();
    //------------------------------------------------------------------------
    
    //Init interrupt ---------------------------------------------------------
    EnableGlobalinterupts();
    EnablePeripheralInterupts();
    EnableRXInterupts();
    // -----------------------------------------------------------------------
    
    //__delay_ms(40);
    //UART1_SendStr("AT+PWRM1");
    
	while(1)
	{   
        CPUDOZEbits.IDLEN = 1;
        SLEEP();
        
        if (FlaginterruptRx==1){
        
            BME280_goForceMode();
            f_temp = BME280_readTemperature();
            f_humi = BME280_readHumidity();
            //f_press = BME280_readPressure();
            char Stockage[12];
            sprintf(Stockage,"%0.2f Deg / %0.2f \n",f_temp,f_humi);
            UART1_SendStr(Stockage);
            __delay_ms(40);
            FlaginterruptRx=0;
        }
        
        __delay_ms(2000);
        UART1_SendStr("AT+SLEEP");
     
    }
}