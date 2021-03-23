/*
 * SafeDistanceMaintainingCar.c
 *
 * Created: 3/22/2021 1:04:26 PM
 *  Author: Sebastian Cioata
 */ 



#define F_CPU 16000000UL 
//controller crystal frequency

#include <util/delay.h>
//header to enable the delay function

#include <avr/io.h>
//header to enable the control over pins

#include <avr/interrupt.h>
//header to enable the control over interrupts

#include "UltrasonicSensor.h"
//header with the code for the Ultrasonic Sensor

#include "UART.h"
//header with the code for the Universal Synchronous/Asynchronous Receiver/Transmitter 



int main(void)
{

	UART_Init();
	
	DDRD |= ((1 << DDD4) | (1 << DDD7));     // set pin 3 of Port B as output
	
	EICRA |= ((1 << ISC00) | (1 << ISC10));    // set INT0 to trigger on ANY logic change
	EIMSK |= ((1 << INT0) | (1 << INT1));     // Turns on INT0
	
	TCCR1A = 0;

	sei();                    // turn on interrupts
	
	while (1){
		
		

		_delay_ms(1000);
		PORTD |= (1 << PD7);     // set pin 3 of Port B high
		_delay_us(50);
		PORTD &= ~(1 << PD7);    // set pin 3 of Port B low
		Serial_print_text("Distance = $");
		Serial_print_val(pulse);
		Serial_print_text("cm\r$");
		
	

		
		
	}
}
