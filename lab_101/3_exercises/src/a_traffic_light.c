/*
 * a_traffic_lights.c
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

<<<<<<< HEAD
// map the leds to GPIO PI1 PI14 PI15 for red amber and green lights
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led2 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led3 = {PB_15, GPIOB, GPIO_PIN_15};
=======
// map the led to gpio pins
gpio_pin_t led1 = {PA_8,  GPIOA, GPIO_PIN_8};
>>>>>>> upstream/master

// this is the main method
int main()
{
<<<<<<< HEAD
	HAL_Init();
	init_sysclk_216MHz();
	
	init_gpio(led,OUTPUT);
	init_gpio(led2,OUTPUT);
	init_gpio(led3,OUTPUT);
	while(1)
	{
		//turning the red led on
		write_gpio(led, HIGH);
		//wait while on red
		HAL_Delay(1000);
		//transition to red amber state
		write_gpio(led2, HIGH);
		//wait while on red amber
		HAL_Delay(1000);
		//turn on green and turn off red amber
		write_gpio(led, LOW);
		write_gpio(led2, LOW);
		write_gpio(led3, HIGH);
		//wait while on green
		HAL_Delay(1000);
		//set to amber
		write_gpio(led3, LOW);
		write_gpio(led2, HIGH);
		HAL_Delay(999);
		//reset all to off before starting the sequence again
		write_gpio(led, LOW);
		write_gpio(led2, LOW);
		write_gpio(led3, LOW);
		HAL_Delay(1);
	}
=======
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();

>>>>>>> upstream/master
}
