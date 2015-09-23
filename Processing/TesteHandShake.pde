import processing.serial.*;
Serial myPort;

void setup(){
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  establishContact();
}

void establishContact(){
  int val = myPort.read();
  if(val==789){
    myPort.println("Processing");
}
