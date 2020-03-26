/**
	@author Thomas Grunenberg
	@version 0.1
	@file main.c
	@brief Ball and Seesaw Template
*/

/**
	@brief The CPU speed in Hz
*/
#define F_CPU 8000000UL





/******************************************************************************/
/* INCLUDED FILES                                                             */
/******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#include "init.h"
#include "servo.h"
#include "irsensors.h"


/******************************************************************************/

/******************************************************************************/
/* Global memory                                                              */
/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

void long_delay(uint16_t time){

	while(time > 0){
		if (time > 255){
			_delay_ms(255);
			time -= 255;
		} else {
			_delay_ms(1);
			time--;
		}
	}
	
	return;
}
/******************************************************************************/

inline void led_red(uint8_t onOrOff){
	if (onOrOff)
		PORTB |= ( 1 << PB0);
	else
		PORTB &= ~( 1 << PB0);
}
/******************************************************************************/

inline void led_green(uint8_t onOrOff){
	if (onOrOff)
		PORTD |= ( 1 << PD7);
	else
		PORTD &= ~( 1 << PD7);
}
/******************************************************************************/

/******************************************************************************/

/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/
volatile uint8_t a_old = 0;
volatile uint8_t counter = 0;
int main(void){

	init();
	servo_init();
	irsensors_init();

	TCCR0B |= (1 << CS02)|(1 << CS00);
	TIMSK0 |= (1 << TOIE0);
	sei(); 	

	int err_old=0;
	int d=127;	// Middle value 
	int err=0;	// error value 
	int out;	// servo positon set value
	int a;		//postion value of the sensor	
	int z = 2;
	servo_setPos(127);
	for (;;){ 	// Loop forever
		a = irsensors_getRawPos();
		if (a==1){
			err=-6;	
			counter = 0; 
		}
		else if (a==2){
			err=-4;
			counter = 0;
		}
		else if (a==3){
			err=-2;
			counter = 0;
		}
		else if (a==4){
			err=-1;
			counter = 0;
		}
		else if (a==5){
			err=1;
			counter = 0;
		}
		else if (a==6){
			err=2;
			counter = 0;
		}
		else if (a==7){
			err=4;
			counter = 0;
		}
		else if (a==8){
			err=6;
			counter = 0;
		}
		if ( counter >= 100 ){
			if ( a_old >= 5 ){
			d = 129;	
			}
			else{
			d = 127;
			}
			counter = 0;
		}
	out=d+(z*err-err_old);
	servo_setPos(out);
	_delay_ms(220);
	err_old=err;
		if ( a != 0 ){
			a_old = a;
		}	
	}
	
	
	return 0;
}
	ISR(TIMER0_OVF_vect){
		counter++;
	}
/******************************************************************************/
