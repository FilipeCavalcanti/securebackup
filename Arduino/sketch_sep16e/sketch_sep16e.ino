  #include <Servo.h>

  Servo s; // Variável Servo
  int pos; // Posição Servo

  void setup ()
  {
    Serial.begin(9600);
    s.attach(10);
    s.write(0); // Inicia motor posição zero
    delay(500);
  }

  void loop()
  {
    for(pos = 0; pos < 90; pos++)
    {
      s.write(pos);
    delay(15);
    }
  delay(1000);
    for(pos = 90 ; pos >= 0; pos--)
    {
      s.write(pos);
      delay(15);
    }
    delay(1000);
  }
