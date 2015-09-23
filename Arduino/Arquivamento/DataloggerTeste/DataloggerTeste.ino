 /*
 Teste do datalogger.
 ###### USAR 3,3 VOLTS ########
 ###### REQUER BIBLIOTECA SDFAT https://github.com/greiman/SdFat ######
 The circuit:
 ** MOSI - pin 11  
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
Código original aproveitado do site oficial do Arduino.
Traduzido pela equipe de Sensoriamento do SAE-E UFPB.

*/

#include <SPI.h>
#include <SdFat.h>
SdFat SD;

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 53;

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
  pinMode(53, OUTPUT);

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Erro!");
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);
    Serial.end();
    
  }
  else{
    Serial.println(" Conectado com sucesso!\n");
    pinMode(6, OUTPUT);
    digitalWrite(6, HIGH);
  }
}
void loop()
{
  // make a string for assembling the data to log:
  String dataString = "";
  // read sensor and append to the string:
  while (analogRead(A1)>=100){
    int sensor = analogRead(A1);
    Serial.println(sensor);
    dataString += String(sensor);
    dataString += ",";
    delay(2000);
  }

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("testecsv.csv", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println("\nEnviado ao arquivo:");    
    Serial.println(dataString);
    Serial.println("\n");
  }
  else {
    Serial.println("Confira se o potenciometro esta em posicao > 100.");
   }
   delay(5000);
}

