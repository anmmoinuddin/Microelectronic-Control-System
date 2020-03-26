
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
// 

    
/**
	@author Thomas Grunenberg
	@version 0.1
	@file irsensors.c
	@brief Functions to read the position of the ball with the IR sensors
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
//#include <avr/interrupt.h>
/******************************************************************************/




/******************************************************************************/
/* Global Memory                                                              */
/******************************************************************************/

/******************************************************************************/



/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

void irsensors_init(void){
	
	// Set Ports direction to input
	DDRC &= ~(1 << DDC0);		// PC0
	DDRC &= ~(1 << DDC1);		// PC1
	DDRC &= ~(1 << DDC2);		// PC2
	DDRC &= ~(1 << DDC3);		// PC3
	DDRC &= ~(1 << DDC4);		// PC4
	DDRC &= ~(1 << DDC5);		// PC5
	DDRD &= ~(1 << DDD5);		// PD5
	DDRD &= ~(1 << DDD6);		// PD6

	// Enable internal pullup resistors
	PORTC |= ( 1 << PC0);		// PC0
	PORTC |= ( 1 << PC1);		// PC1
	PORTC |= ( 1 << PC2);		// PC2
	PORTC |= ( 1 << PC3);		// PC3
	PORTC |= ( 1 << PC4);		// PC4
	PORTC |= ( 1 << PC5);		// PC5
	PORTD |= ( 1 << PD5);		// PD5
	PORTD |= ( 1 << PD6);		// PD6
}
/******************************************************************************/

uint8_t irsensors_getRawPos(void){

	// Orange line sensor
	if ( PIND & (1 << PD6) )
		return 1;

	// Yellow line sensor
	if ( PIND & (1 << PD5) )
		return 2;

	// Dark green line sensor
	if ( PINC & (1 << PC0) )
		return 3;

	// Light green line sensor
	if ( PINC & (1 << PC1) )
		return 4;

	// White line sensor
	if ( PINC & (1 << PC2) )
		return 5;

	// Brown line sensor
	if ( PINC & (1 << PC3) )
		return 6;

	// Blue line sensor
	if ( PINC & (1 << PC4) )
		return 7;

	// Grey line sensor
	if ( PINC & (1 << PC5) )
		return 8;

	// default value
	return 0;
}
/******************************************************************************/
