import processing.serial.*;
PrintWriter output;
int i=0;

Serial myPort;

void setup() {
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  output = createWriter("teste.txt");
}

void draw() {
  while (myPort.available() > 0) {
    String data = "";
    data += myPort.readString();
    String sub = data.substring(0,2);
    println(sub);
    //println(data);
   }
}

/*(void keyPressed(){
  output.flush();
  output.close();
  exit();
}*/
