PImage backufpb;
PFont font;
Table table;
int i=0;
int linhas;

void setup(){
  size(800,600,P3D);
  font = createFont("fonteteste",32);
  table = loadTable("datalogfsae23.09.txt","header,csv");
  linhas = table.getRowCount();
  backufpb = loadImage("back2.jpg");
  smooth();
}

void draw(){
  background(backufpb);

  TableRow row = table.getRow(i);
  float x = row.getFloat("GyroX");
  float y = row.getFloat("GyroY");
  float z = row.getFloat("GyroZ");
  float speed = row.getFloat("Velocidade");
  float latitude = row.getFloat("Latitude");
  float longitude = row.getFloat("Longitude");

  textFont(font);
  fill(255,255,255);
  textSize(18);
  text("Yaw: " + (z) + "º",670,465);
  text("Pitch: " + (y) + "º",670,485);
  text("Roll: " + (x) + "º",670,505);
  text("Latitude: " + latitude,20,480);
  text("Longitude: " + longitude,20,500);

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
  textSize(12);
  fill(255,255,255);
  text(d+"/"+n+"/"+a+"  "+h+":"+m+":"+s+"  Linha "+i, 5,595);

  i++;
  if (i==linhas){
    println("Fim de arquivo");
    delay(1000);
    exit();
  }
  delay(50);
}