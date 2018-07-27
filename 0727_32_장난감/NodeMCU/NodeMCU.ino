#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "e5be49c8db504a6994873ae1f5cdde77";

char ssid[] = "LG U+04";
char pass[] = "";

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

