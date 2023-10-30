/*
 * Antonin Kulyk - ED3
Realizar un programa que configure el puerto P2.0 y P2.1 para que provoquen una interrupción
por flanco de subida para el primer pin y por flanco de bajada para el segundo.
Cuando la interrupción sea por P2.0 se enviará por el pin P0.0 la secuencia de bits 010011010.
Si la interrupción es por P2.1 se enviará por el pin P0.1 la secuencia 011100110.
Las secuencias se envían únicamente cuando se produce una interrupción,
en caso contrario la salida de los pines tienen valores 1 lógicos.
¿que prioridad tienen configuradas por defecto estas interrupciones?
 */

#include "LPC17xx.h"
#include <stdio.h>
#include <string.h>

void retardo(uint32_t conta);
void ConfigGPIOInt(void);

int seq[2]={0b010011010, 0b011100110};
uint32_t tiempo = 100000;


int main(void){


	LPC_GPIO2->FIODIR &= ~(0b11<<0); //P2.0 y P2.1 como entrada
	LPC_GPIO0->FIODIR |= 0b11<<0; //P0.0 y P0.1 como salida

	ConfigGPIOInt();

		while(1){

		}

		return 0;
}

void ConfigGPIOInt(void){

	LPC_GPIO0->IO2IntEnR |= 0b01<<0;
	LPC_GPIO0->IO2IntEnF |= 0b10<<0;
	NVIC_EnableIRQ(EINT3_IRQn);

}

void EINT3_IRQHandler(void){

	if(LPC_GPIOINT->IO2IntStatR & (1<<0)){

		for(int i=0; i<9; i++){
			LPC_GPIO0->FIOSET = seq[1] & (1<<i);
			retardo(tiempo);
			LPC_GPIO0->FIOCLR = (0b1<<0);
		}
	}

	if(LPC_GPIOINT->IO2IntStatF & (1<<0)){

		for(int i=0; i<9; i++){
			LPC_GPIO0->FIOSET = seq[2] & (1<<i);
			retardo(tiempo);
			LPC_GPIO0->FIOCLR = (0b1<<0);
		}
	}
}

void retardo(uint32_t conta){
	for(int i=0; i<conta; i++);
}

