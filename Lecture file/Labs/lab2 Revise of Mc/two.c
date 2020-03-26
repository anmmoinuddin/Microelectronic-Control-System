 
/**
	@author Thomas Grunenberg
	@version 0.1
	@file two.c
	@brief Microcontroller retake step two
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
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

	lcd_init();
	init(); 	// Function to initialise I/Os
	
	lcd_clear();
	lcd_string("Retake");
	lcd_setcursor(0,2);
	lcd_string("step two");
	
	
	// LED off
	PORTC &= ~(1 << PB0);
	
	for (;;){
		
		if ( ~PINB & (1<< PB0) )
			PORTC &= ~(1 << PC0);		

		if ( ~PINB & (1<< PB1) )
			PORTC |= (1 << PC0);			

	}
		
	return 0;
}
/******************************************************************************/
