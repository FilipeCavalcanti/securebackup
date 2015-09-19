int portao;
int ilum;
int arcon;
int valor;

void setup() {
  Serial.begin(9600);
  pinMode(portao, OUTPUT);
  pinMode(iluminacao, OUTPUT);
  pinMode(arcon, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

if ( valor<200 ){
digitalWrite(portão, HIGH);
digitalWrite(iluminação, HIGH);
digitalWrite(arcondicionado; HIGH);
analogRead(Display, HIGH);

lcd.clear();          //limpa o display do LCD.
  lcd.print("Oi!!! ");  //imprime a string no display do LCD.
  delay(2000);
  lcd.setCursor(0,1);   //posiciona cursor na coluna 0 linha 1 do LCD
  lcd.print("Tudo Bem???"); //imprime a string no display do LCD.
  delay(2000);
  lcd.clear();
  lcd.print("Quer aprender");
  lcd.setCursor(0,1);
  lcd.print("este projeto?");
  delay(4000);
  lcd.clear();
  lcd.print("www.ComoFazerAsCoisas.com.br");
  delay(1000);
  //Rolando o display para a esquerda 12 vezes
  for (int i = 0; i < 12; i++) {
    lcd.scrollDisplayLeft();
    delay(600);
  }
  delay(1000);







}




}
