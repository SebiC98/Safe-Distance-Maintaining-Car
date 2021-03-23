/*
 * UART.h
 *
 * Created: 3/22/2021 2:45:18 PM
 *  Author: Sebastian Cioata
 */ 


#ifndef UART_H_
#define UART_H_


void UART_Init()
{

	UCSR0B |= ((1<< RXEN0) | (1<< TXEN0));
	// enable receive and transmit
	
	UBRR0H = 0;
	UBRR0L = 103;
	// baud rate 9600
}

void UART_Transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0) )){
	// wait for empty transmit buffer
		
	}
	UDR0 = data;
	// put data into buffer
}

void Serial_print_text(char* text){
	unsigned char i=0;
	while (text[i] != '$'){
		UART_Transmit(text[i]);
		i++;
	}
}
// function to print text on serial monitor

void Serial_print_val(unsigned int val){
	unsigned char digit;
	unsigned int p = 10;
	if(val < 10)
	UART_Transmit(val%10 + 0x30);
	else{
		while(val / p > 10)
		p *= 10;
		while(p){
			digit = (val / p) % 10;
			p /= 10;
			digit += 0x30;
			UART_Transmit(digit);
		}
	}
}

// function to print value on serial monitor


#endif /* UART_H_ */