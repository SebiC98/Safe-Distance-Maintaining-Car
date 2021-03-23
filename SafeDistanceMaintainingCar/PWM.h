/*
 * PWM.h
 *
 * Created: 3/23/2021 12:32:07 PM
 *  Author: Sebastian
 */ 


#ifndef PWM_H_
#define PWM_H_


void pwm_init()
{
	
	TCCR2A |= (1<<COM2A1) | (1<<COM2A0) | (1<<WGM21) | (1<<WGM20);
	// initialize TCCR2 as: fast pwm mode, non inverting
	
	TCCR2B |= (1<<CS21);
    // clkT2S/8 prescale
	
	DDRB |= (1<<PB3);
	// OC2RA pin made as output
}


#endif /* PWM_H_ */