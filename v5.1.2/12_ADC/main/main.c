#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_adc/adc_oneshot.h"
#include "myadc.h"
#include "lcd.h"
#include "my_usart.h"

void app_main(void)
{

    int length = 0;
    uint8_t receive_data[1024] = {0};
    uart_init();


    while (1)
    {

        length = uart_read_bytes(UART_NUM_0, receive_data, sizeof(receive_data) - 1, 100 / portTICK_PERIOD_MS);
        if (length > 0)
        {
            printf("Received: %s\r\n", receive_data);
            uart_flush(UART_NUM_0);
        }

        vTaskDelay(50);
    }
}