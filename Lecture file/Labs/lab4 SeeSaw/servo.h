/**
	@author Thomas Grunenberg
	@version 0.1
	@file servo.h
	@brief Functions to control a servo motor over PB1
*/

#ifndef SERVO_H
#define SERVO_H

#include <stdint.h>

void servo_init(void);

void servo_setPos(uint8_t pos);

uint8_t servo_getPos(void);


#endif
