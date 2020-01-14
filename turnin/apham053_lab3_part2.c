/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #2
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

int main(void) {
    DDRA = 0x00;
    DDRC = 0xFF;
    PORTA = 0xFF;
    PORTC = 0x00;
    
    unsigned char C = 0x00;

    while (1) {
	unsigned char A = PINA & 0xFF; //set A to PINA	    
	    switch(A) {
		case 0x00:
		C = SetBit(C, 6, 1); // low fuel light
		break;
		
		case 0x01:
		case 0x02:
		C = SetBit(C, 6, 1);
		C = SetBit(C, 5, 1);
		break;

		case 0x03:
		case 0x04:
		C = SetBit(C, 6, 1);
                C = SetBit(C, 5, 1);
		C = SetBit(C, 4, 1);
                break;

		case 0x05:
                case 0x06:
                C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
		C = SetBit(C, 3, 1);
                break;

		case 0x07:
                case 0x08:
		case 0x09:
                C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
                C = SetBit(C, 3, 1);
		C = SetBit(C, 2, 1);
                break;
	        
		case 0x0A:
                case 0x0B:
                case 0x0C:
                C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
                C = SetBit(C, 3, 1);
                C = SetBit(C, 2, 1);
		C = SetBit(C, 1, 1);
                break;

		case 0x0D:
		case 0x0E:
		case 0x0F:
		C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
                C = SetBit(C, 3, 1);
                C = SetBit(C, 2, 1);
                C = SetBit(C, 1, 1);
		C = SetBit(C, 0, 1);
		break;			
	    }
	
	PORTC = C;
	C = 0x00;

    }

    return 1;
	}
