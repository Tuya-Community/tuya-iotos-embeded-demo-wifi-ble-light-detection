/*
 * @Author: zgw
 * @email: liang.zhang@tuya.com
 * @LastEditors: zgw
 * @file name: sensor_control.c
 * @Description: 
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2021-1-5 16:21:15
 * @LastEditTime: 2021-1-5 16:21:15
 */

#include "sensor_control.h"
#include "bh1750.h"
#include "tuya_gpio.h"

/***********************************************************
*************************types define***********************
***********************************************************/
typedef enum
{
    LOW = 0,
    HIGH,
}default_level;



DEVICE_DATA_T device_data = {0};

APP_REPORT_DATA_T app_report_data = {0};

/***********************************************************
*************************IO control device define***********
***********************************************************/
#define IIC_SDA_PORT                     (6)
#define IIC_SCL_PORT                     (7)



/***********************************************************
*************************about adc init*********************
***********************************************************/



/***********************************************************
*************************about iic init*********************
***********************************************************/
STATIC bh1750_init_t bh1750_int_param = {IIC_SDA_PORT, IIC_SCL_PORT};


/***********************************************************
*************************function***************************
***********************************************************/

STATIC VOID __ctrl_gpio_init(CONST TY_GPIO_PORT_E port, CONST BOOL_T high)
{
    tuya_gpio_inout_set(port, FALSE);
    tuya_gpio_write(port, high);
}

VOID app_device_init(VOID)
{
    INT_T op_ret = 0;
    
    tuya_bh1750_init(&bh1750_int_param);

}



OPERATE_RET app_get_all_sensor_data(VOID)
{
    OPERATE_RET ret = 0;

    device_data.bright_value = tuya_bh1750_get_bright_value();
    PR_NOTICE("light_intensity_value = %d",device_data.bright_value);
    app_report_data.bright_value = device_data.bright_value;
    
    return ret;
}



VOID app_ctrl_handle(VOID)
{   
    PR_DEBUG("ctrl handle");

}

VOID app_ctrl_all_off(VOID)
{   
    ;
}