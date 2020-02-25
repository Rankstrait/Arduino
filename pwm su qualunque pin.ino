int c = 0;
int i = 1;
int MAX = 100;
int sgn = 1;

void setup() {
  pinMode (13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  c++;
  digitalWrite(13, HIGH);
  delayMicroseconds(i);
  digitalWrite(13, LOW);
  delayMicroseconds(MAX - i);

  if ((c%5) == 0)  i= i + sgn;
  if (i >= 100) sgn = !sgn; // -1
  if (i <=0) {
    sgn = !sgn;
    i = 1;
  }

}
