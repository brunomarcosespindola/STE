//#include <util/delay.h>
#include <stdio.h>
#include <avr/io.h>
#include "UART.h"
#include "GPIO.h"
#include "Timer.h"

unsigned char i = 0;

unsigned long tempo = 100;

UART uart(19200, UART::DATABITS_8, UART::PARITY_NONE, UART::STOPBITS_1);

GPIO led(11, GPIO::OUTPUT);
GPIO botao(12, GPIO::INPUT);

Timer timer(1000);

void acende_led() {
	led.set(1);
}

void apaga_led() {
	led.set(0);
}

void setup() {


}

bool le_botao() {
	return botao.get();
}

char message[8];
void loop() {

	//uart.put(uart.get());

//	if (le_botao()) {
//		apaga_led();
//	} else {
//		acende_led();
//	}

led.set(botao.get());
sprintf(message,"Timer %d\n",timer.millis());
uart.puts(message);

}

int main() {
	setup();

	while (true) {
		loop();

	}
}

