/*
 * GPIO.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#include "GPIO.h"
#include <avr/io.h>

GPIO::GPIO(int pin, PortDirection_t dir) {
	// TODO Auto-generated constructor stub
	//CALCULAR A MASCARA

	if (pin >= 0 && pin <= 7) {
		mask = (1 << pin);
		ponteiro = &DDRD;
		pointer_port = &PORTD;
		pointer_pin = &PIND;

	} else if (pin >= 8 && pin <= 13) {
		mask = (1 << (pin - 8));
		ponteiro = &DDRB;
		pointer_port = &PORTB;
		pointer_pin = &PINB;

	} else if (pin >= 14 && pin <= 19) {
		mask = (1 << (pin - 14));
		ponteiro = &DDRC;
		pointer_port = &PORTC;
		pointer_pin = &PINC;
	} else {
		//TRATAR ERRO
	}

	if (dir) {
		*ponteiro = *ponteiro | mask;
	} else {
		*ponteiro = *ponteiro & ~(mask);
	}

}

GPIO::~GPIO() {
}

bool GPIO::get() {
	return (*pointer_pin & mask);

}

void GPIO::set(bool val) {
	if (val) {
		*pointer_port = *pointer_port | mask;
	} else {
		*pointer_port = *pointer_port & ~mask;
	}

}
