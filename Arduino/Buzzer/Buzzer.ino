/*Buzzer para FEE
  Filipe do Ó Cavalcanti
*/

const int buzzer = 5;
const int ir = 7;
int detect;

void setup(){
  pinMode(buzzer,OUTPUT);
  pinMode(ir,INPUT);
  Serial.begin(9600);
}

void loop(){
  detect = digitalRead(ir);
  if(detect==0){
  Serial.println("Detectado");
  tone(buzzer,1500);
  delay(70);
  noTone(buzzer);
  delay(70);
  }
  else
  delay(500);
}
