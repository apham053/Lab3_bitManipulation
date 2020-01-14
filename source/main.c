/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #5
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

    DDRD = 0x00;
    DDRB = 0xFE;  // setting portB(7-1) to outputs and portB0 to input
    PORTD = 0xFF;
    PORTB = 0x01;

    unsigned char sum = 0x00;
    unsigned char B = 0x00;

    while (1) {
	unsigned char D = (PIND & 0xFF); // read PIND
	unsigned char B0 = (PINB & 0x01); // read PINB0

	sum = D + B0;

	if (sum >= 0x46) {
	    SetBit(B, 1, 1);    
	}

	else if ((sum < 0x46) && (sum > 0x05)) {
	    SetBit(B, 2, 1);
	}

	PORTB = B;
	B = 0x00;
    }
	

    return 1;
}
