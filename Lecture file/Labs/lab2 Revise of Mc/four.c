/**
	@author Thomas Grunenberg
	@version 0.1
	@file four.c
	@brief Retake four
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
	uint8_t state = 1;

	lcd_init(); // Function to initialise LCD display
	init(); 	// Function to initialise I/Os
	
	lcd_clear();
	lcd_string("Retake");
	lcd_setcursor(0,2);
	lcd_string("step four");	

	
	
	
	while(1){
		
		if ( ~PINB & (1<< PB1) ){
			//TODO delay
			_delay_ms(100);
			if (state){
				PORTC |= (1 << PC0);
				PORTC |= (1 << PC1);
				PORTC |= (1 << PC2);
				state = 0;				
			} else {
				PORTC &= ~(1 << PC0);
				PORTC &= ~(1 << PC1);
				PORTC &= ~(1 << PC2);
				//TODO: 
				state=1;			
			}
			
			// Wait for release
			//TODO
			_delay_ms(100);
		}
		/*	if(~PINB & (1<<PB0))
			{
			PORTC |= (1 << PC0);
			PORTC |=(1 << PC1);			
			PORTC |= (1 << PC2);


			}

			_delay_ms(100);

			if(~PINB & (1<<PB0))
			{
			PORTC &= ~(1 << PC0);
			PORTC &= ~(1 << PC1);			
			PORTC &= ~(1 << PC2);
			_delay_ms(100);
			*/
	}

	return 0;
}
/******************************************************************************/
