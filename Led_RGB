void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop(){
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);
  analogWrite(9, r);
  analogWrite(10, g);
  analogWrite(11, b);
  
  Serial.print ("r: ");
  Serial.println (r);
  Serial.print ("g: ");
  Serial.println (g);
  Serial.print ("b: ");
  Serial.println (b);
  delay (500);
}
