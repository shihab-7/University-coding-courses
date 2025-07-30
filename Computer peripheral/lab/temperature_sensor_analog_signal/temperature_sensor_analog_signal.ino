int temp = A1;
int motor = 12;
int sensor;

void setup() {
  Serial.begin(9600);
  pinMode(temp,INPUT);
  pinMode(motor,OUTPUT);
}

void loop() {
  sensor = analogRead(temp);
  sensor = (sensor * 500) / 1024;
  if(sensor > 25)
  {
    digitalWrite(motor,HIGH);
    Serial.print("temperature is ");
    Serial.print(sensor);
    Serial.println(" motor is running...");  
  }
  else
  {
    digitalWrite(motor,LOW);
    Serial.print("temperature is ");
    Serial.print(sensor);
    Serial.println(" motor is off");
  }
}
