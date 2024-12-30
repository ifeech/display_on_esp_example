# SD card built into the display test

## Connecting the display to the esp32

| Display       | ESP32 |
|---------------|-------|
| VCC           | 3.3V  |
| GND           | GND   |
| LED           | 4     |
| TFT_MISO      | 19    |
| SD_MISO       | 19    |
| TFT_MOSI      | 23    |
| SD_MOSI       | 23    |
| TFT_SCLK      | 18    |
| SD_SCLK       | 18    |
| TFT_CS        | 15    |
| TFT_DC        | 16    |
| TFT_RST       | 17    |
| SD_CS         | 5     |

## TFT_eSPI

**User_Setup.h:**

```
#define USER_SETUP_INFO "User_Setup"

#define ST7789_DRIVER

#define TFT_INVERSION_ON

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT
```

**to customize the settings to your screen:**

example
```
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
```

**User_Setup_Select.h**

Uncomment the line: ``#include <User_Setups/Setup23_TTGO_TM.h>``

**User_Setups/Setup23_TTGO_TM.h:**

```
#define USER_SETUP_ID 23

#define ST7789_DRIVER

#define TFT_SDA_READ // Read from display, it only provides an SDA pin
#define TFT_MISO 19  // Must be defined even though it is not used
#define TFT_MOSI 23  // Connected to display SDA line
#define TFT_SCLK 18
#define TFT_CS   15
#define TFT_DC   16
#define TFT_RST  17
#define TFT_BL   4
#define TOUCH_CS -1

#define TFT_WIDTH  240
#define TFT_HEIGHT 320

#define TFT_RGB_ORDER TFT_RGB  // Colour order Red-Green-Blue
//#define TFT_RGB_ORDER TFT_BGR // Colour order Blue-Green-Red

//#define TFT_INVERSION_ON
#define TFT_INVERSION_OFF

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

//#define SPI_FREQUENCY  40000000     // This display also seems to work reliably at 80MHz
//#define SPI_FREQUENCY  80000000
#define SPI_READ_FREQUENCY  6000000 // 6 MHz is the maximum SPI read speed for the ST7789V
```