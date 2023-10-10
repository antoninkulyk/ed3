/*

Kulyk Antonin - Carrera Electronica
//Blink Led con interrupcion por GPIO con el switch integrado para aumentar la frecuencia del Blink.

*/


#include "LPC17xx.h"

#define REDLED 		(1<<22)
#define GREENLED 	(1<<25)
#define BLUELED 	(1<<26)

#define INPUT		(1<<10)

int tiempo = 2000;

void configGPIO(void);
void configGpioInt(void);

int main(void) {

	configGPIO();
	configGpioInt();
	LPC_GPIO0->FIOCLR |= REDLED;           //LEDs on
	LPC_GPIO3->FIOCLR |= GREENLED;
	LPC_GPIO3->FIOCLR |= BLUELED;

	while(1) {
		LPC_GPIO0->FIOCLR |= REDLED;
		LPC_GPIO3->FIOSET |= GREENLED;
		LPC_GPIO3->FIOSET |= BLUELED;
		delay(tiempo);
		LPC_GPIO0->FIOSET |= REDLED;
		LPC_GPIO3->FIOCLR |= GREENLED;
		LPC_GPIO3->FIOSET |= BLUELED;
		delay(tiempo);
		LPC_GPIO0->FIOSET |= REDLED;
		LPC_GPIO3->FIOSET |= GREENLED;
		LPC_GPIO3->FIOCLR |= BLUELED;
		delay(tiempo);

		if(tiempo<=500){
			tiempo = 2000;               //restart period
		}
	}

    return 0 ;
}

void EINT3_IRQHandler(void) {
	//debounce treating

	if(LPC_GPIOINT->IO2IntStatR & INPUT) { //P0.10 rising
		tiempo -= 140;
		LPC_GPIOINT->IO2IntClr |= INPUT;
	}

}

void configGPIO(void) {
	/*PINSEL*/
	LPC_PINCON->PINSEL1 &= ~(0x3<<12); //P0.22 as GPIO
	LPC_PINCON->PINSEL7 &= ~(0xf<<18); //P3.25,  P3.26 as GPIO
	LPC_PINCON->PINSEL0 &= ~(0x2f<<18); //P0.9, P0.10 as GPIO

	/*FIODIR*/
	LPC_GPIO0->FIODIR |= REDLED;    //P0.22 as output
	LPC_GPIO3->FIODIR |= BLUELED;   //P3.25 as output
	LPC_GPIO3->FIODIR |= GREENLED;  //P3.25 as output

	LPC_GPIO2->FIODIR &= ~(INPUT); //P2.10 as input (switch)


	LPC_PINCON->PINMODE0 &= ~(0x2f<<18); //P0.9 and P0.11 pull-up
	LPC_PINCON->PINMODE4 &= ~(0x3<<20);
}

void configGpioInt(void) {

	LPC_GPIOINT->IO2IntEnR |= INPUT; //P0.10 rising edge interrupt
	LPC_GPIOINT->IO2IntEnF &= ~ (INPUT); //P0.10 falling edge interrupt disable


	NVIC_EnableIRQ(EINT3_IRQn); //ISER0 |= (1<<21) (table 52)
}

void delay(uint32_t times) {
	for(uint32_t i=0; i<times; i++)
		for(uint32_t j=0; j<times; j++);
}
