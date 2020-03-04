void setup() {
  Serial.begin(9600);
  presentati("stefano");
  int n = somma(7, 9);
  Serial.print(n);
  Serial.println(" anni");

}

void loop() {
  
}

void presentati (String nome){ //void non mi restituisce nessun valore in questo caso si parla di procedure
  Serial.print("ciao mi chiamo ");
  Serial.print(nome);
  Serial.print(" ed ho:");
  


}
int somma (int n, int m){ //quà invece somma mi restituisce un valore dunque si parla di funzioni
  int res = n + m;
  return res;
  
}
