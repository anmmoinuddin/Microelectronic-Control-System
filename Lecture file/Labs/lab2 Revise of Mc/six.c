 
/**
	@author Thomas Grunenberg
	@version 0.1
	@file six.c
	@brief Microcontroller retake six
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
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
	lcd_string("step six");

	// TODO: Set prescaler for timer 1
	
	TCCR1B |= (1 << CS12)|(1 << CS10);
	
	for (;;){
		//Your code here
		// DO NOT use the delay functions!
			if( TCNT1 >= 7812){
			PORTC ^= (1 << PC0);
			TCNT1 = 0;
					}
}
		
	return 0;
}
/******************************************************************************/
