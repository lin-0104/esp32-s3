#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "lcd.h"
#include "myadc.h"

void app_main(void)
{
    lcd_init();
    adc_init();

    lcd_show_string(1,1,"adc_rl:",GREEN,BLACK);
    lcd_show_string(2,1,"vol_rl:",GREEN,BLACK);
    lcd_show_string(3,1,"adc_rp:",GREEN,BLACK);
    lcd_show_string(4,1,"vol_rp:",GREEN,BLACK);
    while (1)
    {
        lcd_show_num(1,8,adc_value_rl,4,YELLOW,BLACK);
        lcd_show_float(2,8,(float)adc_value_rl/4095*3.3,3,YELLOW,BLACK);
        lcd_show_num(3,8,adc_value_rp,4,YELLOW,BLACK);
        lcd_show_float(4,8,(float)adc_value_rp/4095*3.3,3,YELLOW,BLACK);
        vTaskDelay(500);
    }
}