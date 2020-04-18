long attivita = 10000; //tempo attività di flusso dell'acqua (10secondi)
long t = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  bool ferma = false;
  if (digitalRead(2) == HIGH && ferma == false){
    digitalWrite(3, HIGH);
    ferma = !ferma;
    if (digitalRead(2) == HIGH && ferma == true){ //chiude elettrovalvola prima della fine del ciclo nel caso rischiacci il pulsante
      digitalWrite(3, LOW);
    }
     if((millis() - t) > attivita ){
      digitalWrite(3, LOW);
      t = millis();
    }
  }
}
