 int matrice [4][4]{
  {3, 5, 6, 8},
  {3, 5, 6, 8},
  {3, 5, 6, 8},
  {3, 5, 6, 8}
};
void setup() {
  Serial.begin (9600);
  for (int r = 0, r<4, r++){
    for(int c = 0, c<4, c++){
      int cella = matrice[r][c];
      Serial.print(cella);
      Serial.print(" ");
    }
    Serial.println(" ");
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
