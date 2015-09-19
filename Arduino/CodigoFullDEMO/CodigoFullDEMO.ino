#include <SPI.h>
#include <SdFat.h>
SdFat SD;

const int chipSelect = 4;

void setup() {
  Serial.begin(9600);
  Serial.print("--Formula SAE-E UFPB 2016--");
  Serial.println("SIS v1.0");
  sdsetup();
}
  
void loop() {
  sdsetup();
  gpsdata();
}

void sdsetup(){
  Serial.print("\nInicializando SD Card...");
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro!");
    Serial.end();
  }
  else
    Serial.println("Conectado!");
}

void gpsdata() {
  String dados = "";
  dados += (random(0, 7)); //latitude
  dados += (",");
  dados += (random(15, 30)); //longitude
  dados += (",");
  dados += (random(0, 5)); //altitude
  dados += (",");
  dados += (random(30, 50)); //velocidade
  Serial.println(dados);

  File dataFile = SD.open("testegrava.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println(dados);
    dataFile.close();
  }
  delay(300);
}
