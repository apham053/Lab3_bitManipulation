/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description:
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
   return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
              //   Set bit to 1           Set bit to 0
}

unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}

int main(void) {
    DDRA = 0x00;
    DDRB = 0xFF;
    DDRC = 0xFF;
    PORTA = 0xFF;
    PORTB = 0x00;
    PORTC = 0x00;
    
    unsigned char B = 0x00;
    unsigned char C = 0x00;

    while (1) {
	unsigned char A = (PINA & 0xFF); //set A to PINA
	
	B = A >> 4;
	C = A << 4; 
	
	PORTB = B;
	PORTC = C;
	B = 0x00;
	C = 0x00;		    
    }
	

    return 1;
}
