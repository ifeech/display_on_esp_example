# Touch screen test

## Connecting the display to the esp32

| Display       | ESP32 |
|---------------|-------|
| VCC, LED      | 3.3V  |
| GND           | GND   |
| TFT_MISO      | 19    |
| T_DO          | 19    |
| TFT_MOSI      | 23    |
| T_DIN         | 23    |
| TFT_SCLK      | 18    |
| T_SCLK        | 18    |
| TFT_CS        | 15    |
| TFT_DC        | 2     |
| TFT_RST       | 4     |
| T_CS          | 21    |
| T_IRQ         | 16    |

T_IRQ - it is not necessary to connect - 0 appears on the pin when touching the touch screen, it is useful for example to wake the controller from sleep

## TFT_eSPI

**User_Setup.h:**

```
#define USER_SETUP_INFO "User_Setup"

#define ILI9341_DRIVER       // Generic driver for common displays

#define TOUCH_CS 21     // Chip select pin (T_CS) of touch screen

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST   4  // Reset pin (could connect to RST pin)

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

#define USE_HSPI_PORT
```

**to customize the settings to your screen:**

example
```
#define TFT_WIDTH  240 // ST7789 240 x 240 and 240 x 320
#define TFT_HEIGHT 320 // ST7789 240 x 320

#define SPI_FREQUENCY  55000000 // STM32 SPI1 only (SPI2 maximum is 27MHz)
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY  2500000
```