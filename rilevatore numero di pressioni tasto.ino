//sketch che misura il numero di click nell'arco di una finestra di 2 secondi
bool conteggio;
bool tasto;
bool prev_tasto;

int n_pressioni;
long t0;
const int finestra = 2000;
void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  tasto = digitalRead(7);
  if(!conteggio){
    n_pressioni = 0;
    conteggio = true;
    t0 = millis();
    Serial.println("start conteggio");
  }
  if(!prev_tasto && tasto) prev_tasto = tasto; //se prev_trasto=false e tasto=high allora prev_tasto=high

  if(prev_tasto && !tasto){ //rilascio del pulsante
     n_pressioni ++; 
     /*
     per vedere tale valore devo uscire dall'if se tengo premuto il tasto il n_pressioni sarà = a 0
     quando rilascierò il pulsante diventerà 0+1=1
     */
     prev_tasto = tasto;
     
  }
  
  if (conteggio && ((millis() - t0) > finestra)){
    conteggio = false;
    
    Serial.print("numero di click=");
    Serial.println(n_pressioni);
    Serial.println("---------------------");
  }
  
}
