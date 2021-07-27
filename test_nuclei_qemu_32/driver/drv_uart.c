#include <drv_uart.h>

void uart_putc(char c)
{
    //while((*UART_LSR & UART_LSR_THRE) == 0);
    //write32(GD32VF103_UART4 + NUCLEI_UART_REG_TXRXDATA, c);

    write32(NUCLEI_N_DEV_UART0 + NUCLEI_UART_REG_STAT, c);
    
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