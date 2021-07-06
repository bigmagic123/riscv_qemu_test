#include <stdio.h>
#include <stdlib.h>
#include <drv_uart.h>

int main(void)
{
    uart_init();
    uart_putc('a');
    uart_putc('b');
    uart_putc('c');
    return 0;
}
