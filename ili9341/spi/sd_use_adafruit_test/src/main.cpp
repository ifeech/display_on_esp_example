#include <Arduino.h>

//Display and SD card
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_DC 16
#define TFT_CS 15
#define TFT_BACKLIGHT 4
#define TFT_MOSI 23
#define TFT_CLK 18
#define TFT_RST 17
#define TFT_MISO 19

#include <SD.h>
#define SD_CS 5

#define RST_PIN -1

// create the display object
//Adafruit_ILI9341 Display = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
Adafruit_ILI9341 Display(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  delay(100);
  Serial.begin(115200);

#if defined(TFT_BACKLIGHT)
  pinMode(TFT_BACKLIGHT, OUTPUT);
  // digitalWrite(TFT_BACKLIGHT, HIGH);
  analogWrite(TFT_BACKLIGHT, 64);
#endif

  // почему после перезапуска карта не активна?
  digitalWrite(TFT_CS, HIGH); // TFT screen chip select
  digitalWrite(SD_CS, HIGH); // SD card chips select, must use GPIO 5 (ESP32 SS)

  Display.begin();
  Display.fillScreen(0x0000);
  Display.setRotation(1);

  SPI.begin(TFT_CLK /* CLK */, TFT_MISO /* D0/MISO */, TFT_MOSI /* CMD/MOSI */);
  // Инициализация SD-карты
  if (!SD.begin(SD_CS, SPI)) {
    Display.setCursor(10, 50);
    Display.setTextColor(0xF800, 0x0000);
    Display.println("SD Card Error!");
    Serial.println("SD Card initialization failed!");
    while (true);
  }

  Display.setTextColor(0xFFFF, 0x0000);
  Display.setTextSize(2);
  Display.setCursor(10, 10);
  Display.println("TFT Display OK!");
  Display.setCursor(10, 50);
  Display.setTextColor(0x07E0, 0x0000);
  Display.println("SD Card OK!");
  Serial.println("SD Card initialized.");
}

void loop() {
}