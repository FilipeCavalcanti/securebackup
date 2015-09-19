#include <SoftwareSerial.h>
#include <TinyGPS++.h>
TinyGPSPlus gps;

SoftwareSerial gps1(10, 11); // RX, TX

void setup(){
  Serial.begin(9600);
  Serial.println("Conectando...");
  while(!Serial){
    ;
  }
  gps1.begin(9600);
  gps1.println("Conectado.");
}

void loop(){
  gps.encode(gps1.read());
  if (gps.location.isUpdated()){
  Serial.print("LAT=");  Serial.println(gps.location.lat(), 6);
  Serial.print("LONG="); Serial.println(gps.location.lng(), 6);
  Serial.print("ALT=");  Serial.println(gps.altitude.meters());
  delay(500);     
}
}
