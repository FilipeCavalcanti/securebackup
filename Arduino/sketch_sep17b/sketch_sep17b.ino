char relay;

void setup(){
  Serial.begin(9600);
  pinMode(7,OUTPUT);
}

void loop(){
  if(Serial.available()){
    relay = Serial.read();
    Serial.println(relay);
    if(relay=='H')
      digitalWrite(7,HIGH);
    if(relay=='L')
      digitalWrite(7,LOW);
  }
  delay(100);
}
