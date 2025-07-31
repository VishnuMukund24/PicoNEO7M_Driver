# PicoNEO7M_Driver
## NEO-7M GPS Reader for Raspberry Pi Pico

This project reads GPS data from a NEO-7M GPS module connected to a Raspberry Pi Pico using UART. It continuously prints out each NMEA sentence received over serial.

### Requirements

- Raspberry Pi Pico board
- NEO-7M GPS module
- CMake (v3.13+)
- GCC ARM toolchain (`arm-none-eabi-gcc`)
- Raspberry Pi Pico SDK
- `picotool` (optional, for flashing)
- USB cable and serial monitor (e.g., `minicom`, `screen`, `PuTTY`)

### Wiring (for UART1)

| GPS Module Pin | Pico Pin |
|----------------|----------|
| VCC            | 3.3V/5V  |
| GND            | GND      |
| TX             | GP8 (RX) |
| RX             | GP9 (TX) |

### Build Instructions

1. **Clone Pico SDK**

2. Set up environment (only once):

```bash
export PICO_SDK_PATH=/path/to/pico-sdk
```
3. Create a build directory and compile:

```bash
mkdir build
cd build
cmake ..
make
```

4. Flash the .uf2 to the Pico:

-Press and hold BOOTSEL on your Pico
-Plug into USB
-Copy the generated .uf2 file to the mounted USB drive:

```bash
cp neo7m.uf2 /media/$USER/RPI-RP2/
```
Or use picotool (if USB serial is active):
```bash
picotool load neo7m.uf2
```

5. Serial Output

Connect to the Pico's USB serial output using a terminal program (115200 baud):

``` bash
minicom -D /dev/ttyACM0
```
