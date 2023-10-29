/*
 * Antonin Kulyk - LPC gpio salida
Una famosa empresa de calzados a incorporado a sus zapatillas 10 luces leds comandadas por un microcontrolador LPC1769
y ha pedido a su grupo de ingenieros que diseñen 2 secuencias de luces que cada cierto tiempo se vayan intercalando
(secuencia A - secuencia B- secuencia A- ... ). Como todavía no se ha definido la frecuencia a la cual va a funcionar
el CPU del microcontrolador, las funciones de retardos que se incorporen deben tener como parametros de entrada variables
que permitan modificar el tiempo de retardo que se vaya a utilizar finalmente. Se pide escribir el código que resuelva este pedido,
considerando que los leds se encuentran conectados en los puertos P0,0 al P0.9. Adjuntar el archivo .c bajo el nombre
"eje1ApellidoDelEstudiante.c"
 */

#include "LPC17xx.h"

uint32_t delay(uint32_t time);

int main(void) {

	uint32_t reloj = SystemCoreClock

    LPC_GPIO0 -> FIODIR |= (0b1111111111<<0); //define 10 led pin as output

    int seq[2]={0b0101010101,0b1010101010}; //2 sequences of 10 led


    while(1) {

    	for(int i = 0; i<2; i++){

    		LPC_GPIO0->FIOSET |= (seq[i]<<0);
    		delay(reloj);
    		LPC_GPIO0->FIOCLR |= (seq[i]<<0);
    		delay(reloj);
    	}


    }
    return 0 ;
}

uint32_t delay(uint32_t time){

	for(time =0; time<6000000; time++){};

}
