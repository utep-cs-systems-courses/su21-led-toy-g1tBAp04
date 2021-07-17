#makefile configuration

COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

all: run.elf

##only blink##
blink.elf: ${COMMON_OBJECTS} blinkMain.o stateMachines.c led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

##blink/button##
run.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o blinkMain.o buzzer.o switches.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

#.o files
wdInterruptHandler.o: stateMachines.h
switches.o: switches.h
stateMachines.o: led.h stateMachines.h
led.o: led_s.s led.h
buzzer.o: buzzer.h

load: blink.elf
	msp430loader.sh blink.elf

load2: run.elf
	msp430loader.sh run.elf

clean:
	rm -f *.o *.elf *# *~
