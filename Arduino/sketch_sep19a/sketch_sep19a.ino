#include <Servo.h>
Servo sg;

int blue = 3;
int green = 5;
int red = 6;
int i=255;
  int pos = 0;
int j;

void setup()
{
  Serial.begin(4800);
  sg.attach(9);
  sg.write(pos);
}

void loop()
{
  for(j=0;j<60;j++){
    analogWrite(blue,255);
    sg.write(j);
    delay(15);
  }
  analogWrite(blue,0);
  delay(500);
  for(j=60;j<120;j++){
    analogWrite(green,255);
    sg.write(j);
    delay(15);
  }
  analogWrite(green,0);
  delay(500);
  for(j=120;j<180;j++){
    analogWrite(red,255);
    sg.write(j);
    delay(15);
  }
  analogWrite(red,0);
  delay(500);
  for(j=180;j=0;j--){
    analogWrite(red,250);
    analogWrite(green,250);
    sg.write(j);
    delay(15);
  }
  delay(500);
}
