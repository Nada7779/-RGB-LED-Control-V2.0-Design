/**
 ** @file                   app.c
 ** @brief                  This is source file for app for TM4C123GH6PM
 ** @author                 Nada Abdelazim
 ** @date                   June 16, 2023
 ** @version                0.1
 */
#include "app.h"
#include "led.h"
#include "button.h"
#include "systick.h"


#define FIRST_STATE   1
#define SECOND_STATE  2
#define THIRD_STATE   3
#define FOURTH_STATE  4
#define FIFTH_STATE   5

uint8_t buttonstate;
		
uint8_t sequence;

void APP_init(void)
{
	 buttonstate=released;	
	 sequence=FIRST_STATE;
	// INIT SYSTICK
   systick_init();
	// LEDs init
  led_init(RED_LED_PORT,RED_LED_PIN);
	led_init(BLUE_LED_PORT,BLUE_LED_PIN);
	led_init(GREEN_LED_PORT,GREEN_LED_PIN);
	// button init
	button_init(SW1_PORT,SW1_PIN);
	// Initially, all LEDs are OFF
  led_off(RED_LED_PORT,RED_LED_PIN);
	led_off(BLUE_LED_PORT,BLUE_LED_PIN);
	led_off(GREEN_LED_PORT,GREEN_LED_PIN);	
}
void APP_start(void)
	{
		
		button_read(SW1_PORT,SW1_PIN,&buttonstate);
		
		if (buttonstate==pressed)
		{
			switch (sequence)
			{
				case FIRST_STATE: 
					               led_on(RED_LED_PORT,RED_LED_PIN);
				                 systick_delay_sec();
				                 led_off(RED_LED_PORT,RED_LED_PIN);
				                 sequence=SECOND_STATE;
                 				 break;
				case SECOND_STATE:
				                  led_on(GREEN_LED_PORT,GREEN_LED_PIN);
				                  systick_delay_sec();
		                      led_off(GREEN_LED_PORT,GREEN_LED_PIN); 		
				                  sequence=THIRD_STATE;
                 				  break;
				case THIRD_STATE: 
				                  
				                  led_on(BLUE_LED_PORT,BLUE_LED_PIN);
				                  systick_delay_sec();
				                  led_off(BLUE_LED_PORT,BLUE_LED_PIN);
				                  sequence=FOURTH_STATE;
                 				  break;
				case FOURTH_STATE:
					               led_on(RED_LED_PORT,RED_LED_PIN);
				                 led_on(GREEN_LED_PORT,GREEN_LED_PIN);
				                 led_on(BLUE_LED_PORT,BLUE_LED_PIN);
				                 systick_delay_sec();
				                 sequence=FIFTH_STATE;
                 				 break;
				case FIFTH_STATE:
					                led_off(RED_LED_PORT,RED_LED_PIN);
				                  led_off(GREEN_LED_PORT,GREEN_LED_PIN);
				                  led_off(BLUE_LED_PORT,BLUE_LED_PIN);
				                  sequence=FIRST_STATE;
                 				  break;
				default:
					                //ERROR Handling
				                  sequence=FIRST_STATE;
				                  
			}
		}
		
		
	}





	
	


