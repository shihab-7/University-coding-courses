#include <WiFi.h>

const char* ssid = "No_internet";
const char* password = "(CSE_904)";


void setup() {
  Serial.begin(115200);

  pinMode(4,OUTPUT);
  // Connect to WiFi
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
}

void loop() {
  delay(1000);
  if(WiFi.status()== WL_CONNECTED)
  {
    digitalWrite(4,1);
  }
  digitalWrite(4,0);
  delay(1000);
}
