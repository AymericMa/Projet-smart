

#include "app.h"

 buffer monBuffer;

 Airbuffer TXbuffer;

void InitBME280andPowerDown(void)
{
	BME280_write8(BME280_REGISTER_CONTROLHUMID, 0x01); // regler avant  CONTROL !!!
    BME280_write8(BME280_REGISTER_CONTROL, 0b00100100);
    readSensorCoefficients(); 
}

void Bme280_OneMeasure(float *temp,float * humi,float *press)
{
	 BME280_goForceMode();
     __delay_ms(200);
     *temp = BME280_readTemperature();
     *humi = BME280_readHumidity();
     *press = BME280_readPressure();
}

