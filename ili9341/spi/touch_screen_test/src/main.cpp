#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
 
TFT_eSPI tft = TFT_eSPI();
 
// Пины сенсорного экрана
#define XPT2046_IRQ 16   // T_IRQ
#define XPT2046_CS 21    // T_CS
 
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
 
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2
 
// Координаты сенсорного экрана: (x, y) и давление (z)
int x, y, z;
 
// Вывод информации о сенсорном экране о X, Y и давлении (Z) в мониторе последовательного порта
void printTouchToSerial(int touchX, int touchY, int touchZ) {
  Serial.print("X = ");
  Serial.print(touchX);
  Serial.print(" | Y = ");
  Serial.print(touchY);
  Serial.print(" | Pressure = ");
  Serial.print(touchZ);
  Serial.println();
}
 
// Вывод информации о сенсорном экране о X, Y и давлении (Z) на TFT дисплее
void printTouchToDisplay(int touchX, int touchY, int touchZ) {
  // Очистка экрана TFT
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  
 
  int centerX = SCREEN_WIDTH / 2;
  int textY = 80;
 
  String tempText = "X = " + String(touchX);
  tft.drawCentreString(tempText, centerX, textY, FONT_SIZE);
 
  textY += 20;
  tempText = "Y = " + String(touchY);
  tft.drawCentreString(tempText, centerX, textY, FONT_SIZE);
 
  textY += 20;
  tempText = "Pressure  = " + String(touchZ);
  tft.drawCentreString(tempText, centerX, textY, FONT_SIZE);
}
 
void setup() {
  Serial.begin(9600);
 
  // Начать использовать SPI для сенсорного экрана и инициализировать сенсорный экран
  touchscreen.begin();
  // Установить поворот сенсорного экрана в ландшафтный режим
  // Примечание: на некоторых дисплеях сенсорный экран может быть перевернут, поэтому может потребоваться установить поворот в 3: touchscreen.setRotation(3);
  touchscreen.setRotation(1);

  // Начать использовать TFT дисплей
  tft.init();
  // Установить поворот TFT дисплея в ландшафтный режим
  tft.setRotation(1);
 
  // Очистить экран перед записью на него
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  
  // Установить координаты X и Y для центра дисплея
  int centerX = SCREEN_WIDTH / 2;
  int centerY = SCREEN_HEIGHT / 2;
 
  tft.drawCentreString("Hello, world!", centerX, 30, FONT_SIZE);
  tft.drawCentreString("Touch screen to test", centerX, centerY, FONT_SIZE);
}
 
void loop() {
  // Проверка, коснулся ли кто-то сенсорного экрана, и вывод информации о X, Y и давлении (Z) на TFT дисплей и в монитор последовательного порта
  if (touchscreen.touched()) {
    // Получение координат сенсорного экрана
    TS_Point p = touchscreen.getPoint();
    // Калибровка координат сенсорного экрана с помощью функции map к правильной ширине и высоте
    x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
    y = map(p.y, 240, 3800, 1, SCREEN_HEIGHT);
    z = p.z;
 
    printTouchToSerial(x, y, z);
    printTouchToDisplay(x, y, z);
 
    delay(100);
  }
}