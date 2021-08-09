#include <drv_uart.h>

volatile uint64_t tohost __attribute__((section(".htif")));
volatile uint64_t fromhost __attribute__((section(".htif")));

void uart_putc(char c)
{
#if __riscv_xlen == 64
    while (tohost);
    //while((*UART_LSR & UART_LSR_THRE) == 0);
    //write32(GD32VF103_UART4 + NUCLEI_UART_REG_TXRXDATA, c);

    //write32(NUCLEI_N_DEV_UART0 + NUCLEI_UART_REG_STAT, c);
    tohost = TOHOST_CMD(1, 1, c);
#else
   // while((*UART_LSR & UART_LSR_THRE) == 0);
    write32(NUCLEI_N_DEV_UART0 + NUCLEI_UART_REG_STAT, c);
#endif
    
}

char uart_getc(void)
{
    // virtual_addr_t addr = QEMU_UART_BASE;
    // if (*UART_LSR & LSR_RX_READY){
    //     return read32(addr + RHR);
    // } 
    // else 
    // {
    //     return -1;
    // }
}

void uart_init(void)
{
    
}

void htif_init(void)
{
  tohost = 0;
  fromhost = 0;
}