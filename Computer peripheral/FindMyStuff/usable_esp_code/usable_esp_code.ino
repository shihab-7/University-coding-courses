#include <Keypad.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// WiFi credentials
const char* ssid = "No_internet";
const char* password = "(CSE_904)";

// Server URLs
const char* userOtpURL = "http://192.168.0.105:8000/api/esp32/verify-user-otp/";
const char* adminPasswordURL = "http://192.168.0.105:8000/api/esp32/verify-admin-password/";

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
const int led_pin3 = 33;

//password matching logics
String enteredOTP = "";
const int maxUserOTPLength = 5;  // User OTP is 5 digits
const int maxAdminPasswordLength = 3;  // Admin password is 3 digits
bool vaultOpen = false;
unsigned long openTime = 0;
const unsigned long openDuration = 10000;

bool is_empty = false;
bool is_filled = false;

void setup() {
//  Serial.begin(115200);
//  Serial.println("Keypad Test Ready");
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2 , OUTPUT);
  pinMode(led_pin3 , OUTPUT);
  digitalWrite(led_pin1, 0);
  digitalWrite(led_pin2, 0);
  digitalWrite(led_pin3, 0);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
//  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
//    Serial.print(".");
  }
//  Serial.println();
//  Serial.println("WiFi connected!");
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
  
  //servo section
//  Serial.println("Attaching servos...");
  lock_servo1.attach(servoPin1);
  lock_servo2.attach(servoPin2);
}

void loop() {
  char key = keypad.getKey();
  
  //password validation
  if (key) {
//    Serial.print("Key Pressed: ");
//    Serial.println(key);
    digitalWrite(led_pin1, 1);
    
    if (key >= '0' && key <= '9') 
    {
      // Limit input to maxUserOTPLength
      if (enteredOTP.length() < maxUserOTPLength) 
      {
        enteredOTP += key;
//        Serial.print("OTP: ");
        for (int i = 0; i < enteredOTP.length(); i++) 
        {
//          Serial.print("*");
        }
//        Serial.println();
        // Auto-submit only for 5-digit user OTP
        if (enteredOTP.length() == maxUserOTPLength) {
          verifyOTP(enteredOTP);
          enteredOTP = "";
        }
        // For admin password (3 digits), require manual submit with '#'
      }
    }
    else if (key == '*') 
    {
      enteredOTP = "";
//      Serial.println("OTP cleared");
    }
    else if (key == '#') 
    {
      if (enteredOTP.length() > 0) 
      {
//        Serial.println("Submitting code: " + enteredOTP);
        verifyOTP(enteredOTP);
        enteredOTP = "";
      }
    }
  }
  
  if (vaultOpen && (millis() - openTime > openDuration)) 
  {
    close_vault();
  }

  delay(200);
  digitalWrite(led_pin1, 0);
  
  if(is_empty == true)
  {
    digitalWrite(led_pin3, 1);
  }
  else
  {
    digitalWrite(led_pin3, 0);
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
//  Serial.println("Unlocking vault for 10 seconds...");
  lock_servo2.write(unlock_position);
  delay(2000);
  vaultOpen = true;
  lock_servo1.write(open_position);
  openTime = millis();
}
void close_vault()
{
//  Serial.println("Closing vault...");
  lock_servo1.write(close_position);
  delay(2000);
  lock_servo2.write(lock_position);
  vaultOpen = false;
}
void verifyOTP(String otp) {
  if (otp.length() > 0) {
//    Serial.println("Verifying code: " + otp);

    if (otp.length() == 5) {
      verifyUserOTP(otp);
    }
    else if (otp.length() == 3) {
      verifyAdminPassword(otp);
    }
    else {
//      Serial.println("Invalid code length. Use 5 digits for user OTP or 3 digits for admin password.");
    }
  } else {
//    Serial.println("Something went wrong");
  }
}

void verifyUserOTP(String otp) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(userOtpURL);
    http.addHeader("Content-Type", "application/json");
    
    //JSON payload
    DynamicJsonDocument doc(1024);
    doc["otp_code"] = otp;
    
    String requestBody;
    serializeJson(doc, requestBody);
    
//    Serial.println("Verifying User OTP: " + otp);
    
    int httpResponseCode = http.POST(requestBody);
    
    if (httpResponseCode > 0) {
      String response = http.getString();
//      Serial.println("Response: " + response);
      
      // Parse response
      DynamicJsonDocument responseDoc(1024);
      deserializeJson(responseDoc, response);
      
      if (httpResponseCode == 200 && responseDoc["success"]) {
        // User verified successfully
        String message = responseDoc["message"];
        String itemName = responseDoc["item_name"];
        
//        Serial.println("Ok " + message);
//        Serial.println("Item: " + itemName);
        
        // User collected item
        is_empty = true;
        is_filled = false;
        open_vault();
      } else {
        String error = responseDoc["error"];
//        Serial.println("User OTP: " + error);
      }
    } else {
//      Serial.println("Error: HTTP " + String(httpResponseCode));
    }
    
    http.end();
  } else {
//    Serial.println("WiFi not connected");
  }
}

void verifyAdminPassword(String password) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(adminPasswordURL);
    http.addHeader("Content-Type", "application/json");
    
    // Create JSON payload
    DynamicJsonDocument doc(1024);
    doc["password"] = password;
    
    String requestBody;
    serializeJson(doc, requestBody);
    
//    Serial.println("Verifying Admin Password: " + password);
    
    int httpResponseCode = http.POST(requestBody);
    
    if (httpResponseCode > 0) {
      String response = http.getString();
//      Serial.println("Response: " + response);
      
      // Parse response
      DynamicJsonDocument responseDoc(1024);
      deserializeJson(responseDoc, response);
      
      if (httpResponseCode == 200 && responseDoc["success"]) {
        // Admin verified successfully
        String message = responseDoc["message"];
        
//        Serial.println("Ok " + message);
        
        // Admin refilled vault
        is_empty = false;
        is_filled = true;
        open_vault();
      } else {
        String error = responseDoc["error"];
//        Serial.println("Admin Password: " + error);
      }
    } else {
//      Serial.println("Error: HTTP " + String(httpResponseCode));
    }
    
    http.end();
  } else {
//    Serial.println("WiFi not connected");
  }
}
