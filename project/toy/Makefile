COMMON_OBJECTS 	=
CPU 		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../project/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: toy.elf

install:
	cd ../timerLib/ && make install

toy.elf: ${COMMON_OBJECTS} buzzer.o interrupts.o led.o switches.o uimain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a


load: toy.elf
	msp430loader.sh toy.elf

clean:

	rm -f *.o *.elf
