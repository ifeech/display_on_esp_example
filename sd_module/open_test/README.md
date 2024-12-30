# SD card test

SD Card Module

## Connecting the display to the esp32

| Display       | ESP32 |
|---------------|-------|
| VCC           | 3.3V  |
| GND           | GND   |
| SD_CS         | 5     |
| SD_SCK        | 18    |
| SD_MISO       | 19    |
| SD_MOSI       | 23    |

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
```

**to customize the settings to your screen:**

example
```
#define SPI_FREQUENCY  40000000
#define SPI_READ_FREQUENCY  20000000
```