import org.json.JSONObject;
import processing.serial.*;

Serial myPort;

boolean ready = false;
int x = 0;
int y = 0;
int z = 0;

void setup()
{
  size(1080, 1080, P3D);

  println(Serial.list());

  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil(10);
}

void draw()
{
  lights();

  background(0);

  if(ready) {
    fill(255);
    textSize(16);
    text("X: " + x, 10, 20);
    text("Y: " + y, 10, 40);
    text("Z: " + z, 10, 60);

    pushMatrix();
      fill(0, 255, 0);
      translate(width/2, height/2, 0);
      rotateX(radians(-x));
      rotateY(radians(z));
      rotateZ(radians(y));
      box(300);
    popMatrix();
  } else {
    fill(255);
    textSize(64);
    text("Calibrating, don't move...", 10, 80);
  }
}

void serialEvent(Serial port)
{
  String str = port.readString();
  str = str.substring(0, str.length() - 1);

  if(str.charAt(0) == '{') {
    ready = true;

    JSONObject json = new JSONObject(str);
    x = json.getInt("x");
    y = json.getInt("y");
    z = json.getInt("z");
  } else {
    ready = false;
    println(str);
  }
}
