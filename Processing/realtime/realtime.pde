import processing.serial.*;
Serial myPort;
int i = 0;
float x;
float y;
float z;
int firstContact = 0;

void setup() {
  size(800,600,P3D);
  smooth();
  //frameRate(60);
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  delay(5000);
}

void draw(){
  background(0);
  textSize(24);
  fill(255,0,0);
  text("Formula SAE-E UFPB",275,30);
  textSize(12);
  fill(0,0,255);
  text("Eixo x: " + radians(x),150,500);
  text("Eixo y: " + radians(y),350,500);
  text("Eixo z: " + radians(z),550,500);

  pushMatrix();
  translate(200,300,0);
  rotateX(radians(y));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();

  pushMatrix();
  translate(400,300);
  rotateY(radians(x));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();

  pushMatrix();
  translate(600,300);
  rotateZ(radians(z));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();
  delay(50);

  int s = second(); int m = minute(); int h = hour();
  int d = day();  int n = month(); int a = year();
  text(d+"/"+n+"/"+a+"  "+h+":"+m+":"+s+"  Linha "+i, 5,595);
  i++;
  serialEvent(myPort);
}

void serialEvent(Serial myPort){
  int valor = myPort.read();
  if (valor != 0){
    println(valor);
    if(firstContact == 0){
     if(valor == 1){
     myPort.clear();
     firstContact = 1;
     myPort.write('A');
     }
  }
  else{
  //println("foi");
  String data = "";
  data += myPort.readStringUntil('\n'); //Lê até pular a linha (lembrar do println)
  String sub[] = split(data,' ');       //Split separa a string de acordo com um caracter que desejar
  println("Str Length:" + data.length());
  if(sub[0]==null)
      serialEvent(myPort);
  if(sub[1]==null)
      serialEvent(myPort);
  x = float(sub[0]);                    //Cada valor fica em uma posição no vetor
  y = float(sub[1]);
  z = float(sub[2]);
  println(x,y,z);
  }
  myPort.write('A');
 }
}