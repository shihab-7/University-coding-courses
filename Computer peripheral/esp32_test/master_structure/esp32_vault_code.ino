#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Keypad.h>
#include <ESP32Servo.h>

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Server details
const char* serverURL = "http://your-django-server.com/api/verify-otp/";

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {19, 18, 5, 17};
byte colPins[COLS] = {16, 4, 2, 15};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Servo for lock mechanism
Servo lockServo;
const int servoPin = 12;
const int lockPosition = 0;    // Locked position
const int unlockPosition = 90; // Unlocked position

// Variables
String enteredOTP = "";
const int maxOTPLength = 5;
bool vaultOpen = false;
unsigned long openTime = 0;
const unsigned long openDuration = 10000;

void setup() {
  Serial.begin(115200);
  
  // Initialize servo
  lockServo.attach(servoPin);
  lockServo.write(lockPosition); // Start locked
  

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  Serial.println("Vault System Ready");
  Serial.println("Enter 5-digit OTP using keypad:");
}

void loop() {
  char key = keypad.getKey();
  
  // keypad input
  if (key) {
    Serial.println(key);
    
    if (key >= '0' && key <= '9') {
      if (enteredOTP.length() < maxOTPLength) {
        enteredOTP += key;
        Serial.print("OTP: ");
        for (int i = 0; i < enteredOTP.length(); i++) {
          Serial.print("*");
        }
        Serial.println();
        
        if (enteredOTP.length() == maxOTPLength) {
          verifyOTP(enteredOTP);
          enteredOTP = ""; // Reset
        }
      }
    }
    else if (key == '*') {
      enteredOTP = "";
      Serial.println("OTP cleared");
    }
    else if (key == '#') {
      if (enteredOTP.length() > 0) {
        verifyOTP(enteredOTP);
        enteredOTP = "";
      }
    }
  }
  
  //close vault after 10 seconds
  if (vaultOpen && (millis() - openTime > openDuration)) {
    closeVault();
  }
  
  delay(100);
}

void verifyOTP(String otp) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverURL);
    http.addHeader("Content-Type", "application/json");
    
    // Create JSON payload
    DynamicJsonDocument doc(1024);
    doc["otp_code"] = otp;
    
    String requestBody;
    serializeJson(doc, requestBody);
    
    Serial.println("Verifying OTP: " + otp);
    
    int httpResponseCode = http.POST(requestBody);
    
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);
      
      // Parse response
      DynamicJsonDocument responseDoc(1024);
      deserializeJson(responseDoc, response);
      
      if (httpResponseCode == 200) {
        // OTP verified successfully
        String message = responseDoc["message"];
        String itemName = responseDoc["item_name"];
        
        Serial.println("OK " + message);
        Serial.println("Item: " + itemName);
        
        openVault();
      } else {
        // OTP verification failed
        String error = responseDoc["error"];
        Serial.println("X " + error);
      }
    } else {
      Serial.println("Error: HTTP " + String(httpResponseCode));
    }
    
    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
}

void openVault() {
  Serial.println(" VAULT OPENING...");
  lockServo.write(unlockPosition);
  vaultOpen = true;
  openTime = millis();
  
  // Optional: Add LED, buzzer, or display feedback
  Serial.println("Vault will close automatically in 10 seconds");
}

void closeVault() {
  Serial.println(" VAULT CLOSING...");
  lockServo.write(lockPosition);
  vaultOpen = false;
  Serial.println("Vault secured. Ready for next OTP.");
}
