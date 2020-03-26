/**
	@author Thomas Grunenberg
	@version 0.1
	@file three.c
	@brief Retake three
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL



/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>

#include <util/delay.h>				//newly added
#include "init.h"
#include "lcd.h"
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){

	lcd_init(); // Function to initialise LCD display
	init(); 	// Function to initialise I/Os
	
	lcd_clear();
	lcd_string("Retake");
	lcd_setcursor(0,2);
	lcd_string("step three");
	
	
	while (1) 	// Loop forever
	{
		// Key 1: enable red LED
		if ( ~PINB & (1<< PB0) )
			PORTC |= (1 << PC0);			

		// Key 2: enable green LED
		if ( ~PINB & (1<< PB1) )
			PORTC |= (1 << PC1);			


		// Key 1 and Key 2: disable red and green LED
		if ( ( ~PINB & (1<< PB1) ) &&  ( ~PINB & (1<< PB0) ) ){

			

			PORTC &= ~(1 << PC0);
			PORTC &= ~(1 << PC1);			
			PORTC |= (1 << PC2);
			
			// Wait for relase
			_delay_ms(100);
		}

		// Yellow LED
		if ( ( ~PINB & (1<< PB1) ) ||  ( ~PINB & (1<< PB0) ) )
			PORTC |= (1 << PC2);
		else
			PORTC &= ~(1 << PC2);

		




	}
	return 0;
}
/******************************************************************************/
