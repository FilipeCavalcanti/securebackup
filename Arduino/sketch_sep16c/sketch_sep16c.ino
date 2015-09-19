int ldr=A2;
int valor=0;
int led=4;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (ldr, INPUT);
pinMode (led,   OUTPUT);


}

void loop() {
valor= analogRead (ldr);
Serial.println (ldr);
delay(1000);
if(valor<500){
  digitalWrite(led,HIGH);
}
if(valor>500){
  digitalWrite(led, LOW);}
}
