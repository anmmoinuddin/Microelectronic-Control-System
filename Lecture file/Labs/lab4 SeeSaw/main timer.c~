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
	volatile int Protect; 	// compare interrupt protection from overflow
	volatile int time_new; 	// newer timer value
	volatile int time_old;	// older timer value
	volatile int old_postion; // position from last time.
	volatile int derivative_error; 
	volatile int intergral_error; 	
	volatile int ki = 0.05; // integrall factor
	volatile int kd = 1; // derivative factor
	volatile int ttime_new;
	volatile int ttime_old;
	volatile int x; // value we change the output with
	volatile int out; // variable which the sensor will be set;
	volatile int vel; // velocity;
	volatile int setpoint = 100; // desired middle point ( 127);
	volatile int sen_position ; // sensor variable
	
int main(void){

	init();
	servo_init();
	irsensors_init();
	
	// Setting up the timer +  compare interrupt
	TCCR1B |= (1<<CS10)|(1<<CS12); // prescaler 1024
	EICRA |=(ISC01);
	EIMSK |=(1<<INT0);
	TIMSK1 |=(1<<OCIE1A);
	
	sei();
	OCR1A = 0;	
	// need timer;
	
	
	
	

	servo_setPos(100);
	for (;;){ 	// Loop forever
		sen_position = irsensors_getRawPos(); // get which sensor gets passed.
		if (sen_position==1){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==2){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==3){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==4){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==5){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==6){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==7){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		else if (sen_position==8){
			// saving time ;
			time_new = TCNT1;
			// starting interrupt 
			Protect = 1;
			TCNT1 = 0;
		}
		time_old = time_new;
		if (Protect == 1){
			led_green(1);
			led_red(0);
		}
	}
	
	
	return 0;
}
/******************************************************************************/

/******************************************************************************/
// interrupt timer on Compare mode
ISR(TIMER1_COMPA_vect){
	if ( Protect == 1){ // interrupt protection
	// calculation of timer in secxonds
	ttime_new = ((time_new*1024)/8000000)*10; // *10 because the time value gonna be too small so we need to increase it so some higher value that the sensor dooes not change to much.
	ttime_old = ((time_old*1024)/8000000)*10;
	// calculate x;
	// or calculate some value to make the error calculation like get a distance calculate the velocity and then change it.
	// vel = ttime_new * distance; // determine the distance
	// out = out + vel; // maybe a factor of a veloctiy like 2*;
	derivative_error = kd * (ttime_new - ttime_old); 
	intergral_error = ki * (ttime_new - ttime_old);
	x = derivative_error + intergral_error;
	if ( x > 1 ){ // to slow ball makes a x higher then 1 so we need to change so the ball still moves
		x = 0.99;
	}
	out = setpoint/x;
	if ( sen_position < 5){
		out = - out;
	}
	servo_setPos(out);	// set the servo position
	Protect = 0;		// deactivate protection
	TCNT1 = 0;
	led_red(1);
	}
	led_green(0);
	
}
/******************************************************************************/
