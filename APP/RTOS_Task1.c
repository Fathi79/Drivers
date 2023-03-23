/*
 * RTOS_Task1.c
 *
 *  Created on: Sep 26, 2022
 *      Author: loppy
 */

#include "../FreeRTOS/FreeRTOSConfig.h"
#include "../FreeRTOS/FreeRTOS.h"
#include "../FreeRTOS/task.h"
#include "../FreeRTOS/semphr.h"
#include "../HAL/LED/LED.h"
#include "../HAL/LCD_DRIVER/LCD_CFG.h"
#include "../HAL/LCD_DRIVER/LCD.h"

#define null ((void*)0)

LED one, two;
xSemaphoreHandle s;

void Blink_200ms_task(void)
{
	while(1)
	{
		LED_toggle(&one);
		vTaskDelay(200);
	}
}

void Blink_1000ms_task(void)
{
	while(1)
	{
		LED_toggle(&two);
		vTaskDelay(1000);
	}
}

void LED_by_RTOS(void)
{

	one.port = GROUP_B;
	two.port = GROUP_B;
	one.pin = PIN_0;
	two.pin = PIN_1;
	one.state = LED_OFF;
	two.state = LED_OFF;
	LED_Init(&one);
	LED_Init(&two);

	xTaskCreate(Blink_200ms_task, NULL, configMINIMAL_STACK_SIZE, NULL, 3, NULL);
	xTaskCreate(Blink_1000ms_task, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	vTaskStartScheduler();

	while(1);
}


void LCD1(void)
{
	while(1)
	{
		if (s == 0)
		{
			xSemaphoreTake(s, 0);
			LCD_goto_row_col(1, 10);
			LCD_intToStr(1);
			vTaskDelay(1000);
			xSemaphoreGive(s);
		}
	}
}

void LCD2(void)
{
	while(1)
	{
		if (s == 0)
		{
			xSemaphoreTake(s, 0);
			LCD_goto_row_col(1, 10);
			LCD_intToStr(2);
			vTaskDelay(1000);
			xSemaphoreGive(s);
		}
	}
}

/*
void main(void)
{
	LCD_vInit();
	LCD_DisplayStr("I am TASK ");

	vSemaphoreCreateBinary(s);

	xTaskCreate(LCD1, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(LCD2, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	vTaskStartScheduler();

	while(1);
}
*/
