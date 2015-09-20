#include <Ultrasonic.h>

const int trig = 13;
const int echo = 12;

Ultrasonic ultrasonic(trig,echo);

void setup()
{
   Serial.begin(9600); //inicia a porta serial
}

void loop(){
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.print(", IN: ");
  Serial.println(inMsec);
  delay(1000);
}
