# Output image from the sd card built into the display

Set ``FILENAME`` to the name of the image file on the SD card.

## Connecting the display to the esp32

| Display       | ESP32 |
|---------------|-------|
| VCC           | 3.3V  |
| GND           | GND   |
| LED           | 21    |
| TFT_MISO      | 19    |
| SD_MISO       | 19    |
| TFT_MOSI      | 23    |
| SD_MOSI       | 23    |
| TFT_SCLK      | 18    |
| SD_SCLK       | 18    |
| TFT_CS        | 15    |
| TFT_DC        | 2     |
| TFT_RST       | 4     |
| SD_CS         | 5     |

## TFT_eSPI

**User_Setup.h:**

```
#define USER_SETUP_INFO "User_Setup"

#define ILI9341_DRIVER       // Generic driver for common displays

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST   4  // Reset pin (could connect to RST pin)

#define SD_CS   5  // Chip select control pin

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
//#define LOAD_FONT8N
#define LOAD_GFXFF

#define SMOOTH_FONT
```

**to customize the settings to your screen:**

example
```
#define TFT_HEIGHT 320 // ST7789 240 x 320

#define SPI_FREQUENCY  40000000
#define SPI_READ_FREQUENCY  20000000
```