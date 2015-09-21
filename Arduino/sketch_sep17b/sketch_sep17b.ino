int x=0;
int y=0;
int z=0;

void setup() {
Serial.begin(9600);
}

void loop() {
String dados = "";

x = random(10,45);
y = random(10,45);
z = random(10,45);

dados += x; dados += " "; dados += y; dados += " "; dados += z;
Serial.println(dados);
delay(50);
}
