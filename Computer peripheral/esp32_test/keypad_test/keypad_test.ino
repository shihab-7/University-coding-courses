//#include <Keypad.h>
//const byte ROWS = 4;
//const byte COLS = 4;
//
//char keys[ROWS][COLS] = {
//  {'1','4','7','*'},
//  {'2','5','8','0'},
//  {'3','6','9','#'},
//  {'A','B','C','D'}
//};
//
//byte rowPins[ROWS] = {19, 18, 5, 17};    
//byte colPins[COLS] = {15, 21, 4, 16};
//
//Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
//
//void setup() {
//  Serial.begin(115200);
//  Serial.println("Keypad Test Ready");
//  pinMode(27,OUTPUT);
//}
//
//void loop() {
//  char key = keypad.getKey();
//  if (key) {
//    digitalWrite(27,1);
//    delay(5);
//    digitalWrite(27,0);
//    for (int row = 0; row < ROWS; row++) {
//      for (int col = 0; col < COLS; col++) {
//        if (keys[row][col] == key) {
//          Serial.print("Key Pressed: ");
//          Serial.print(key);
//          Serial.print("  [Row: ");
//          Serial.print(row);
//          Serial.print(", Col: ");
//          Serial.print(col);
//          Serial.println("]");
//        }
//      }
//    }
//  }
//}

#include <Keypad.h>

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

const int ledPin = 27;

void setup() {
  Serial.begin(115200);
  Serial.println("Keypad Test Ready");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 1);  // LED initially off
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // Blink the LED
    Serial.print("Key Pressed: ");
    Serial.println(key);
    
    digitalWrite(ledPin, 1);
    delay(200);
       
  }
  digitalWrite(ledPin, 0);
}
