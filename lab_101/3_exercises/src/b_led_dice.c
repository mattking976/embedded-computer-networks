/*
 * b_led_dice.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"
#include "random_numbers.h"

// mapping all the leds
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1}; //bottom right
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};//middle right
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};//top right
gpio_pin_t led4 = {PA_8, GPIOA, GPIO_PIN_8};//bottom left
gpio_pin_t led5 = {PA_15, GPIOA, GPIO_PIN_15};//middle left
gpio_pin_t led6 = {PI_2, GPIOI, GPIO_PIN_2};//center
gpio_pin_t led7 = {PI_3, GPIOI, GPIO_PIN_3};//top left
// this is the main method
int main()
{
	//initialising needed libraries
	HAL_Init();
	init_sysclk_216MHz();
	init_random();
	
	//initialising all leds
	init_gpio(led, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);
	init_gpio(led5, OUTPUT);
	init_gpio(led6, OUTPUT);
	init_gpio(led7, OUTPUT);
	while(1)
	{
		//resetting the led dice
		write_gpio(led, LOW);
		write_gpio(led2, LOW);
		write_gpio(led3, LOW);
		write_gpio(led4, LOW);
		write_gpio(led5, LOW);
		write_gpio(led6, LOW);
		write_gpio(led7, LOW);
		//getting the random number
		uint32_t rnd = (get_random_int()%6) +1;
		HAL_Delay(200);
		
		switch(rnd)
		{
			case 1:
				//turning on the center led and giving a 2 second delay for the user the see the results
				write_gpio(led6, HIGH);
				HAL_Delay(2000);
				break;
			case 2:
				//turning on the top left and bottom right leds and a 2 second delay for results
				write_gpio(led, HIGH);
				write_gpio(led7, HIGH);
				HAL_Delay(2000);
				break;
			case 3:
				//turning on the top left and bottom right and center leds and a 2 second delay for results
				write_gpio(led, HIGH);
				write_gpio(led6, HIGH);
				write_gpio(led7, HIGH);
				HAL_Delay(2000);
				break;
			case 4:
				//turning on the 4 corners and a 2 second delay for results
				write_gpio(led3, HIGH);
				write_gpio(led7, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led, HIGH);
				HAL_Delay(2000);
				break;
			case 5:
				//turning on the 4 corners and the center and a 2 second delay for results
				write_gpio(led3, HIGH);
				write_gpio(led7, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led, HIGH);
				write_gpio(led6, HIGH);
				HAL_Delay(2000);
				break;
			case 6:
				//turning on the left and right sides and a 2 second delay for results
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led5, HIGH);
				write_gpio(led7, HIGH);
				HAL_Delay(2000);
				break;
			default:
				//should not get here but if we do show all on
				write_gpio(led, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led5, HIGH);
				write_gpio(led6, HIGH);
				write_gpio(led7, HIGH);
				HAL_Delay(1);
				break;
		}
	}
}
