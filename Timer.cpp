/*
 * Timer.cpp
 *
 *  Created on: 24 de mar de 2017
 *      Author: aluno
 */

#include "Timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
unsigned long long Timer::_ticks=0;

Timer::Timer(Hertz freq) {
	// TODO Auto-generated constructor stub
TCCR0A=0x00;
TCCR0B=0x05; //div 1024
TIMSK0= 0x01; //liga int de ov
TCNT0= 0xF0;

}

Milliseconds Timer::millis() {
// VERSAO ERRADA
	isr_handler();
	return _ticks;
}
Microseconds Timer::micros() {

}

void Timer::delay(Milliseconds ms) {

}
void Timer::udelay(Microseconds us) {

}

void Timer::isr_handler(){
	TCNT0= 0xF0;
	_ticks ++;
}

ISR(TIMER0_OVF_vect){
	Timer::isr_handler();
}
