char *lettere [] = {".-", "-...", "– · – ·", "– · ·", ".", "· · – ·", " – – ·", " · · · ·", "· ·", 
"· – – –", " – · –", "· – · ·", "– –", "-.", "---", "· – – ·", " – – · –", ".-.", "· · ·" , "-", "· · –",
"· · · –", "· – –", " – · · –", " – · – –", "– – · ·" }; //alfabeto in morse 
const int ledpin = 13;
const int pausa = 500;
void setup() {
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char ch;
  if (Serial.available() > 0) {
    ch = Serial.read(); //Serial.read processa una lettera alla volta, questo è fondamentale per la creazione di un codice morse
    if(ch >= 'a' && ch <= 'z'){ //per arduino 'a' equivale a 97 e 'b' 98...
      flashSequence(lettere[ch - 'a']); //ad es se ho inserito b mi andrà nella posizione 1 dell'array lettere
      Serial.println(ch);
    }
  }
  
  delay(pausa*4); // pausa tra una parola e l'altra
}

void flashSequence(char *sequence) { //incomincia leggere dalla prima posizione di b in morse ossia da -
  int i = 0;
  while (sequence[i] !=  '\0'){ //ultima cosa che legge arduino dopo ogni elemento dell'array
    codice(sequence [i]);
    i++;
  }
  delay (pausa * 4); //pausa tra le lettere
}

void codice(char simbolo){
  digitalWrite(ledpin, HIGH);
  if(simbolo == '-'){
    delay(pausa * 3);
  }else{ //dev'essere per forza un '.'
    delay(pausa );
  }
  digitalWrite(ledpin, LOW);
  delay(pausa); //pausa tra un simbolo e l'altro
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
