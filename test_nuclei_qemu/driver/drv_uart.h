#ifndef __VIRT_UART_H__
#define __VIRT_UART_H__

#include <ttypes.h>

#ifdef QEMU_VIRT
#define QEMU_UART_BASE            (0x10000000L)

#define RHR 0    // Receive Holding Register (read mode)
#define THR 0    // Transmit Holding Register (write mode)
#define DLL 0    // LSB of Divisor Latch (write mode)
#define IER 1    // Interrupt Enable Register (write mode)
#define DLM 1    // MSB of Divisor Latch (write mode)
#define FCR 2    // FIFO Control Register (write mode)
#define ISR 2    // Interrupt Status Register (read mode)
#define LCR 3    // Line Control Register
#define MCR 4    // Modem Control Register
#define LSR 5    // Line Status Register
#define MSR 6    // Modem Status Register
#define SPR 7    // ScratchPad Register

#define LSR_RX_READY (1 << 0)
#define LSR_TX_IDLE  (1 << 5)
#define UART_LSR (volatile uint8_t *)(QEMU_UART_BASE + 0x05)
#define UART_LSR_THRE       0x20
#endif

#ifdef  QEMU_GD32VF
#define GD32VF103_UART4 (0x40005000)

#define NUCLEI_UART_REG_TXDATA 0x000
#define NUCLEI_UART_REG_RXDATA 0x004
#define NUCLEI_UART_REG_TXCTRL 0x008
#define NUCLEI_UART_REG_RXCTRL 0x00C
#define NUCLEI_UART_REG_IE 0x010
#define NUCLEI_UART_REG_IP 0x014
#define NUCLEI_UART_REG_DIV 0x018

#endif

void uart_putc(char c);
char uart_getc(void);
void uart_init(void);

#endif