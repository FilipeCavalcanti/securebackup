#include <SPI.h>
#include <SdFat.h>
SdFat SD;

const int chipSelect = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("--Formula SAE-E UFPB 2016--");
  Serial.print("\nInicializando SD Card...");
  pinMode(10, OUTPUT);
  //verifica se o cartao SD esta conectado
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro!");
    Serial.end();
  }
  else
    Serial.println("Conectado!");
  Serial.println("\nLatitude, Longitude, Altitude, Velocidade");
}

void loop() {
  gpsdata();
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
  //cria e abre o arquivo onde os dados serao salvos
  File dataFile = SD.open("testegrava.txt", FILE_WRITE);
  //escreve os dados e fecha o arquivo
  if (dataFile) {
    dataFile.println(dados);
    dataFile.close();
  }
  delay(300);
}
