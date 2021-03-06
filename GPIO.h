/*
 * GPIO.h
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */

#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>


class GPIO {
public:
	enum PortDirection_t {
		INPUT = 0, OUTPUT = 1
	};

	GPIO(int pin, PortDirection_t dir);
	~GPIO();

	bool get();
	void set(bool val);

private:
	unsigned char mask;
	volatile uint8_t * ponteiro;
	volatile uint8_t * pointer_port;
	volatile uint8_t * pointer_pin;
};
#endif /* GPIO_H_ */
