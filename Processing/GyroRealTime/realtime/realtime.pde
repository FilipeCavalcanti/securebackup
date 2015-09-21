import processing.serial.*;
float x;
float y;
float z;

Serial myPort;

void setup() {
  size(800,600,P3D);
  smooth();
  frameRate(60);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  if (myPort.available() > 0) {
    String data = "";
    data += myPort.readStringUntil('\n'); //Lê até pular a linha (lembrar do println)
    String sub[] = split(data,' ');       //Split separa a string de acordo com um caracter que desejar
    x = float(sub[0]);                    //Cada caracter fica em uma posição no vetor
    y = float(sub[1]);
    z = float(sub[2]);
    println(x,y,z);
  }

  background(0);
  text("Eixo x: " + radians(x),150,500);
  text("Eixo y: " + radians(y),350,500);
  text("Eixo z: " + radians(z),550,500);
  //text("Linha: " + i,150,550);

  pushMatrix();
  translate(200,300,0);
  rotateX(radians(x));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();

  pushMatrix();
  translate(400,300);
  rotateY(radians(y));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();

  pushMatrix();
  translate(600,300);
  rotateZ(radians(z));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();
  //println(x + "," + y + "," + z);
  delay(50);
}