/*  Feira de Engenharia Elétrica 2015 - FEE UFPB
    Software para controle de segurança de uma casa.
    Criado e mantido pelos alunos Vinícius Marinho, Matheus Duarte, Rivaldo Ferreira
    e pelos orientadores Filipe Cavalcanti e Marcelo Lira.

    João Pessoa, setembro de 2015.

*/
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial esp8266(2, 3);
#include <LiquidCrystal_I2C.h> //SDA: A4 //  SCL: A5
#include <Servo.h>
#define DEBUG true
#define SERVO 11

const int buzzer = 2; const int ir = 4; const int ldr = A2;
int detect, val;
const int led  = 7; const int relay = 8;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Servo s;
int pos;

void setup() {
  Serial.begin(9600);
  esp8266.begin(19200);
  pinMode(relay, OUTPUT); pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT); pinMode(ir, INPUT);
  pinMode(ldr, INPUT);
  s.attach(SERVO);
  s.write(0);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0); lcd.print("Projeto FEE 2015");
  lcd.setCursor(0, 1); lcd.print("      UFPB");
  delay(3000); lcd.clear();
  /////// Parte do WiFi ////////
  sendData("AT+RST\r\n", 2000, DEBUG); // rst
  sendData("AT+CWJAP=\"CavalcantiAP\",\"cavalcanticasa123\"\r\n", 2000, DEBUG);
  delay(3000);
  sendData("AT+CWMODE=1\r\n", 1000, DEBUG);
  sendData("AT+CIFSR\r\n", 1000, DEBUG);
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);
}

void loop() {
  val = analogRead(ldr);    // ler o valor do potenciômetro
  detect = digitalRead(ir);
  if (detect == 0) {            //presença foi detectada na casa
    digitalWrite(relay, HIGH);
    Serial.println("Status: Detectado");
    lcd.clear(); lcd.setCursor(0, 0);
    lcd.print("Status:    LDR:"); lcd.setCursor(0, 1);
    lcd.print("Detectado"); lcd.setCursor(12,1); lcd.print(val);
    tone(buzzer, 1500);
    delay(70);
    noTone(buzzer);
    if (val < 300)
      digitalWrite(led, HIGH);
    else
      digitalWrite(led, LOW);
    if (pos == 0) {
      for (pos = 0; pos < 90; pos++) {
        s.write(pos);
        delay(15);
      }
    }
  }
  if (detect == 1) {
    digitalWrite(relay, LOW);
    lcd.clear(); lcd.setCursor(0, 0);
    lcd.print("Status:    LDR:"); lcd.setCursor(0, 1);
    lcd.print("Livre"); lcd.setCursor(12,1); lcd.print(val);
    if (val < 300)
      digitalWrite(led, HIGH);
    else
      digitalWrite(led, LOW);
    if (pos == 90) {
      for (pos = 90; pos > 0; pos--) {
        s.write(pos);
        delay(15);
      }
    }
  }
  lcd.setBacklight(HIGH);
  delay(500);
  // Verifica se o ESP8266 esta enviando dados
  if (esp8266.available())
  {
    if (esp8266.find("+IPD,"))
    {
      delay(300);
      int connectionId = esp8266.read() - 48;

      String webpage = "<head><meta http-equiv=""refresh"" content=""3"">";
      webpage += "</head><h1><u>ESP8266 - FEE 2015</u></h1><h2>Porta";
      webpage += "Digital 8: ";
      int a = digitalRead(8);
      webpage += a;
      webpage += "<h2>Porta Digital 9: ";
      int b = digitalRead(9);
      webpage += b;
      webpage += "</h2>";

      String cipSend = "AT+CIPSEND=";
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";

      sendData(cipSend, 1000, DEBUG);
      sendData(webpage, 1000, DEBUG);

      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId; // append connection id
      closeCommand += "\r\n";

      sendData(closeCommand, 3000, DEBUG);
    }
  }
}



String sendData(String command, const int timeout, boolean debug)
{
 // Envio dos comandos AT para o modulo
 String response = "";
 esp8266.print(command);
 long int time = millis();
 while ( (time + timeout) > millis())
 {
   while (esp8266.available())
   {
     // The esp has data so display its output to the serial window
     char c = esp8266.read(); // read the next character.
     response += c;
   }
 }
 if (debug)
 {
   Serial.print(response);
 }
 return response;
}
