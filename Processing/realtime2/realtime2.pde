import processing.serial.*;
Serial myPort;
PImage background;
String incoming, dia, hora,satelites;
String data[];
float x,y,z,longit,latit,speed;

void setup() {
  size(800,600,P3D);
  smooth();
  background = loadImage("back2.jpg");
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 57600);
  myPort.buffer(81);
}

void draw(){
    if(incoming != null){
    data = split(incoming,',');
    dia = data[0];
    hora = data[1];
    longit = float(data[2]);
    latit = float(data[3]);
    speed = float(data[4]);
    satelites = data[6];
    x = float(data[7]); y = float(data[8]); z = float(data[9]);
    }
    background(background);
    fill(255,255,255);
    textSize(18);
    text("Yaw: " + (z) + "º",665,465);
    text("Pitch: " + (y) + "º",665,485);
    text("Roll: " + (x) + "º",665,505);
    text("Latitude: " + latit,20,480);
    text("Longitude: " + longit,20,500);
    
    textSize(11);
    text("Escutando xBee na porta serial. Sensoriamento Formula SAE UFPB 2015 v1.0",width/4,595);
    text("Data: " + dia,5,570);
    text("Hora: " + hora,5,581);
    text("Fixado em " + satelites + " satelites.", 5,592);
    textSize(24);
    text(speed,85,300);
    textSize(21);
    text("km/h",100,330);
 
    pushMatrix();
    translate(400,300);
    rotateX(radians(-x));
    rotateY(radians(z));
    rotateZ(radians(y));
    fill(0,0,255);
    box(75,25,250);
    popMatrix();
    
    if(incoming==null){
       textSize(21);
       fill(255,0,0);
       text("Aguardando dados na porta serial...",220,180);
    }
}

void serialEvent(Serial myPort){
  incoming = myPort.readStringUntil('\n');
}