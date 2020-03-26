/**
	@author Thomas Grunenberg
	@version 0.1
	@file init.h
	@brief Init fuunction for the I/O
*/


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include "init.h"
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Init the PORTx and DDRx register for the I/O setup
*/
void init(void){

	DDRB |= (1 << DDB0);		// PB0 as output (LED red)
	PORTB &= ~( 1 << PB0);

	DDRD |= (1 << DDD7);		// PD7 as output (LED green)
	PORTD &= ~( 1 << PD7);

}
