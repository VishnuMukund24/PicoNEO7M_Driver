#include "neo7m.h"

NEO7M::NEO7M(uart_inst_t* uart_port, uint tx_pin, uint rx_pin, uint32_t baudrate)
    : uart(uart_port), tx(tx_pin), rx(rx_pin), baud(baudrate) {}

void NEO7M::init() {
    uart_init(uart, baud);
    gpio_set_function(tx, GPIO_FUNC_UART);
    gpio_set_function(rx, GPIO_FUNC_UART);
    uart_set_format(uart, 8, 1, UART_PARITY_NONE);
    uart_set_fifo_enabled(uart, false);
}

bool NEO7M::readLine(std::string& line) {
    while (uart_is_readable(uart)) {
        char ch = uart_getc(uart);
        if (ch == '\n') {
            line = buffer;
            buffer.clear();
            return true;
        } else if (ch != '\r') {
            buffer += ch;
        }
    }
    return false;
}
