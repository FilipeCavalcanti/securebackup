PImage grid;
Table table;
int i=0;
int linhas;

void setup(){
  size(800,600,P3D);
  grid = loadImage("grid.jpg");
  table = loadTable("testerealp.txt","header,csv");
  linhas = table.getRowCount();
  smooth();
}

void draw(){
  background(0);
  //image(grid,0,0);
  TableRow row = table.getRow(i);
  float x = row.getFloat("x");
  float y = row.getFloat("y");
  float z = row.getFloat("z");

  text("Eixo x: " + radians(-x),150,500);
  text("Eixo y: " + radians(y),350,500);
  text("Eixo z: " + radians(z),550,500);
  text("Linha: " + i,150,550);

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

  println(x + "," + y + "," + z);
    i++;
  if (i==linhas){
    println("Fim de arquivo");
    delay(1000);
    exit();
  }
}
