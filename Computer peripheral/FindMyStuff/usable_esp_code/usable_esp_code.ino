#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SDA_PIN 23
#define SCL_PIN 22

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long pickTimerStart = 0;
bool showPickTimer = false;
bool showAdminWelcome = false;
int pickTimerSeconds = 10;
bool showTryAgain = false;
unsigned long tryAgainStart = 0;


// WiFi credentials
const char* ssid = "No_internet";
const char* password = "(CSE_904)";

// Server URLs
const char* userOtpURL = "https://findmystuff.onrender.com/api/esp32/verify-user-otp/";
const char* adminPasswordURL = "https://findmystuff.onrender.com/api/esp32/verify-admin-password/";

Servo lock_servo1;
Servo lock_servo2;
const int servoPin1 = 12;
const int servoPin2 = 13;
const int lock_position = 0;
const int close_position = 98;
const int unlock_position = 90;
const int open_position = 0;

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
  Wire.begin(SDA_PIN, SCL_PIN);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;);
  }

// dusplay setup
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,10);
  display.println("OLED Ready!");
  display.display();
  delay(1000);
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
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  //servo section
  lock_servo1.attach(servoPin1);
  lock_servo2.attach(servoPin2);
}

void loop() {
  // Show 'Try Again' message if needed
  if (showTryAgain) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 20);
    display.println("Try Again");
    display.display();
    if (millis() - tryAgainStart > 1500) {
      showTryAgain = false;
      enteredOTP = "";
    }
    return;
  }

  // Show pick timer after user verification
  if (showPickTimer) {
    int secondsLeft = pickTimerSeconds - (millis() - pickTimerStart)/1000;
    if (secondsLeft > 0) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0,10);
      display.println("Pick Item:");
      display.setTextSize(2);
      display.setCursor(0,30);
      display.print(secondsLeft);
      display.println("s...");
      display.display();
    } else {
      showPickTimer = false;
      vaultOpen = false;
      enteredOTP = "";
    }
    return;
  }

  // Show admin welcome
  if (showAdminWelcome) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0,20);
    display.println("Welcome");
    display.setCursor(0,40);
    display.println("Admin");
    display.display();
    delay(2000);
    showAdminWelcome = false;
    enteredOTP = "";
    return;
  }

  // Always show Enter OTP prompt when idle
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,10);
  display.println("Enter OTP:");
  display.setTextSize(2);
  display.setCursor(0,30);
  display.println(enteredOTP);
  display.display();

  //password validation
  char key = keypad.getKey();
  if (key) {
//    Serial.print("Key Pressed: ");
//    Serial.println(key);
    digitalWrite(led_pin1, 1);
    if (key >= '0' && key <= '9') {
      if (enteredOTP.length() < maxUserOTPLength) {
        enteredOTP += key;
        // Auto-submit only for 5-digit user OTP
        if (enteredOTP.length() == maxUserOTPLength) {
          verifyOTP(enteredOTP);
          enteredOTP = "";
        }
      }
    } else if (key == '*') {
      enteredOTP = "";
    } else if (key == '#') {
      if (enteredOTP.length() > 0) {
        verifyOTP(enteredOTP);
        enteredOTP = "";
      }
    }
  }

  if (vaultOpen && (millis() - openTime > openDuration)) {
    close_vault();
  }

  delay(200);
  digitalWrite(led_pin1, 0);

  if(is_empty == true) {
    digitalWrite(led_pin3, 1);
  } else {
    digitalWrite(led_pin3, 0);
  }
  if(is_filled == true) {
    digitalWrite(led_pin2, 1);
  } else {
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
        is_empty = true;
        is_filled = false;
        open_vault();
        // Start pick timer on OLED
        showPickTimer = true;
        pickTimerStart = millis();
      } else {
        // Show 'Try Again' on OLED
        showTryAgain = true;
        tryAgainStart = millis();
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
        is_empty = false;
        is_filled = true;
        open_vault();
        // Show admin welcome on OLED
        showAdminWelcome = true;
      } else {
        // Show 'Try Again' on OLED
        showTryAgain = true;
        tryAgainStart = millis();
      }
    } else {
//      Serial.println("Error: HTTP " + String(httpResponseCode));
    }
    http.end();
  } else {
//    Serial.println("WiFi not connected");
  }
}
