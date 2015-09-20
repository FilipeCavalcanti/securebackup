import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class sketch_150918b extends PApplet {

Table table;
int i=0;

public void setup(){
 
  table = loadTable("testerealp.txt","header,csv");
 
}

public void draw(){
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
  public void settings() {  size(500,500,P3D);  smooth(); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "sketch_150918b" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
