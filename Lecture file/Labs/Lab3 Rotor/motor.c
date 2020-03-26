/**
	@author Thomas Grunenberg
	@version 0.1
	@file motor.c
	@brief Functions to control the motor / the rotor speed
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL


/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include "motor.h"
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

void motor_init(void){
	
	// Port einstellen
	DDRB |= (1 << DDB3);		// PD2 as Output
	PORTB &= ~( 1 << PB3);		// Low value for init


	// Timer 2
	
	TCCR2B = (1 << CS20) | (1 << CS21); // prescaler 32 => 976 Hz PWM
	
	// Fast PWM mode, non inverting
	TCCR2A |= (1<<WGM21) | (1<<WGM20) | (1<<COM2A1);

	// stop motor at init
	OCR2A = 0;

}
/******************************************************************************/

void motor_setSpeed(uint8_t spd){
	OCR2A = spd;
}
/******************************************************************************/

uint8_t motor_getSpeed(void){
	return OCR2A;
}
/******************************************************************************/
