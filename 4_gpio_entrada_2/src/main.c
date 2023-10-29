/*
 * Antonin Kulyk - ED3
Considerando pulsadores normalmente abiertos conectados en un extremo a masa y en el otro directamente
a las entradas P0.0 y p0.1. Realizar un programa que identifique en una variable cual o cuales
pulsadores han sido presionados. Las identificaciones posibles a implementar en esta variable
van a ser "ninguno", "pulsador 1", "pulsador 2", "pulsador 1 y 2".
 */

#include "LPC17xx.h"
#include <stdio.h>
#include <string.h>

void delay(uint32_t time);

int main(void) {

	char resulto[14];

	LPC_GPIO0->FIODIR0 &= ~(0b11<<0); // entrada

    LPC_PINCON->PINMODE0 |= (0b1111<<0); //Resistencia de pull up


    while(1) {

    	switch(LPC_GPIO0->FIOPIN &= (0b11<<0)){

    	case 0b00:
    		strcpy(resulto ,"ninguno");
    		break;

    	case 0b01:
    		strcpy(resulto ,"pulsador 1");
    		break;

    	case 0b10:
    		strcpy(resulto ,"pulsador 2");
    		break;

    	case 0b11:
    		strcpy(resulto ,"pulsador 1 y 2");
    		break;

    	printf("%s",resulto);

    	}
    }
    return 0;
}

