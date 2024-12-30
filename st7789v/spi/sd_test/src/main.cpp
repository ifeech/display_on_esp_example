#include <SPI.h>

#include <FS.h>
#include <SD.h>

#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

// JPEG decoder library
#include <JPEGDecoder.h>

#define TFT_CS 15 
#define SD_CS 5      // Пин Chip Select для SD-карты
// #define LED_PIN 22    // Пин для управления подсветкой

void setup() {
  delay(100);
  Serial.begin(115200);

  // Инициализация подсветки
  // pinMode(LED_PIN, OUTPUT);
  // analogWrite(LED_PIN, 155); // Максимальная яркость (0-255)

  // почему после перезапуска карта не активна?
  digitalWrite(TFT_CS, HIGH); // TFT screen chip select
  digitalWrite(SD_CS, HIGH); // SD card chips select, must use GPIO 5 (ESP32 SS)

  tft.begin();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);

  // Инициализация SD-карты
  if (!SD.begin(SD_CS, tft.getSPIinstance())) {
    tft.setCursor(10, 50);
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.println("SD Card Error!");
    Serial.println("SD Card initialization failed!");
    while (true);
  }

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("TFT Display OK!");
  tft.setCursor(10, 50);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("SD Card OK!");
  Serial.println("SD Card initialized.");
}

void loop() {
}