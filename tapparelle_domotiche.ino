int dir = 0; // direzione rotazione
#define ENABLE 5 // enable motore 
#define DIRA 3 // senso rotazione
#define DIRB 4 // senso rotazione

void setup() {
pinMode(2, INPUT); //pulsante alza tapparelle
pinMode(3, INPUT); //pulsante abbassa tapparelle
pinMode(4, INPUT);//sensore fine corsa parte basculante
pinMode(5, INPUT);//sensore fine corsa parte poggiolo
pinMode(A0,INPUT);
pinMode(A1, INPUT);

//---set pin direction
pinMode(ENABLE,OUTPUT);
pinMode(DIRA,OUTPUT);
pinMode(DIRB,OUTPUT);



}

void loop() {
  int velocita;
  int luce = analogRead (A0); //legge valore da 0 a 1023 della luce sulla stanza
  if(luce > 500 or digitalRead(2) == HIGH){
      if(digitalRead(4) == HIGH){
        dir = 0;// senso antiorario, ossia tirare sù le tapparelle
        velocita = 255;
      }else {velocita = 0;
  }
  }
  if (luce <= 500 or digitalRead(3) == HIGH){
    if(digitalRead(5) == LOW){
    dir = 1; // senso orario, ossia tirare giù le tapparelle
    velocita = 255;
    }else {velocita = 0;
  }
  }
  analogWrite(ENABLE, velocita);
  digitalWrite(DIRA,dir); 
  digitalWrite(DIRB,!dir);
}
