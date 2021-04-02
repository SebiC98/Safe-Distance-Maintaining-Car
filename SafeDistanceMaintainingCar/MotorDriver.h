/*
 * MotorDriver.h
 *
 * Created: 3/23/2021 11:30:23 AM
 *  Author: Sebastian
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

void controlMotors(unsigned int pulse){
	if(pulse <=5){
		OCR2A = 255;
		//motor stopped, duty cycle 0%
		
		}else if(pulse>5 && pulse <=25){
		OCR2A = 127;
		// duty cycle 50%
		}else if(pulse >25){
		OCR2A = 0;
		// duty cycle 100%
	}
}


#endif /* MOTORDRIVER_H_ */