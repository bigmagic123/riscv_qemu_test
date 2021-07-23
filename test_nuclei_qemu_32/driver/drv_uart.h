#ifndef __VIRT_UART_H__
#define __VIRT_UART_H__

#include <ttypes.h>
/* peripheral memory map */
#define APB1_BUS_BASE         ((uint32_t)0x40000000U)        /*!< apb1 base address                */
#define APB2_BUS_BASE         ((uint32_t)0x40010000U)        /*!< apb2 base address                */
#define AHB1_BUS_BASE         ((uint32_t)0x40018000U)        /*!< ahb1 base address                */
#define AHB3_BUS_BASE         ((uint32_t)0x60000000U)        /*!< ahb3 base address                */
#define USART_BASE            (APB1_BUS_BASE + 0x00004400U) 

#define USART1                        USART_BASE                        /*!< USART1 base address */
#define USART2                        (USART_BASE+(0x00000400U))        /*!< USART2 base address */
#define UART3                         (USART_BASE+(0x00000800U))        /*!< UART3 base address */
#define GD32VF103_UART4               (USART_BASE+(0x00000C00U))        /*!< UART4 base address */
#define USART0                        (USART_BASE+(0x0000F400U))        /*!< USART0 base address */

#define NUCLEI_UART_REG_STAT 0x000
#define NUCLEI_UART_REG_TXRXDATA 0x004
#define NUCLEI_UART_REG_TXCTRL 0x008
#define NUCLEI_UART_REG_RXCTRL 0x00C
#define NUCLEI_UART_REG_IE 0x010
#define NUCLEI_UART_REG_IP 0x014
#define NUCLEI_UART_REG_DIV 0x018

void uart_putc(char c);
char uart_getc(void);
void uart_init(void);

#endif