#include<Keypad.h>

const byte ROW=4;
const byte COL=4;
char keys[ROW][COL]={
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'A','0','=','+'}
};
byte row_pins[ROW]={13,12,11,10};
byte col_pins[COL]={9,8,7,6};
Keypad keypad = Keypad(makeKeymap(keys),row_pins,col_pins,ROW,COL);

int buzzer_pin = 2;
String password="";
void setup() {
  Serial.begin(9600);
  pinMode(buzzer_pin,OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  if(key)
  {
    password+=key;
    if(password=="1234" && (password.length()==4))
    {
      digitalWrite(buzzer_pin,HIGH);
      password="";
    }
    else if(password=="+")
    {
      digitalWrite(buzzer_pin,LOW);
      password=""; 
    }
    else
    {
      Serial.println("wrong password");
    }
  }
  delay(10);
}
