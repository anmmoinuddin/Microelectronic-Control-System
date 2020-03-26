################################################################################
# Makefile for MyAVR Programm                                                  #
# First test program                                                           #
################################################################################


# Options ######################################################################
PORT=/dev/ttyUSB_MySmartUSB
PROGRAMMER=avr911
TARGET_CPU=atmega88pa
TARGET_PROCESSOR=m88p
CFLAGS=-Wall -Os -c -mmcu=$(TARGET_CPU)
LDFLAGS=-Os -mmcu=$(TARGET_CPU) -o

# Program ######################################################################
all: main.hex

main.hex: main.elf
	avr-objcopy -O ihex main.elf main.hex

main.elf: main.o init.o servo.o irsensors.o
	avr-gcc $(LDFLAGS) main.elf main.o init.o servo.o irsensors.o

main.o: main.c
	avr-gcc $(CFLAGS) main.c

init.o: init.c init.h
	avr-gcc $(CFLAGS) init.c

servo.o: servo.c servo.h
	avr-gcc $(CFLAGS) servo.c

irsensors.o: irsensors.c irsensors.h
	avr-gcc $(CFLAGS) irsensors.c

program: main.hex
	avrdude -P $(PORT) -p $(TARGET_PROCESSOR) -c $(PROGRAMMER) -Uflash:w:main.hex:i


# Clean ########################################################################
clean:
	rm -f *.o *.elf *.hex *~ *.bak
