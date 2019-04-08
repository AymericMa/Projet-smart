#include "I2C1.h"


#define TSL2561_ADDRESS     0x39          // define the default I2C address



// Name of Registers used in the TSL2561
    
    
#define    TSL2561_REGISTER_POWERON      0xA0
#define    TSL2561_REGISTER_LUX          0xAC
#define    POWER_ON                      0x03
#define TSL2561_COMMAND_BIT       0x80    ///< Must be 1
#define TSL2561_CLEAR_BIT         0x40    ///< Clears any pending interrupt (write 1 to clear)
#define TSL2561_WORD_BIT          0x20    ///< 1 = read/write word (rather than byte)
#define TSL2561_REGISTER_CHAN1_LOW 0x0E

//fonctions

inline int8_t TSL2561_write8(uint8_t reg,uint8_t value);
inline uint16_t TSL2561_read16(uint8_t reg);
