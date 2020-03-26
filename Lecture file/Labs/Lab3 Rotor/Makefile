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

main.elf: main.o init.o motor.o poti.o led.o
	avr-gcc $(LDFLAGS) main.elf main.o init.o motor.o poti.o led.o

main.o: main.c
	avr-gcc -Wall $(CFLAGS) main.c

init.o: init.c init.h
	avr-gcc -Wall $(CFLAGS) init.c

motor.o: motor.c motor.h
	avr-gcc -Wall $(CFLAGS) motor.c

poti.o: poti.c poti.h
	avr-gcc -Wall $(CFLAGS) poti.c

led.o: led.c led.h
	avr-gcc -Wall $(CFLAGS) led.c

program: main.hex
	avrdude -P $(PORT) -p $(TARGET_PROCESSOR) -c $(PROGRAMMER) -Uflash:w:main.hex:i


# Clean ########################################################################
clean:
	rm -f *.o *.elf *.hex *~ *.bak
