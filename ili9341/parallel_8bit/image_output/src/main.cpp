#include <Arduino.h>
#include <TFT_eSPI.h>
#include <JPEGDecoder.h>
#include <SD.h>

#define FILENAME "/image.jpg"

#define SD_CS 5  // Установите пин Chip Select для SD-карты


TFT_eSPI tft = TFT_eSPI(); // Создаем объект TFT дисплея

// Функция для отображения изображения JPEG
void displayJPEG(const char *filename, int xpos, int ypos) {
  File jpegFile = SD.open(filename);
  if (!jpegFile) {
    Serial.println("Не удалось открыть файл изображения");
    return;
  }

  Serial.println("Файл изображения открыт успешно");

  // Декодируем файл JPEG
  if (JpegDec.decodeSdFile(jpegFile)) {
    Serial.println("Изображение успешно декодировано");

    // Получаем ширину и высоту изображения
    int16_t imgWidth = JpegDec.width;
    int16_t imgHeight = JpegDec.height;

    Serial.print("Ширина изображения: ");
    Serial.println(imgWidth);
    Serial.print("Высота изображения: ");
    Serial.println(imgHeight);

    // Проверка, умещается ли изображение на экране
    if (xpos + imgWidth > tft.width() || ypos + imgHeight > tft.height()) {
      Serial.println("Изображение не умещается на экране!");
      jpegFile.close();
      return;
    }

    // Отображаем изображение блоками
    uint16_t *pImg;
    uint16_t mcuWidth = JpegDec.MCUWidth;
    uint16_t mcuHeight = JpegDec.MCUHeight;
    uint16_t maxX = xpos + imgWidth;
    uint16_t maxY = ypos + imgHeight;

    // Перебираем все блоки MCU
    while (JpegDec.readSwappedBytes()) {
        pImg = JpegDec.pImage;  // Указатель на декодированные данные

        int mcuX = JpegDec.MCUx * mcuWidth + xpos;
        int mcuY = JpegDec.MCUy * mcuHeight + ypos;

        int mcuBlockWidth = (mcuX + mcuWidth <= maxX) ? mcuWidth : (maxX - mcuX);
        int mcuBlockHeight = (mcuY + mcuHeight <= maxY) ? mcuHeight : (maxY - mcuY);

        // Отображаем MCU блок
        if (mcuBlockWidth > 0 && mcuBlockHeight > 0) {
            tft.pushImage(mcuX, mcuY, mcuBlockWidth, mcuBlockHeight, pImg);
        }
    }
  } else {
    Serial.println("Не удалось декодировать изображение");
  }

  jpegFile.close();  // Закрываем файл после декодирования
}

void setup() {
  delay(100);
  Serial.begin(9600);

  tft.init();
  tft.setRotation(1); // Установим горизонтальную ориентацию
  tft.fillScreen(TFT_BLACK); // Очистим экран черным цветом

  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Белый текст на черном фоне
  tft.setCursor(10, 10);
  tft.println("Hello, ESP32!"); 
  
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card initialization failed!");
    tft.println("SD Card initialization failed!"); 
    return;
  } 
  
  // Загрузка и отображение изображения
  displayJPEG(FILENAME, 0, 0);
}

void loop() {
  // Ничего не делаем в loop
}