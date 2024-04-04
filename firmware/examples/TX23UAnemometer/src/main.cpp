#include <Arduino.h>
#include <Tx20.h>
#include <TX23U.h>

#define ANEMOMETER 25

uint8_t _windSpeed = 0;
uint16_t _windDirection = 0;

TX23U anemometer(ANEMOMETER);

void setup()
{
    Serial.begin(115200);
//    tx20_init(ANEMOMETER);
}

// these are global variables.  I really should make most local but.....

// get wind speed and direction
void getWind(int windPin)
{
    byte datagramBits = 23;
    unsigned int bitWide;
    unsigned int halfBitWide;
    byte windDirNbl;
    static unsigned long windReadTimer = 0;
    static byte windReadIndex = 0;
    static unsigned long getWindTimer = 0;
    getWindTimer = millis();
    pinMode(windPin, OUTPUT);
    digitalWrite(windPin, LOW);
    delay(500);
    digitalWrite(windPin, HIGH);
    pinMode(windPin, INPUT);

    for(int dataGramIndex = 0; dataGramIndex < 2; dataGramIndex++)
    {
        unsigned long datagram = 0;
        while(digitalRead(windPin) == LOW);  // wait for datagram start
        unsigned int twiceBitWide = pulseIn(windPin, HIGH, 100000);  // get bit width
        bitWide = twiceBitWide / 2;
        halfBitWide = twiceBitWide / 4;
        delayMicroseconds(halfBitWide);
        windReadIndex = 0;
        while(windReadIndex < datagramBits)
        {
            if(micros() - windReadTimer > bitWide)
            {
                windReadTimer = micros();
                bitWrite(datagram, windReadIndex, digitalRead(windPin));
                windReadIndex++;
            }
        }
        for(int n = 0; n < 4; n++)
        {
            bitWrite(windDirNbl, n, bitRead(datagram, n + 3));
        }
        int windSpd = 0;
        for(int n = 0; n < 12; n++)
        {
            bitWrite(windSpd, n, bitRead(datagram, n + 7));
        }

        byte ckSum = 0;
        byte fNbl, sNbl, tNbl;
        for(int n = 0; n < 4; n++)
        {
            bitWrite(ckSum, n, bitRead(datagram, n + 19));
        }

        fNbl = windSpd & 0x000F;
        sNbl = (windSpd >> 4) & 0x000F;
        tNbl = (windSpd >> 8) & 0x000F;
        byte sumOfAll = (windDirNbl + fNbl + sNbl + tNbl) & 0x0F;
        if(ckSum == sumOfAll)
        {
            Serial.printf("%d Direction = %d, Speed = %d\n", dataGramIndex, windDirNbl, windSpd);
        }
        else
        {
            Serial.println("***  CHECKSUM FAIL  ***");
        }
    }
}

void loop()
{
//    tx20getNewData(&_windSpeed, &_windDirection);
//    Serial.printf("WindSpeed = %d, WindDirection = %d\n", _windSpeed, _windDirection);

//    if (anemometer.getData()) {
//        anemometer.printRawData();
//        Serial.printf("Direction %d, Speed %d\n", anemometer.direction, anemometer.speed);
//        Serial.print("Direction: ");
//        Serial.println(anemometer.DIRECTIONS[anemometer.direction]);
//        Serial.print("Speed: ");
//        Serial.println(anemometer.speed);
//    } else {
//        Serial.println("ERROR");
//    }

    getWind(ANEMOMETER);
    delay(1000);
}