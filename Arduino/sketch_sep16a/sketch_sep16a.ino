int sensor = 4;
int ler;

void setup() {
Serial.begin(9600);
pinMode(sensor, INPUT);
}

void loop() {
  ler = digitalRead(sensor);
  if (ler==1)
  Serial.println("Livre");
  else
  Serial.println("Detectado");
delay(1000);
}
