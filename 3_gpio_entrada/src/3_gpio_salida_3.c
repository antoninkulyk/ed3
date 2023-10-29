/*
 * Antonin Kulyk - ED3
Configurar el pin P0.4 como entrada digital con resistencia de pull down y utilizarlo
para decidir si el valor representado por los pines P0.0 al P0.3 van a ser sumados o restados
al valor guardado en la variable "acumulador".El valor inicial de "acumulador" es 0.
 */

#include "LPC17xx.h"

void delay(uint32_t time);

int main(void) {

	uint32_t reloj = SystemCoreClock;

	int acumulador = 0;
	int temp = 0;

    LPC_GPIO0->FIODIR0 &= ~(0b11111<<0); //pin P0.4 como entrada
    LPC_PINCON->PINMODE0 |= (0b1<<4); //Resistencia de pull down


    while(1) {

    	temp =0;

    	for(int i =0; i<4; i++){
    		temp = temp + (LPC_GPIO0->FIOPIN0 &= (1<<i));
    	}

    	if(LPC_GPIO0->FIOPIN0 & (1<<4)){

    		acumulador = acumulador + temp;

    	}else{

    		acumulador = acumulador - temp;
    	}


    }
    return 0 ;
}

void delay(uint32_t time){

	for(time =0; time<6000000; time++){};

}
