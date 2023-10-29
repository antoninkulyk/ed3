//Autor: J. Martin Ayarde
//Descripción: Este código genera una señal cuadrada mediante el timer2 en modo Match
//             y es utilizada para generar los eventos que captura el Timer 0 en modo Capture.

#include "LPC17xx.h"

void confTimerMatch(void);
void confTimerCapt(void);
uint32_t aux = 0;

int main(void) {

	confTimerCapt();
	confTimerMatch();
	while(1){}
	return 0;
}


void confTimerCapt(void){
	LPC_SC->PCONP       |= (1<<1);
	LPC_SC->PCLKSEL0    |= (1<<2);
	LPC_PINCON->PINSEL3 |= (3<<20);        //pag. 120
	LPC_TIM0->CCR       |= (1<<1)|(1<<2);  //pag. 508
	LPC_TIM0->TCR        = 3;              //pag. 505
	LPC_TIM0->TCR       &= ~(1<<1);
	NVIC_EnableIRQ(TIMER0_IRQn);
	return;
}

void confTimerMatch(void){
	LPC_SC->PCONP       |= (1<<22);
	LPC_PINCON->PINSEL0 |= (3<<18);  // pag. 118
	LPC_TIM2->EMR       |=(3<<10);   // pag. 509
	LPC_TIM2->MR3        = 70000000;
	LPC_TIM2->MCR       |= (1<<10);   // pag. 507
	LPC_TIM2->MCR       &= ~(1<<9);  // pag. 507
	LPC_TIM2->TCR        = 3;        // pag. 505
	LPC_TIM2->TCR       &= ~(1<<1);
	return;
}

void TIMER0_IRQHandler(void) //ISR del timer0
{
	static uint8_t i = 0;
	aux = LPC_TIM0->CR0; //Variable auxiliar para observar el valor del registro de captura

	LPC_TIM0->IR|=1; //Limpia bandera de interrupción
	return;
}
