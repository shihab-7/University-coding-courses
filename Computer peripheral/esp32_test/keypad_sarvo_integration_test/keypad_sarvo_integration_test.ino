#include <Keypad.h>
#include <ESP32Servo.h>

Servo lock_servo1;
Servo lock_servo2;
const int servoPin1 = 12;
const int servoPin2 = 13;
const int lock_position = 0;
const int close_position = 0;
const int unlock_position = 90;
const int open_position = 180;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};
byte rowPins[ROWS] = {19, 18, 5, 17};    
byte colPins[COLS] = {15, 21, 4, 16};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int led_pin1 = 27;
const int led_pin2 = 26;

//password matching logics
String enteredOTP = "";
const int maxOTPLength = 5;
bool vaultOpen = false;
unsigned long openTime = 0;
const unsigned long openDuration = 10000;

bool is_empty = false;
bool is_filled = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Keypad Test Ready");
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2 , OUTPUT);
  digitalWrite(led_pin1, 0);
  digitalWrite(led_pin2, 0);
  //sarvo section
  Serial.println("Attaching servos...");
  lock_servo1.attach(servoPin1);
  lock_servo2.attach(servoPin2);
}

void loop() {
  char key = keypad.getKey();
  
  //password validation
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
    digitalWrite(led_pin1, 1);
    
    if (key >= '0' && key <= '9') 
    {
      if (enteredOTP.length() < maxOTPLength) 
      {
        enteredOTP += key;
        Serial.print("OTP: ");
        for (int i = 0; i < enteredOTP.length(); i++) 
        {
          Serial.print("*");
        }
        Serial.println();
        if (enteredOTP.length() == maxOTPLength)
        {
          verifyOTP(enteredOTP);
          enteredOTP = "";
        }
      }
    }
    else if (key == '*') 
    {
      enteredOTP = "";
      Serial.println("OTP cleared");
    }
    else if (key == '#') 
    {
      if (enteredOTP.length() > 0) 
      {
        verifyOTP(enteredOTP);
        enteredOTP = "";
      }
    }
  }
  
  //close vault after 10 seconds
  if (vaultOpen && (millis() - openTime > openDuration)) 
  {
    close_vault();
  }
  delay(200);
  digitalWrite(led_pin1, 0);
  
  if(is_empty == true)
  {
    digitalWrite(led_pin1, 1);
  }
  else
  {
    digitalWrite(led_pin1, 0);
  }
  if(is_filled == true)
  {
    digitalWrite(led_pin2, 1);
  }
  else
  {
    digitalWrite(led_pin2, 0);
  }
}

void open_vault()
{
  Serial.println("Unlocking vault for 10 seconds...");
  lock_servo2.write(unlock_position);
  delay(2000);
  vaultOpen = true;
  lock_servo1.write(open_position);
  openTime = millis();
}
void close_vault()
{
  Serial.println("Closing vault...");
  lock_servo1.write(close_position);
  delay(2000);
  lock_servo2.write(lock_position);
  vaultOpen = false;
}
void verifyOTP(String otp) {
  
    
    if (otp.length() > 0) 
    {
      //user collect things and update empty status
      if (otp == "12345") 
      {
        Serial.println("Verification successful");
        is_empty = true;
        is_filled = false;    
        open_vault();
      } 
      //admin reset empty status and put things inside
      else if(otp == "555")
      {
        is_empty = false;
        is_filled = true;
        open_vault();
      }
      else 
      {
        Serial.println("Verification failed");
      }
    } 
    else
    {
      Serial.println("Something went wrong");
    }
 }
