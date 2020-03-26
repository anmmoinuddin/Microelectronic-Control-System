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
	@file init.h
	@brief Init function for the I/O
*/

#ifndef INIT
#define INIT

#define LOW  0
#define HIGH 1
 
#define SPI_SCLK  PD5
#define SPI_DATA  PD6
#define SPI_CS    PD7
 
#define SPI_PORT  PORTD


void init(void);


#endif
