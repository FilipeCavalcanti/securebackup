/*  Feira de Engenharia Elétrica 2015 - FEE UFPB
    Software para controle de segurança de uma casa.
    Criado e mantido pelos alunos Vinícius Marinho, Matheus Duarte, Rivaldo Ferreira
    e pelos orientadores Filipe Cavalcanti e Marcelo Lira.

    João Pessoa, setembro de 2015.

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //SDA: A4 //  SCL: A5

const int buzzer = 2;
const int ir = 4;

int detect;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup(){
  pinMode(buzzer,OUTPUT);
  pinMode(ir,INPUT);
  Serial.begin(9600);
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0); lcd.print("Projeto FEE 2015");
  lcd.setCursor(0,1); lcd.print("       UFPB");
  delay(3000); lcd.clear();
}

void loop(){
  detect = digitalRead(ir);
  if (detect==0){
    lcd.setBacklight(HIGH);
    Serial.println("Detectado");
    lcd.setCursor(0,0);
    lcd.print("   FEE 2015");
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer); 
    delay(70);
  }
  else
    delay(500);
    lcd.setBacklight(LOW);
}
