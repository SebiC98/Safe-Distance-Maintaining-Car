/*
 * UltrasonicSensor.h
 *
 * Created: 3/22/2021 2:01:15 PM
 *  Author: Sebastian Cioata
 */ 

#ifndef ULTRASONICSENSOR_H_
#define ULTRASONICSENSOR_H_

volatile float pulse=0;
volatile int i=0;
const unsigned char st_c=1;
const double scalec=932.8;
ISR(INT0_vect)
//interrupt service routine for external interrupt 0
{
	if (i==1) 
	//when logic changes from HIGH to LOW
	{
		TCCR1B=0; 
		//disable the counter
		
		pulse=TCNT1;
		//store the count value
	
		pulse=pulse/scalec+st_c;
		//convert the count value to centimeters & adjust the value
		
		TCNT1=0;
		//reset the counter memory
		
		i=0;
	}
	if (i==0)
	//when logic changes from HIGH to LOW
	{
		TCCR1B|=(1<<CS10);
		//enabe the counter
		
		i=st_c;
	}
}

#endif /* ULTRASONICSENSOR_H_ */
