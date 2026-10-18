#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led.h"
#include "nvs_flash.h"
#include "myble.h"

void app_main(void)
{
    nvs_flash_init();
    led_init();
    ble_init();
}