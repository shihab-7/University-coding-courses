int a=2,b=4;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
}

void loop() {
  digitalWrite(a,HIGH);
  delay(1000);
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  delay(1000);
  digitalWrite(b,LOW);
  delay(1000);
}
