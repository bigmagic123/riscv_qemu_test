#include <stdio.h>
#include <stdlib.h>
#include <drv_uart.h>
#include <printf.h>

void _putchar(char character)
{
  uart_putc(character);
}

int main(void)
{
    uart_init();
    printf("hello\n");
    return 0;
}
