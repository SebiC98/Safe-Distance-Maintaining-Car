/*
 * SafeDistanceMaintainingCar.c
 *
 * Created: 3/22/2021 1:04:26 PM
 *  Author: Sebastian Cioata
 */ 



#define F_CPU 16000000UL 
// controller crystal frequency

#include <util/delay.h>
// header to enable the delay function

#include <avr/io.h>
// header to enable the control over pins

#include <avr/interrupt.h>
// header to enable the control over interrupts

#include "UltrasonicSensor.h"
// header with the code for the Ultrasonic Sensor

#include "UART.h"
// header with the code for the Universal Asynchronous Receiver/Transmitter 

#include "MotorDriver.h"
// header with the code for the  Motor Driver

#include "PWM.h"
// header with the code for the PWM signal


int main(void)
{
	pwm_init();
	UART_Init();
	
	DDRB |= ((1<< DDB0) | (1<<DDB2) | (1 << DDB3)); 
	//set pins 0,2 and 3 of port B as output
	
	DDRD |= ((1 << DDD4) | (1 << DDD7));     
	// set pins 4 and 7 of port D as output
	
	EICRA |= ((1 << ISC00) | (1 << ISC10));    
	// set INT0 to trigger on ANY logic change
	
	EIMSK |= ((1 << INT0) | (1 << INT1));     
	// turns on INT0
	
	TCCR1A = 0;
	// initialize the counter

	sei();
	// turn on interrupts
	
	while (1){
		  
		PORTD |= (1 << PD7);     
		// set pin 7 of Port D high
		
		_delay_us(50);
		
		PORTD &= ~(1 << PD7);    
		// set pin 7 of Port D low
		
		Serial_print_text("Distance = $");
		Serial_print_val(pulse);
		Serial_print_text("cm\r$");
		
		controlMotors(pulse);
	
		_delay_ms(1000);
			
	}
}
