int i=0;

void setup() {
Serial.begin(57600);
}

void loop() {
Serial.println("Teste Formula UFPB");
Serial.println(i);
i++;
delay(200);
}
