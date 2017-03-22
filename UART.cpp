/*
 * UART.cpp
 *
 *  Created on: 15 de mar de 2017
 *      Author: aluno
 */

#include "UART.h"
#include <avr/io.h>

UART::UART(unsigned long br,DataBits_t db,ParityBits_t pr,StopBits_t sb)
: _baudrate(br), _databits(db),_parity(pr),_stopbits(sb)

{   //configura o baudrate
	UBRR0=(F_CPU / (16ul*_baudrate)) -1;
	//liga o tx e o rx
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); // Enable receiver and transmitter
	//set data bits

	if(_databits==DATABITS_9){
	//--------FAZER ESSA PARTE
		UCSR0C= (UCSR0C & ~(7<< UCSZ00)) | (_databits<< UCSZ00);
	}
	else{
		UCSR0C= (UCSR0C & ~(3<< UCSZ00)) | (_databits<< UCSZ00);
	}

	//set parity
	UCSR0C= (UCSR0C & ~(3<< UPM00)) | (_parity<< UPM00);
	//set stopbits
	UCSR0C= (UCSR0C & ~(1<<USBS0)) | (_stopbits << USBS0);

	//set frame:8N1
	//UCSR0C = (3<<UCSZ00);

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
