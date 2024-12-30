# Output image from the sd card built into the display

Set ``FILENAME`` to the name of the image file on the SD card.

## Connecting the display to the esp32

| Display     | ESP32 |
|-------------|-------|
| VCC         | 3.3V  |
| GND         | GND   |
| TFT_CS      | 33    |
| TFT_DC      | 15    |
| TFT_RST     | 32    |
| TFT_WR      | 4     |
| TFT_RD      | 2     |
| SD_CS       | 5     |
| ----------- | ----  |
| TFT_D0      | 12    |
| TFT_D1      | 13    |
| TFT_D2      | 26    |
| TFT_D3      | 25    |
| TFT_D4      | 17    |
| TFT_D5      | 16    |
| TFT_D6      | 27    |
| TFT_D7      | 14    |

## TFT_eSPI

**User_Setup.h:**

```
#define USER_SETUP_INFO "User_Setup"

#define ILI9341_DRIVER       // Generic driver for common displays

#define TFT_PARALLEL_8_BIT

// The ESP32 and TFT the pins used for testing are:
#define TFT_CS   33  // Chip select control pin (library pulls permanently low
#define TFT_DC   15  // Data Command control pin - must use a pin in the range 0-31
#define TFT_RST  32  // Reset pin, toggles on startup

#define TFT_WR    4  // Write strobe control pin - must use a pin in the range 0-31
#define TFT_RD    2  // Read strobe control pin

#define TFT_D0   12  // Must use pins in the range 0-31 for the data bus
#define TFT_D1   13  // so a single register write sets/clears all bits.
#define TFT_D2   26  // Pins can be randomly assigned, this does not affect
#define TFT_D3   25  // TFT screen update performance.
#define TFT_D4   17
#define TFT_D5   16
#define TFT_D6   27
#define TFT_D7   14

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
#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY  2500000
```