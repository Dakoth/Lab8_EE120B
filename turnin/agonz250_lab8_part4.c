/*	Author: agonz250 
 *  Partner(s) Name: 
 *	Lab Section: 028 
 *	Assignment: Lab # 8  Exercise #4
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

	unsigned char tmpB = 0x00;

	unsigned short my_short = 0; //10 bit input from ADC

	//unsigned short MAX = 0x187; //0110000111, (391) max value observed from phone flashlight 

	//have to call this 
	ADC_init();
    /* Insert your solution below */
    while (1) {
	    //PORTA = ~PINA;
	    //Calculations 
	    tmpB = 0;
	    my_short = ADC; //10 bits to 8 bits 

	    //Values based on dividing MAX(391)/8 
	    if (my_short >= 49) { //1
		    tmpB = (tmpB & 0xFF) | 0x01;
	    }
	    if (my_short >= 98) { //2
		    tmpB = (tmpB & 0xFF) | 0x02;
	    }
            if (my_short >= 146) { //3
		    tmpB = (tmpB & 0xFF) | 0x04;
	    }
	    if (my_short >= 195) { //4
		    tmpB = (tmpB & 0xFF) | 0x08;
	    }
	    if (my_short >= 244 ) { //5
		    tmpB = (tmpB & 0xFF) | 0x10;
	    }
	    if (my_short >= 293) { //6
		    tmpB = (tmpB & 0xFF) | 0x20;
	    }
	    if (my_short >= 342 ) { //7
		    tmpB = (tmpB & 0xFF) | 0x40;
	    }
	    if (my_short >= 391 ) { //8
		    tmpB = (tmpB & 0xFF) | 0x80;
	    }

	   // if (my_short >= MAX) {
	//	   PORTB = 1;
	  //  }
	    //Setting output 
	    PORTB = tmpB;

	    tmpB = 0;
	    //PORTD = tmpD;
    }
    return 1;
}
