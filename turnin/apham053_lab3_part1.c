/*	Author: apham053
 *  Partner(s) Name: Steven Rodriguez
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: Count the number of 1s on ports A and B and output *      that number on port C. 
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00;
    DDRB = 0x00;
    DDRC = 0xFF;
    PORTA = 0xFF;
    PORTB = 0xFF;
    PORTC = 0x00;

    unsigned char num = 0x00; // var to keep track of total number of 1's
 //   unsigned char B = 0x00; 

    while (1) {

	num = (PINA & 0x01) + (PINA >> 1 & 0x01) + (PINA >> 2 & 0x01) + (PINA >> 3 & 0x01) + (PINA >> 4 & 0x01) + (PINA >> 5 & 0x01) + (PINA >> 6 & 0x01) + (PINA >> 7 & 0x01); // shift PINA down 7 times																						    // to evaluate each PIN
																						// by ANDING with 00000001
	num = num + (PINB & 0x01) + (PINB >> 1 & 0x01) + (PINB >> 2 & 0x01) + (PINB >> 3 & 0x01) + (PINB >> 4 & 0x01) + (PINB >> 5 & 0x01) + (PINB >> 6 & 0x01) + (PINB >> 7 & 0x01);

        PORTC = num;		

    }

    return 1;
}
