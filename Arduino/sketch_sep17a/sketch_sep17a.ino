  #include <Servo.h>

  Servo s; // Variável Servo
  int pos; // Posição Servo
  const int buzz = 2;
  void setup ()
  {
    Serial.begin(9600);
    pinMode(buzz,OUTPUT);
    s.attach(10);
    s.write(0); // Inicia motor posição zero
    delay(500);
  }

  void loop()
  {
    for(pos = 0; pos < 180; pos++)
    {
      s.write(pos);
    delay(15);
    Serial.println(s.read());
    if(pos==179){
      tone(buzz,1500);
      delay(1000);
      noTone(buzz);
    }
  }
  delay(1000);
    for(pos = 180 ; pos >= 0; pos--)
    {
      s.write(pos);
      delay(15);
      Serial.println(s.read());
      if(pos==0){
        tone(buzz,1500);
        delay(1000);
        noTone(buzz);
      }
    }
    delay(1000);
  }
