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
	@file main.c
	@brief Software für Versuchsanlage Rotor
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
#include "motor.h"
#include "led.h"
#include "poti.h"
//check here that all libs are included!

/******************************************************************************/


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
volatile uint16_t T[4];
volatile uint16_t Ti;
volatile uint16_t flag;
volatile uint16_t counter;

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


/**
	@brief Main function
	@return only a dummy to avoid a compiler warning, not used
*/

int main(void){
	
	init();
	led_init();
	motor_init();
	poti_init();

	//set up interrupt INT0
	EICRA |= (1<<ISC01);	// INT0  & INT1 generates interrupt on failing edge
	EIMSK |= (1<<INT0);		// enable external pin interrupts 0 and 1

	//set up TIMER 1
	TIMSK1 |= (1<<OCIE1A);
	
	TCCR1B |= (1<<WGM12)|(1<<CS11)|(1<<CS10);
	
	//set up TIMER 0
	TCCR0B |= (1<<CS02)|(1<<CS00);
	sei();
	
	for(;;){
		
		motor_setSpeed(poti_getValue8bit());
		Ti = (T[0]+T[1]+T[2]+T[3])/4;
		
	}
	
	
	return 0;
}
ISR(INT0_vect)
{
	T[counter] = TCNT0;
	TCNT0 = 0;
	
	counter++;
	counter%=4;
	
	TCNT1=0;
	flag=1;
	OCR1A = Ti*8;
	
	
}

ISR(TIMER1_COMPA_vect)
{
	if(flag)
	{
		led_on();
		TCNT1 = 0;
		OCR1A = Ti/3;
		flag = 0;
	}
	
	else 
		led_off();
}


/******************************************************************************/
