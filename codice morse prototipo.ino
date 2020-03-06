char *lettere [] = {".-", "-..."}; //a e b in morse 
const int ledpin = 13;
const int pausa = 200;
void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read();
    if(ch >= 'a' && ch <= 'b'){ //per arduino 'a' equivale a 97 e 'b' 99...
      flashSequence(lettere[ch - 'a']); //ad es se ho inserito b mi andrà nella posizione 2 dell'array lettere
    }
  }

}

void flashSequence(char *sequence) { //incomincia leggere dalla prima posizione di b in morse ossia da -
  int i = 0;
  while (sequence[i] != '/0'){ //ultima cosa che legge arduino dopo ogni elemento dell'array
    codice(sequence [i]);
    i++;
  }
  delay (pausa * 4); //pausa tra le lettere
}

void codice(char simbolo){
  digitalWrite(ledpin, HIGH);
  if(simbolo == '.'){
    delay(pausa);
  }else{
    delay(pausa * 3);
  }
  digitalWrite(ledpin, LOW);
  delay(pausa); //pausa tra un simbolo e l'altro
}
