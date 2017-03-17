#include <util/delay.h>
#include <stdio.h>
#include <avr/io.h>
#include "UART.h"

UART uart;
char pin = 3;
char pin_botao=4;
const unsigned char led_mask = (1 << pin);
const unsigned char botao_mask = (1 << pin_botao);
unsigned char i=0;

unsigned long tempo = 100;

void acende_led(){
    PORTB = PORTB | led_mask;

}

void apaga_led(){
    PORTB = PORTB & ~led_mask;

}

void setup(){
    //DDRB = 0x20;
    //pinMode(pin, OUTPUT);

    DDRB = DDRB | led_mask;
    DDRB = DDRB & ~(botao_mask);
}

bool le_botao(){
    return (PINB & botao_mask);
}

void loop(){

	uart.put(uart.get());

if (le_botao()){
    apaga_led();
}
else{
    acende_led();
}

//    i=PINB;
//    i= i & botao_mask;
//    if(i==botao_mask){
//        apaga_led();
//    }
//    else{
//        acende_led();
//    }

}

//void loop_pisca_led(){
//
//        acende_led();
//        _delay_ms(tempo);
//        apaga_led();
//        _delay_ms(tempo);
//}

int main(){
    setup();

    while(true){
        loop();

    }
}




