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

/*
unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}
*/

int main(void) {

    DDRD = 0x00;
    DDRB = 0xFE;  // setting portB(7-1) to outputs and portB0 to input
    PORTD = 0xFF;
    PORTB = 0x01;

    unsigned short totWeight = 0x00;   // total weight will exceen 8 bits, so need to use short data type
    unsigned char B = 0x00;

    while (1) {
	unsigned char D = (PIND & 0xFF); // read PIND
	unsigned char B0 = (PINB & 0x01); // read PINB0
	
	if (D >= 0xFF) {                   // if D exceeds 255, must multiply D by 2 before adding B0 to get accurate total weight
	    totWeight = (D * 2) + B0;
	} 
	
	/*if (D == 0xFF) {          
	    switch(B0) {
		case 0x00:
		totWeight = 510;
		break;
		
		case 0x01:
		totWeight = 511;
		break;
	    }
	}*/

	totWeight = D + B0;           // if D less than 255, do not need to multiply by 2

	if (totWeight >= 0x46) {   // if greater than or equal to 70, set B1 to 1
	    B = SetBit(B, 1, 1);    
	}

	else if ((totWeight < 0x46) && (totWeight > 0x05)) {  // if in bewtween 5 and 70, set B2 to 1
	    B = SetBit(B, 2, 1);
	}

	PORTB = B;
	B = 0x00;
    }
	

    return 1;
}
