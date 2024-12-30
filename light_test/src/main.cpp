#include <Arduino.h>

#define LED_PIN 2

#define BLINK_DELAY 5000

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(BLINK_DELAY);
    digitalWrite(LED_PIN, LOW);
    delay(BLINK_DELAY);
}