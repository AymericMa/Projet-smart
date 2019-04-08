


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
  uint16_t  lux ;
  float temperature ; 
  float humidity ;
  float pressure ;
uint8_t tx_address1[5] = {0xE7,0xE7,0xE7,0xE7,0xE7};
uint8_t rx_address1[5] = {0xD7,0xD5,0xD7,0xD7,0xD7};

uint8_t device_address[5] = {0xAA,0xBB,0xCC,0xDD,0xEE};

uint16_t luxValue;
void main()
{
    
    SYSTEM_Initialize();
    __delay_ms(2000);
    
    EnableRXInterupts();
    EnableGlobalinterupts();
    EnablePeripheralInterupts();
    // IOCANbits.IOCAN5 = 1;
    
    // InitBME280andPowerDown();

    
     PORTCbits.RC3 = 0 ;  
   // CLRWDT();
    //SLEEP();
   
    TSL2561_write8(TSL2561_REGISTER_LUX,POWER_ON);
        

	while(1)
	{
        __delay_ms(1000);
        UART1_SendStr("Je suis dans la boucle while\n");
        
        
        luxValue = TSL2561_read16(TSL2561_COMMAND_BIT | TSL2561_WORD_BIT | TSL2561_REGISTER_CHAN1_LOW);
        printf("Lux : %d \r\n",luxValue);
        UART1_SendHex(luxValue);
        CLRWDT();
        //Bme280_OneMeasure(&temperature,&humidity,&pressure);

            
       CPUDOZEbits.IDLEN = 1;
       //SLEEP();// go dodo , le watchdog doit nous reveiller dans 8 secondes

     //  printf("Lux : %d \r\n",LireLux(1));
     
    /*   PORTCbits.RC3 = 1 ; 
      //  set_csn(0,1);
      __delay_ms(500);
       PORTCbits.RC3 = 0 ;
        //set_csn(1,1);
       __delay_ms(500); */
     
     
      
      
    }
}