int stato[3];
int rgb [3]= {11, 9, 10};
void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop(){
  for (int i=0; i<4; i++){
    stato[i] = random(0, 256);
  }
  for (int i=0; i<4; i++){
    analogWrite(rgb[i], stato[i]);
    delay(1000);
  }
  for (int i=0; i<4; i++){
    
    Serial.print(rgb[i]);
   
    Serial.println(stato [i]);
  }
  
}
