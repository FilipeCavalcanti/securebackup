Table table;
int i=0;

void setup(){
  size(500,500,P3D);
  table = loadTable("testerealp.txt","header,csv");
  smooth();
}

void draw(){
  background(0,0,255);
  TableRow row = table.getRow(i);
  float x = row.getFloat("xg");
  float y = row.getFloat("yg");
  float z = row.getFloat("zg");
  translate(400,250,0);
  rotateX(y);
  rotateY(x);
  rotateZ(z);
  box(150,75,20);
  println(x);
  i++;
}