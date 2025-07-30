#include <ESP32Servo.h>

Servo lock_servo1;
Servo lock_servo2;

const int servoPin1 = 12; // First servo signal pin
const int servoPin2 = 13; // Second servo signal pin

const int lock_position = 0;
const int close_position = 0;
const int unlock_position = 90;
const int open_position = 180;


void setup() {
  Serial.begin(115200);
  Serial.println("Attaching servos...");

  lock_servo1.attach(servoPin1);
  lock_servo2.attach(servoPin2);

//  Serial.println("Locking both...");
//  lock_servo1.write(lock_position);
//  lock_servo2.write(close_position);
}

void loop() {
  Serial.println("Unlocking both...");
  lock_servo1.write(unlock_position);
  lock_servo2.write(open_position);
  delay(1000);

  Serial.println("Locking both...");
  lock_servo1.write(lock_position);
  lock_servo2.write(close_position);
  delay(1000);
}
