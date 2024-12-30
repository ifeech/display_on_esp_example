#include <TFT_eSPI.h>  // Подключение библиотеки TFT_eSPI
#include <JPEGDecoder.h>
#include <SD.h>        // Подключение библиотеки для работы с SD-картой

#define FILENAME "/image.jpg"

TFT_eSPI tft = TFT_eSPI(); // Создаем объект для дисплея

#define SD_CS 5      // Пин Chip Select для SD-карты
#define LED_PIN 21    // Пин для управления подсветкой


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
    /*if (xpos + imgWidth > tft.width() || ypos + imgHeight > tft.height()) {
      Serial.println("Изображение не умещается на экране!");
      jpegFile.close();
      return;
    }*/

    tft.setRotation(1);

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
  Serial.begin(115200);

  // Инициализация подсветки
  pinMode(LED_PIN, OUTPUT);
  analogWrite(LED_PIN, 155); // Максимальная яркость (0-255)

  // Инициализация дисплея
  // tft.init();
  // tft.setRotation(1);
  // tft.fillScreen(TFT_BLACK);
  // tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // tft.setTextSize(2);
  // tft.setCursor(10, 10);
  // tft.println("TFT Display OK!");

  // digitalWrite(15, HIGH); // TFT screen chip select
  // digitalWrite(5, HIGH); // SD card chips select, must use GPIO 5 (ESP32 SS)

  tft.begin();

  // Инициализация SD-карты
  if (!SD.begin(SD_CS, tft.getSPIinstance())) {
    tft.setCursor(10, 50);
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.println("SD Card Error!");
    Serial.println("SD Card initialization failed!");
    while (true);
  }

  Serial.println("SD Card initialized.");

  // Загрузка и отображение изображения
  displayJPEG(FILENAME, 0, 0);
}

void loop() {
}