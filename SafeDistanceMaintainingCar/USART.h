/*
 * USAR.h
 *
 * Created: 3/22/2021 2:45:18 PM
 *  Author: Sebastian Cioat?
 */ 


#ifndef USAR_H_
#define USAR_H_


void USART_Init()
{
	//enable receive and transmit
	UCSR0B |= ((1<< RXEN0) | (1<< TXEN0));
	
	//baud rate 9600
	UBRR0H = 0;
	UBRR0L = 103;
}

void USART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0) )){
		
	}
	
	UDR0 = data;
}

void Serial_print_text(char* text){
	unsigned char i=0;
	while (text[i] != '$'){
		USART_Transmit(text[i]);
		i++;
	}
}

void Serial_print_val(unsigned int val){
	unsigned char digit;
	unsigned int p = 10;
	if(val < 10)
	USART_Transmit(val%10 + 0x30);
	else{
		while(val / p > 10)
		p *= 10;
		while(p){
			digit = (val / p) % 10;
			p /= 10;
			digit += 0x30;
			USART_Transmit(digit);
		}
	}
}


#endif /* USAR_H_ */