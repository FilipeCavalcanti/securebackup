/*  Feira de Engenharia Elétrica 2015 - FEE UFPB
    Software para controle de segurança de uma casa.
    Criado e mantido pelos alunos Vinícius Marinho, Matheus Duarte, Rivaldo Ferreira
    e pelos orientadores Filipe Cavalcanti e Marcelo Lira.

    João Pessoa, setembro de 2015.

*/

const int buzzer = 2;
const int ir = 4;
const int relay = 7;
int detect;



void setup(){
  pinMode(buzzer, OUTPUT);    //Buzzer como saída
  pinMode(ir, INPUT);         //Infrared como entrada
  pinMode(relay, OUTPUT);     //Relé como saída
  Serial.begin(9600);
}


void loop(){
  detect = digitalRead(ir);   //Detecta o estado do sensor IR
  if (detect==0){
    digitalWrite(relay, HIGH);    //Ative o relay
    Serial.println("Detectado");
    tone(buzzer,1500);    //Toca alarme
    delay(70);
    noTone(buzzer);
    delay(70);
  }
  else
    delay(500);
    digitalWrite(relay, LOW);
}
