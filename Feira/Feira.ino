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
const int ldr = A2;
int detect;
int val;
const int led  = 7;
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup(){
  pinMode (led, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ir,INPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0); lcd.print("Projeto FEE 2015");
  lcd.setCursor(0,1); lcd.print("       UFPB");
  delay(3000); lcd.clear();
}

void loop(){
  val = analogRead(ldr);    // ler o valor do potenciômetro
 Serial.println(val);            //emvia valor para o pc
 delay(1000);
 detect = digitalRead(ir);
  if (detect==1){ //presença foi detectada na casa
    lcd.setBacklight(HIGH);
    Serial.println("Detectado");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(val);
    lcd.setCursor(0,1);
    lcd.print(val);//sensor de ldr
    if(val<300){
    digitalWrite (led, HIGH);
      tone(buzzer,3000);
    delay(70);
    noTone(buzzer); 
    delay(70);
    }
   else if(val>600){
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer); 
    delay(70);
    digitalWrite(led, HIGH);
    }
    else{digitalWrite (led, LOW);}
    
  }                        //aguarda 1 segundo
   else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LADRAO FDP");
    lcd.setCursor(0,1);
    lcd.print("CORRE VAGABUNDO"); 
    //digitalWrite(buzzer, HIGH);
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer); 
    delay(70);
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer); 
    delay(70);
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer); 
    delay(70);
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer); 
    delay(70);
   }
   
  

lcd.setBacklight(HIGH);
}
