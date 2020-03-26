/**
	@author Thomas Grunenberg
	@version 0.1
	@file motor.h
	@brief Functions to control the motor / the rotor speed
*/

#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

void motor_init(void);

void motor_setSpeed(uint8_t spd);

uint8_t motor_getSpeed(void);


#endif
