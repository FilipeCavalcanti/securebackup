import processing.serial.*;
Serial myPort;
PImage background;
int i = 0;
float x;
float y;
float z;
float lat;
float longi;
float speed;

void setup() {
  size(800,600,P3D);
  smooth();
  background = loadImage("back2.jpg");
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 57600);
}

void draw(){
  String data = "";
  //myPort.bufferUntil('\n');
  data += myPort.readStringUntil('\n'); //Lê até pular a linha (lembrar do println)
  String sub[] = split(data,',');       //Split separa a string de acordo com um caracter que desejar
  println("Str Length:" + data.length());
  if (data.length() > 50){
  x = float(sub[7]);                    //Cada valor fica em uma posição no vetor
  y = float(sub[8]);
  z = float(sub[9]);
  lat = float(sub[3]);
  longi = float(sub[2]);
  speed = float(sub[4]);
  
  println(x,y,z);
  background(background);
  fill(255,255,255);
  textSize(18);
  text("Yaw: " + (z) + "º",670,465);
  text("Pitch: " + (y) + "º",670,485);
  text("Roll: " + (x) + "º",670,505);
  text("Latitude: " + lat,20,480);
  text("Longitude: " + longi,20,500);

  textSize(24);
  text(speed,85,300);
  textSize(21);
  text("km/h",100,330);

  pushMatrix();
  translate(400,300);
  rotateX(radians(x));
  rotateY(radians(y));
  rotateZ(radians(z));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();

  println(x + "," + y + "," + z);

  int s = second(); int m = minute(); int h = hour();
  int d = day();  int n = month(); int a = year();
  text(d+"/"+n+"/"+a+"  "+h+":"+m+":"+s+"  Linha "+i, 5,595);
  i++;
  //serialEvent(myPort);
  }
  delay(30);
}

/*void serialEvent(Serial myPort){
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
}*/