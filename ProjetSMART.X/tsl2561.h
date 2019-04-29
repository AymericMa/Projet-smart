#include "I2C1.h"


#define TSL2561_ADDRESS_READ     0x73          // define the default I2C address read
#define TSL2561_ADDRESS_WRITE     0x72          // define the default I2C address write



// Name of Registers used in the TSL2561
    
    
#define    TSL2561_REGISTER_POWERON      0xA0
#define    TSL2561_REGISTER_LUX          0xAC
#define    POWER_ON                      0x03
#define TSL2561_COMMAND_BIT       0x80    ///< Must be 1
#define TSL2561_CLEAR_BIT         0x40    ///< Clears any pending interrupt (write 1 to clear)
#define TSL2561_CONTROL_REG       0x00
#define TSL2561_WORD_BIT          0x20    ///< 1 = read/write word (rather than byte)
#define TSL2561_REGISTER_CHAN0_LOW 0x0C

//fonctions

inline int8_t TSL2561_write8(uint8_t reg,uint8_t value);
inline int8_t TSL2561_read8(uint8_t reg);
inline int16_t TSL2561_read16(uint8_t reg);
