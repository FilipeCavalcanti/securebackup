import processing.serial.*;
PrintWriter output;
float x;
float y;
float z;

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
    data += myPort.readStringUntil('\n'); //Lê até pular a linha (lembrar do println)
    String sub[] = split(data,' ');       //Split separa a string de acordo com um caracter que desejar
    x = float(sub[0]);                    //Cada caracter fica em uma posição no vetor
    y = float(sub[1]);
    z = float(sub[2]);
    println(x,y,z);
    delay(1000);
    }
  }
