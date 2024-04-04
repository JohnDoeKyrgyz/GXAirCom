
/*!
 * @file Weather.h
 */

#ifndef __Weather_H__
#define __Weather_H__

#include <Arduino.h>
#include <string.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TimeLib.h>
#include <ctime>
#include "main.h"
#include <ADS1X15.h>
#include <SparkFun_Weather_Meter_Kit_Arduino_Library.h>

#define DEG2RAD M_PI / 180.0
#define RAD2DEG 180.0 / M_PI

#define WEATHER_REFRESH 2000

#define WEATHER_UPLOAD 300000uL //weather upload intervall 5min

#define Bucket_Size 0.5           // rain bucket size 0.5mm

class Weather {
public:
    typedef struct {
        bool bTemp = false; //temp exists
        float temp = 0.0; //temp [°C]
        bool bHumidity = false; //humidity exists
        float Humidity = 0.0; // [%rH]
        bool bPressure = false; // pressure exists
        float Pressure = 0.0; // [hPa]
        bool bWindDir = false; //winddir exists
        float WindDir = 0.0; //[Deg]
        bool bWindSpeed = false; //windspeed exists
        float WindSpeed = 0.0; //[km/h]
        float WindGust = 0.0; //[km/h]
        bool bRain = false; //rain-sensor exists
        float rain1h = 0.0; // rain this hour [l/h]
        float rain1d = 0.0; // rain this day [l/h]
        int vaneValue = 0;
    } weatherData;

    Weather(); //constructor
    ~Weather();
    void setTempOffset(float tempOffset);
    void setWindDirOffset(int16_t winddirOffset);
    bool begin(TwoWire *pi2c, SettingsData &setting, int8_t oneWirePin, int8_t windDirPin, int8_t windSpeedPin,int8_t rainPin);
    void run();
    bool getValues(weatherData *weather);

protected:
private:
    TwoWire *pI2c;
    bool checkI2Caddr(uint8_t);
    bool initBME280();
    float calcPressure(float p, float t, float h);    
    void checkDavisAnemometer();
    void checkAnalogWeatherVane();
    void checkAnalogAnemometer();
    void checkRainSensor();
    float calcWindSpeed();
    Adafruit_BME280 bme;
    float _tempOffset = 0;
    int16_t _windDirOffset = 0;
    float _height = 0;
    uint8_t _windDirPin;
    uint8_t _windSpeedPin;
    weatherData _weather;
    bool bNewWeather;
    SemaphoreHandle_t xMutex;
    OneWire oneWire;
    DallasTemperature sensors;
    bool hasTempSensor;
    DeviceAddress tempSensorAdr;
    uint32_t _actPulseCount = 0;
    float winddir;
    float windspeed = 0;
    float windgust = 0;
    uint32_t rainTipCount1h = 0;
    uint32_t rainTipCount1d = 0;
    uint8_t actHour = 0;
    uint8_t actDay = 0;
    uint8_t anemometerType = 0;
    bool _bHasBME = false;
    SFEWeatherMeterKit* _sparkFunWeatherMeter = nullptr;
    AnemometerSettings anSettings;
};
#endif