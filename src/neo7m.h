#ifndef NEO7M_H
#define NEO7M_H

#include "hardware/uart.h"
#include "pico/stdlib.h"
#include <string>
#include <queue>

class NEO7M {
public:
    NEO7M(uart_inst_t* uart_port, uint tx_pin, uint rx_pin, uint32_t baudrate = 9600);
    void init();
    bool readLine(std::string& line);

private:
    uart_inst_t* uart;
    uint tx, rx;
    uint32_t baud;
    std::string buffer;
};

#endif // NEO7M_H
