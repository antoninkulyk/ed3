/*
 * Antonin Kulyk - ED3
En los pines P2.0 a P2.7 se encuentra conectado un display de 7 segmentos.
Utilizando la variable numDisplay [10] ={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67}
que codifica los números del 0 a 9 para ser mostrados en el display, realizar un programa que muestre
indefinidamente la cuenta de 0 a 9 en dicho display.
 */

#include "LPC17xx.h"

void delay(uint32_t time);

int main(void) {

	uint32_t reloj = SystemCoreClock;
	int numDisplay[10] ={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};

    LPC_GPIO2 -> FIODIR0 |= (0b11111111<<0); //define 8 pin as display segments output //FIODIR2

    while(1) {
    	for(int i = 0; i<10; i++){

    		LPC_GPIO2->FIOSET0 &= (numDisplay[i]);

    		LPC_GPIO2->FIOSET0 |= (numDisplay[i]);

    		delay(reloj);
    	}


    }
    return 0 ;
}

void delay(uint32_t time){

	for(time =0; time<6000000; time++){};

}
