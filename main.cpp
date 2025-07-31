#include "neo7m.h"
#include <cstdio>

int main() {
    stdio_init_all();

    NEO7M gps(uart1, 8, 9); // TX = GP8, RX = GP9
    gps.init();

    while (true) {
        std::string line;
        if (gps.readLine(line)) {
            printf("NMEA: %s\n", line.c_str());
        }
    }

    return 0;
}

