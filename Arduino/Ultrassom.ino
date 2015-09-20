const int trig = 13;
const int echo = 12;

void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop(){
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  float tempo = pulseIn(echo, HIGH);
  Serial.println(tempo);
  delay(500);
}
