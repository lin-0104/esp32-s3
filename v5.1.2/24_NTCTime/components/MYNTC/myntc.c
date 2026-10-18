#include "myntc.h"
#include "esp_sntp.h"
#include <time.h>


void myntc_init(void)
{
    esp_sntp_setoperatingmode(ESP_SNTP_OPMODE_POLL);//设置SNTP工作模式为轮询模式
    esp_sntp_setservername(0, "pool.ntp.org");
    esp_sntp_setservername(1, "cn.pool.ntp.org");
    esp_sntp_setservername(2, "ntp1.aliyun.com");
    esp_sntp_init();//初始化SNTP
    setenv ("TZ", "CST-8", 1);//设置时区为东八区，与UTC时间差8小时，
    tzset();//设置时区
}