#include <CapacitiveSensor.h>
#include <Wire.h>

const byte TOUCH_ON = 100;
const byte TOUCH_OFF = 0;
const byte TOUCH_SAMPLES = 30;
const byte TOUCH_THRESHOLD = 125;
byte touchValues[] = {
  0, 0, 0, 0, 0
};
CapacitiveSensor touchs[] = {
  CapacitiveSensor(4,2),
  CapacitiveSensor(4,3),
  CapacitiveSensor(4,5),
  CapacitiveSensor(4,6),
  CapacitiveSensor(4,7)
};

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
  for(byte i = 0; i < 5; ++i)
  {
//    touchs[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
}

void loop()
{
  for(byte i = 0; i < 5; ++i)
  {
    touchValues[i] =  touchs[i].capacitiveSensor(TOUCH_SAMPLES);
  }

  Wire.beginTransmission(8); // transmit to device #8
  for(byte i = 0; i < 5; ++i)
  {
    Wire.write(i);              // sends one byte
    if(touchValues[i] > TOUCH_THRESHOLD)
    {
      Serial.print("touch");
      Serial.print((int)i);
      Serial.print(": ");
      Serial.print((int)touchValues[i]);
      Serial.print("\n");
      Wire.write(TOUCH_ON);
    }
    else
    {
      Wire.write(TOUCH_OFF);
    }
  }
  Wire.endTransmission();    // stop transmitting
  delay(50);
}
