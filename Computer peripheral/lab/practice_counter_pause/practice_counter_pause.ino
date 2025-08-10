int segment_pins[]={13,12,11,10,9,8,7};
int left_display = 5;
int right_display = 4;
int count = 0;
unsigned long last_update = 0;
int current_digit = 0;
bool is_paused = false;
int button_pin = 2;

int digits[10][7]={
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

void setup() {
  pinMode(button_pin,INPUT_PULLUP);
  for(int i=0;i<7;i++)
  {
    pinMode(segment_pins[i],OUTPUT);
  }
  pinMode(left_display,OUTPUT);
  pinMode(right_display,OUTPUT);
}

void loop() {

  unsigned long current_time = millis();

  if(digitalRead(button_pin)==LOW) is_paused = true;
  else is_paused = false;
  delay(40);

  if(current_digit == 0)
  {
    display_digit(count/10,left_display);
    current_digit = 1;
  }
  else
  {
    display_digit(count%10,right_display);
    current_digit = 0;
  }

  if(!is_paused && (current_time - last_update >=1000))
  {
    count = (count+1)%100;
    last_update +=1000;
  }
}
void display_digit(int num, int digit_pin)
{
  digitalWrite(left_display,LOW);
  digitalWrite(right_display,LOW);
  delayMicroseconds(100);
  for(int i=0;i<7;i++)
  {
    digitalWrite(segment_pins[i],!digits[num][i]);
  }
  digitalWrite(digit_pin,HIGH);
}
