#include <Wire.h>

const byte SHAKE_VALUE = 255;
const byte motorPins[] = {
  3, 5, 6, 9, 10
};
byte motorValues[] = {
  SHAKE_VALUE, SHAKE_VALUE, SHAKE_VALUE, SHAKE_VALUE, SHAKE_VALUE
};

void setup()
{
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  // Update all the motors.
  for(byte i = 0; i < 5; ++i)
  {
    analogWrite(motorPins[i], motorValues[i] > 0 ? SHAKE_VALUE : 0);
    if(motorValues[i] > 0)
    {
      motorValues[i]--;
    }
  }
  delay(10);
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    byte id = Wire.read();
    byte val = Wire.read();
    if(val > 0)
    {    
      motorValues[id] = val;
    }
  }
}
