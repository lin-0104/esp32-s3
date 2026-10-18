#include "my_usart.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <stdio.h>
#include <stdarg.h>


void uart_init(void)
{
  uart_config_t uart_structure = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .parity = UART_PARITY_DISABLE,
        .rx_flow_ctrl_thresh = 100,
        .source_clk = UART_SCLK_DEFAULT,
        .stop_bits = UART_STOP_BITS_1,
    };
    uart_param_config(UART_NUM_0, &uart_structure);

      uart_set_pin(UART_NUM_0, GPIO_NUM_43, GPIO_NUM_44, -1, -1);
    
      uart_driver_install(UART_NUM_0, 1024, 1024, 0, NULL, 0);
   
}


// ÖØÐ´ _write£¬ÈÃ printf ×ß uart Çý¶¯
int _write(int fd, const char *data, int len)
{
    uart_write_bytes(UART_NUM_0, data, len);
    return len;
}