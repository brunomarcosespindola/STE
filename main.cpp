//#include <util/delay.h>
#include <stdio.h>
#include <avr/io.h>
#include "UART.h"
#include "GPIO.h"


unsigned char i=0;

unsigned long tempo = 100;

UART uart(19200,UART::DATABITS_8,UART::PARITY_NONE ,UART::STOPBITS_1);

GPIO led(11,GPIO::OUTPUT);

GPIO botao(12,GPIO::INPUT);
void acende_led(){
//    PORTB = PORTB | led_mask;
	led.set(1);
}

void apaga_led(){
//    PORTB = PORTB & ~led_mask;
	led.set(0);
}

void setup(){
    //DDRB = 0x20;
    //pinMode(pin, OUTPUT);

//    DDRB = DDRB | led_mask;
//    DDRB = DDRB & ~(botao_mask);
}

bool le_botao(){
    return botao.get();
}

void loop(){

	//uart.put(uart.get());

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




