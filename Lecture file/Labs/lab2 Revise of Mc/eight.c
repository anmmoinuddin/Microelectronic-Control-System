 
/**
	@author Thomas Grunenberg
	@version 0.1
	@file eight.c
	@brief Microcontroller retake eight
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
#include <util/twi.h>
#include "init.h"
#include "lcd.h"
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/**
	@brief Check if an I2C device is connected and responding
	@return zero for no, one for yes
*/
uint8_t check_i2c(uint8_t adr){
	uint8_t ret = 0;

	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); // Send START condition

	while( !( TWCR & (1 << TWINT) ) ) // wait until this is done
		;

	// Check value of TWSR
	if ( (TWSR & 0xF8) != TW_START && (TWSR & 0xF8) != TW_REP_START)
		return 1; /*TODO*/

	// slave address to bus and wait until this is donde
	// TODO
	TWDR = adr;
	TWCR=(1<<TWINT)|(1<<TWEN); //clear twi interrupt flag, enalbe twi
	
	while(!(TWCR & (1<<TWINT) )); //wait until this is done 

	// check value (masked prescaler bits)
	if ( (TWSR & 0xF8) == TW_MT_SLA_ACK ) 
		ret = 1;
	if ( (TWSR & 0xF8) == TW_MR_SLA_ACK ) 
		ret = 1;

	 // send stop---------------------------------------------------------------
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	
	// wait until this is done
	while( TWCR & (1 << TWSTO) )
		;

	return ret;
		
}
/******************************************************************************/



/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
int main(void){

	init(); 	// Function to initialise I/Os
	
	// TWI init
	TWSR = 0;
	TWBR = 20;

	
	for (;;){
		
		_delay_ms(10);
		
		if ( check_i2c(0xA0) )
			PORTC |= (1 << PC0);
		else
			PORTC &= ~(1 << PC0);			

		// TODO: the other LED
		if ( check_i2c(0xD0) )
			PORTC |= (1 << PC1);
		else
			PORTC &= ~(1 << PC1);			


	}
		
	return 0;
}
/******************************************************************************/


