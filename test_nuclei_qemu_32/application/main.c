#include <stdio.h>
#include <stdlib.h>
#include <drv_uart.h>
#include <printf.h>

#include <encoding.h>

#include <drv_test.h>


void _putchar(char character)
{
  uart_putc(character);
}

void test_csr()
{
  int vector_base = 0x00200;
  asm volatile("csrw 0x301,%0"::"r"(vector_base));
}

int main(void)
{
    int a = -7, b = 0;
#if __riscv_xlen == 64
    htif_init();
#endif
    uart_init();
    printf("hello!\n");
    //virt_test();
    printf("test ok!\n");
    //virt_test();
    test_dsp();
    //test_csr();
    return 0;
}
