/**
	@author Thomas Grunenberg
	@version 0.1
	@file poti.c
	@brief Read the poti value
*/


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include "poti.h"
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the PORTx and DDRx register for the I/O setup
*/
void poti_init(void){

	// Port to input, no pullup resistor
	DDRC &= ~( 1 << PC5);
	PORTC &= ~( 1 << PC5);
	
	// ADMUX
	ADMUX = 0;
	ADMUX |= (1 << REFS0); // AVCC as reference
	
	// Select Channel ADC5
	ADMUX |= (1 << MUX2) |  (1 << MUX0);
	
	ADCSRA = 0;
	ADCSRA |= (1 << ADPS1) | (1 << ADPS2); // ADC Prescale by 64 => 125kHz
	ADCSRA |= (1 << ADSC) | (1 << ADEN) | (1<<ADATE);

}
/******************************************************************************/

uint8_t poti_getValue8bit(void){
	uint16_t out;
	
	out = ADCW;

	return out / 4;

}
/******************************************************************************/

uint16_t poti_getValue16bit(void){
	uint16_t out;
	
	out = ADCW;
	
	return out;
}
/******************************************************************************/
