Table table;
int i=0;
int linhas;

void setup(){
  size(500,500,P3D);
  table = loadTable("testerealp.txt","header,csv");
  linhas = table.getRowCount();
  smooth();
}

void draw(){
  background(0,0,255);
  TableRow row = table.getRow(i);
  float x = row.getFloat("xg");
  float y = row.getFloat("yg");
  float z = row.getFloat("zg");
  translate(250,250,0);
  rotateX(y); rotateY(x); rotateZ(z);
  box(150,75,30);
  println(x);
  i++;
  if (i==linhas){
    println("Fim de arquivo");
    delay(1000);
    exit();
  }
}
