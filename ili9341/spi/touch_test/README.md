# Touch test

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