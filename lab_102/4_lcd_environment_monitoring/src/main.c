/*
 * main.c
 *
 * this is the skeleton for task 4
 *
 * author:    Dr. Alex Shenfield
 * date:      04/09/2018
 * purpose:   55-604481 embedded computer networks : lab 102
 */

// include the basic headers and hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "adc.h"
#include "stm32746g_discovery_lcd.h"

// LCD DEFINES
#define BOARDER "****************************"
// CODE
const char * welcome_Message[2] = 
{
	"*     Hello LCD World!     *",
	"*      Welcome to SHU      *"
};

gpio_pin_t tmp = {PA_0, GPIOA, GPIO_PIN_0};
gpio_pin_t ldr = {PF_10, GPIOF, GPIO_PIN_10};
gpio_pin_t pot = {PF_9, GPIOG, GPIO_PIN_9};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	init_adc(pot);
	
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, SDRAM_DEVICE_ADDR);
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	
	// show the header
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	
	BSP_LCD_SetFont(&Font24);
	
	BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
	BSP_LCD_DisplayStringAtLine(0, (uint8_t *)BOARDER);
	BSP_LCD_DisplayStringAtLine(1, (uint8_t *)welcome_Message[0]);
	BSP_LCD_DisplayStringAtLine(2, (uint8_t *)welcome_Message[1]);
	BSP_LCD_DisplayStringAtLine(3, (uint8_t *)BOARDER);
	
	
	
	// loop
	while(1)
	{
		uint16_t adc_tmp = read_adc(tmp);
		uint32_t adc_ldr = read_adc(ldr);
		uint32_t adc_pot = read_adc(pot);
		char str[20];
		sprintf(str, "ADC = %4d", adc_ldr);
		BSP_LCD_ClearStringLine(6);
		BSP_LCD_DisplayStringAtLine(6, (uint8_t *)str);
		
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_FillRect(0, 200, 480, 20);
		BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		BSP_LCD_FillRect(0, 200, (480*(adc_pot/4095.0)), 20);
		
		sprintf(str, "Temperature = %4f", ((((adc_ldr/4095.0)*3300.0) -500 )/10.0));
		BSP_LCD_ClearStringLine(7);
		BSP_LCD_DisplayStringAtLine(7, (uint8_t *)str);
		
		HAL_Delay(75);
	}
}
