/**
	@author moin
	@version 0.1
	@file five.c
	@brief Retake five
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
#include <stdio.h>
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
	char str[16];
	uint16_t value;
	
	// Init
	lcd_init(); // Function to initialise LCD display
	init(); 	// Function to initialise I/Os
	
	// Set display
	lcd_clear();
	lcd_string("Retake step five");
	lcd_setcursor(0,2);
	//lcd_string("step five");


	// ADC init
	DDRC &= ~(1 << DDC3);		// PC3 as Input (Poti)
	PORTC &= ~(1 << DDC3);		// Pullup PC3 OFF	
	
	// ADMUX
	ADMUX = 0;
	ADMUX |= (1 << REFS0); // AVCC as reference
	//TODO: ADMUX |= ... // Select Channel ADC3
	ADMUX |= (1 << MUX0);  // Select Channel ADC3
	ADMUX |= (1 << MUX1);
	

	ADCSRA = 0;
	ADCSRA |= (1 << ADPS2)|(1 << ADPS1); // ADC Prescale by 64
	
	ADCSRA |= (1 << ADSC)|(1 << ADATE)|(1 << ADEN); // Start conversion
												//Free running, Enalbe ADC


	
	// Loop
	for (;;){
		
		// Short delay (250ms)
		_delay_ms(250);

		 // read 10 bit ADC and save it to value
		value = ADCW;
		

		// Print value to LCD
		sprintf(str, "%d    ", value);
		lcd_setcursor(0,2);
		lcd_string(str);
		
	}
		
	return 0;
}
/******************************************************************************/
