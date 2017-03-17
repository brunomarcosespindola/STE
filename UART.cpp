/*
 * UART.cpp
 *
 *  Created on: 15 de mar de 2017
 *      Author: aluno
 */

#include "UART.h"
#include <avr/io.h>

UART::UART(int br, int db, int pr, int sb)
:_baudrate(br),_databits(db),_parity(pr),_stopbits(sb)
{   //configura o baudrate
	UBRR0=(F_CPU / (16ul*_baudrate)) -1;
	//liga o tx e o rx
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); // Enable receiver and transmitter
	//set frame:8N1
	UCSR0C = (3<<UCSZ00);

	// TODO Auto-generated constructor stub

}

UART::~UART() {
	// TODO Auto-generated destructor stub
}
void UART::put (unsigned char data){

	//Wait for empty transmit buffer
	while ( !( UCSR0A & (1<<UDRE0)) );
	//Put data into buffer, sends the data
	UDR0 = data;

}


unsigned char UART::get(){

	//wait until data is received
	while ( !( UCSR0A & (1<<RXC0)) );

	return UDR0;
}
