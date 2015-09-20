import processing.serial.*;
int i=0;

Serial myPort;

void setup() {
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  while (myPort.available() > 0) {
   String dados = myPort.readString();
   String[] separado = split(dados,",");
   for(i=0; i<separado.length; i++){
     println(separado[i]);
   }
  }
}