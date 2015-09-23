int x=0;
int y=0;
int z=0;
int val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  String dados = "";
  val = Serial.read();
  if (val==1){
    x = random(0,45);
    y = random(0,45);
    z = random(0,45);
    dados += x; dados += " "; dados += y; dados += " "; dados += z;
    Serial.println(dados);
    delay(50);
  }
}
