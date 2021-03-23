/*
 * UltrasonicSensor.h
 *
 * Created: 3/22/2021 2:01:15 PM
 *  Author: Sebastian Cioata
 */ 


#ifndef ULTRASONICSENSOR_H_
#define ULTRASONICSENSOR_H_

volatile float pulse = 0;
volatile int i = 0;

ISR(INT0_vect)
//interrupt service routine for external interrupt 0
{
	if (i==1) 
	// when logic changes from HIGH to LOW
	
	{
		TCCR1B=0; 
		// disabling the counter
		
		pulse=TCNT1;
		// store the count value
	
		pulse=pulse/932.8;
		pulse=pulse+1;
		// converting the count value to centimeters and adjusting the value
		
		TCNT1=0;
		//resetting the counter memory
		i=0;
	}
	if (i==0)
	// when logic changes from HIGH to LOW
	
	{
		TCCR1B|=(1<<CS10);
		// enabling the counter
		
		i=1;
	}
}




#endif /* ULTRASONICSENSOR_H_ */