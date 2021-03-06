/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #3
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
    DDRC = 0xFF;
    PORTA = 0xFF;
    PORTC = 0x00;
    
    unsigned char C = 0x00;

    while (1) {
	unsigned char A = (PINA & 0xFF); //set A to PINA	    
	    
		if (GetBit(A, 4) && GetBit(A,5)) {   // check if driver is seated and key is in ignite, if both yes (1)
                    if(!(GetBit(A, 6))) {            // check if seatbelt fastened, if no (0), logical NOT to 1 so the body execute
                        C = SetBit(C, 7, 1);         
                    }
                }
		
		A = A << 4;    // bit shift to the left 4 to account for seatbelt, seated, and key in ignition since I used a switch statement
		
		switch(A) {
		case 0x00:
		C = SetBit(C, 6, 1); // low fuel light
		break;
		
		case 0x10:
		case 0x20:
		C = SetBit(C, 6, 1);
		C = SetBit(C, 5, 1);
		break;

		case 0x30:
		case 0x40:
		C = SetBit(C, 6, 1);
                C = SetBit(C, 5, 1);
		C = SetBit(C, 4, 1);
                break;

		case 0x50:
                case 0x60:
                C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
		C = SetBit(C, 3, 1);
                break;

		case 0x70:
                case 0x80:
		case 0x90:
                C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
                C = SetBit(C, 3, 1);
		C = SetBit(C, 2, 1);
                break;
	        
		case 0xA0:
                case 0xB0:
                case 0xC0:
                C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
                C = SetBit(C, 3, 1);
                C = SetBit(C, 2, 1);
		C = SetBit(C, 1, 1);
                break;

		case 0xD0:
		case 0xE0:
		case 0xF0:
		C = SetBit(C, 5, 1);
                C = SetBit(C, 4, 1);
                C = SetBit(C, 3, 1);
                C = SetBit(C, 2, 1);
                C = SetBit(C, 1, 1);
		C = SetBit(C, 0, 1);
		break;
	    }
	
	PORTC = C;
	C = 0x00;   // reset

    }

    return 1;
	}
