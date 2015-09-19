/*  Feira de Engenharia Elétrica 2015 - FEE UFPB
    Software para controle de segurança de uma casa.
    Criado e mantido pelos alunos Vinícius Marinho, Matheus Duarte, Rivaldo Ferreira
    e pelos orientadores Filipe Cavalcanti e Marcelo Lira.

    João Pessoa, setembro de 2015.

*/

const int buzzer = 2;
const int ir = 4;

int detect;



void setup(){
  pinMode(buzzer,OUTPUT);
  pinMode(ir,INPUT);
  Serial.begin(9600);
}


void loop(){
  detect = digitalRead(ir);
  if (detect==0){
    Serial.println("Detectado");
    tone(buzzer,1500);
    delay(70);
    noTone(buzzer);
    delay(70);
  }
  else
    delay(500);
}
