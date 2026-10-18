#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "lcd.h"
#include "camera.h"

void app_main(void)
{
    lcd_init();
    camera_init();
    while (1)
    {
        camera_show();
        vTaskDelay(5);
    }
}