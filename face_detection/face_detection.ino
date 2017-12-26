#define SSID_WIFI "hogwarts"
#define PASSWORD_WIFI "11234566"
#define LOCK_PIN 5

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
String url = "http://e3109629.ngrok.io/person/enter";

void setup() {
  pinMode(LOCK_PIN, OUTPUT);
  
  Serial.begin(115200);

  WiFi.begin(SSID_WIFI, PASSWORD_WIFI);

  // Ожидание подключения
  Serial.println("Connecting to wifi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() { 
  http.begin(url); //HTTP
  
  int httpCode = http.GET();

  if(httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();

      if (payload == "true") {
        blink();
      }
      
      Serial.println(payload);
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();

  delay(500);
}


void blink() {
  digitalWrite(LOCK_PIN, HIGH);
  delay(500);
  digitalWrite(LOCK_PIN, LOW);
  delay(500);
  digitalWrite(LOCK_PIN, HIGH);
  delay(500);
  digitalWrite(LOCK_PIN, LOW);
  delay(500);
}

