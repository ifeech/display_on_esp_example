#include <SD.h>
#include <SPI.h>

#define SD_CS 5  // Пин CS для SD-карты
#define SD_SCK 18   // Пин SCK
#define SD_MISO 19  // Пин MISO
#define SD_MOSI 23  // Пин MOSI

// Создание объекта SPI с определёнными пинами
SPIClass spi = SPIClass(VSPI); // Используем VSPI (пины можно указать вручную)


void setup() {
  delay(2000); // Задержка 2 секунды

  Serial.begin(9600);  
  
  // Настройка SPI с пользовательскими пинами
  spi.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);
  
  if (!SD.begin(SD_CS, spi)) {
    Serial.println("SD-карта не инициализирована. Проверьте соединения!");
    return;
  }
  
  Serial.println("SD-карта успешно инициализирована!");
}

void loop() {
  // Ничего не делать
}