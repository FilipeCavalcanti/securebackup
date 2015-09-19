int ir;

void setup() {
  Serial.begin(9600);
  pinMode(10,INPUT);
}

void loop() {
  ir = digitalRead(10);
  if(ir==0)
    Serial.println("Detectado");
  else
    Serial.println("Livre");
  delay(1000);
}
