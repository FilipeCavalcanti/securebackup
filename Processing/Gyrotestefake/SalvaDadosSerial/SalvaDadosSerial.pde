import processing.serial.*;
PrintWriter output;
int i=0;
int x;

Serial myPort;

void setup() {
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
  output = createWriter("test2.txt");

}

void draw() {
  while (myPort.available() > 0) {
    String data = "";
    String sub = "";
    data += myPort.readStringUntil('\n'); //Lê até pular a linha (lembrar do println)
    sub += data.substring(0,2);           //(x,y) -> Lê do caracter x até o y
    if(sub == null){
      draw();
    }
    output.println(sub);
    println(sub);
  }
}

void keyPressed(){
  output.flush(); // Writes the remaining data to the file
  output.close(); // Finishes the file
  exit();
}
