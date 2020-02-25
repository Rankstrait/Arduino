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

  if ((c%5) == 0)  i= i + sgn; //rallentatore
  if (i >= 100) sgn = !sgn; // quando i arriva a 100 (max durata per l' HIGH), sgn viene invertito così si ha il decadimento (fade del led)
  if (i <=0) {
    sgn = !sgn; //ricomincia la scalata fino ad arrivare a 100
    i = 1;
  }

}
