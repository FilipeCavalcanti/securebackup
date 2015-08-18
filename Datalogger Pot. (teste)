/*
 Teste do datalogger.
 
 REQUER BIBLIOTECA SdFat disponível em https://github.com/greiman/SdFat 
 
 Lê os dados de um potenciômetro e salva num arquivo txt dentro do cartão de memória. 
 
 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 */

#include <SPI.h>
#include <SdFat.h>
SdFat SD;

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 4;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.print("--Formula SAE-E UFPB--");
  Serial.print("\nInicializando SD Card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Problema ao conectar.");
    // don't do anything more:
    return;
  }
    Serial.println(" Conectado com sucesso.\n");
}

void loop()
{
  // make a string for assembling the data to log:
  String dataString = "";
  // read three sensors and append to the string:
  while (analogRead(1)>=100){
    int sensor = analogRead(1);
    Serial.println(sensor);
    dataString += String(sensor);
    dataString += ",";
    delay(2000);
  }
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("logteste2.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println("\nEnviado ao txt:");    
    Serial.println(dataString);
    delay(2000);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("Erro ao abrir log.txt");
   }
   delay(3000);
}
