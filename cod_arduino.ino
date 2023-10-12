const byte ledAzul = 4;
const byte ledVerde = 5;
const byte ledVermelho = 6;

const byte interrupPin2 = 2;
const byte interrupPin3 = 3;

byte i;

/*
É recomendado declarar como volatile quaisquer variavel que seja modificada dentro
da função associada a interupção

exemplo: volatile byte state = LOW;
*/

void setup(){
  Serial.begin(9600);
  
  pinMode(ledAzul,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledVermelho,OUTPUT);
  
  /*
  Parametros que podem ser usados para configurar as interrupções
  
  LOW acionar a interrupção quando o estado do pino for LOW
  CHANGE acionar a interrupção quando o sempre estado do pino mudar
  RISING acionar a interrupção quando o estado do pino for de LOW para HIGH apenas
  FALLING acionar a interrupção quando o estado do pino for de HIGH para LOW apenas
  
  Placas Due, Zero e MKR1000 suportam também:
  HIGH acionar a interrupção quando o estado do pino for HIGH.
  */

  attachInterrupt(digitalPinToInterrupt(interrupPin2), execaoUm, RISING);
  attachInterrupt(digitalPinToInterrupt(interrupPin3), execaoDois, RISING);
}

void loop(){
  Serial.println("antes do looping");
  for(i=0;i<=4;i++){
    Serial.println("dentro do looping");
    digitalWrite(ledVermelho,HIGH);
    delay(250);
    digitalWrite(ledVermelho,LOW);
    delay(250);
  }
  Serial.println("saiu do looping");
}

void execaoUm(){
  Serial.println("execao um");
    digitalWrite(ledVerde,LOW);
     digitalWrite(ledAzul,HIGH);
}

void execaoDois(){
  Serial.println("execao dois");
    digitalWrite(ledAzul,LOW);
     digitalWrite(ledVerde,HIGH);
}