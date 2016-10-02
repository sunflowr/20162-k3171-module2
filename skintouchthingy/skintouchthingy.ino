int piezo = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
}

void loop()
{
  int aval = analogRead(0);
  if(aval < 1000)
  {
    int val = constrain(aval, 400, 1000);
    int val2 = map(val, 400, 1000, 0, 4000);
    digitalWrite(piezo, HIGH);
    delayMicroseconds(val2);
    digitalWrite(piezo, LOW);
    delayMicroseconds(val2);
  }

  digitalWrite(piezo, HIGH);
  //Serial.println(aval);
  //delay(200);
}
