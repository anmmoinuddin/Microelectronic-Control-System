
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
	@file init.c
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
	
	DDRC |= (1 << PC0); // PC0 to output
	DDRC |= (1 << PC1); // PC1 to output
	DDRC |= (1 << PC2); // PC2 to output
	
	DDRB &= ~(1 << PB0); // PB0 to input
	DDRB &= ~(1 << PB1); // PB1 to input
	
	// Enable Pullup resistors
	PORTB |= (1 << PB0);
	PORTB |= (1 << PB1);	

	// TWI / I2C
	DDRC &= ~(1 << PC5);
	DDRC &= ~(1 << PC4);
	PORTC |= (1 << PC5);
	PORTC |= (1 << PC4);
	TWBR = 25;
	TWSR = (1<<TWPS0);

}
/******************************************************************************/
