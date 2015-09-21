float i = -2.0;
void setup(){
 size(800,600,P3D);
}

void draw(){
  background(0);
 
  pushMatrix();
  translate(400,300);
  rotateY(radians(i));
  fill(0,0,255);
  box(75,25,250);
  popMatrix();
  println(i);
  if (i<=90)
    i = i + 0.2;
  if (i>=90)
    i = i + 0.3;
}