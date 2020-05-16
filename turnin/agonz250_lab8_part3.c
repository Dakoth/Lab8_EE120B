/*	Author: agonz250 
 *  Partner(s) Name: 
 *	Lab Section: 028 
 *	Assignment: Lab # 8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//adc stuff 
void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // input

	DDRB = 0xFF; PORTB = 0X00; //output
	DDRD = 0xFF; PORTD = 0x00;

	//unsigned char tmpC = 0x00;
	//unsigned char tmpD = 0x00; 

	unsigned short my_short = 0; //10 bit input from ADC
	//unsigned char my_char = 0;

	unsigned short MAX = 0x187; //0110000111; //max value observed from phone flashlight 

	//have to call this 
	ADC_init();
    /* Insert your solution below */
    while (1) {
	    //PORTA = ~PINA;
	    //Calculations 
	    my_short = ADC; //10 bits to 8 bits 
	   // my_char = (char)my_short; //now 8 lower bits
	    //tmpD = (char)(my_short >> 8); //Should be 2 upper bits

	    if (my_short >= MAX) {
		   PORTB = 1;
	    }
	    else {
		    PORTB = 0;
	    } 
	    //Setting output 
	    //PORTB = my_char;
	    //PORTD = tmpD;
    }
    return 1;
}
