#include <TinyGPS++.h>
TinyGPSPlus gps;

void setup() {
Serial.begin(9600);
Serial1.begin(4800);

}

void loop() {
  gps.encode(Serial1.read());
  Serial.println(Serial1.read());
  
}
