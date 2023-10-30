/*
 * Antonin Kulyk - ED3
Escribir un programa en C que permita realizar un promedio movil con los últimos 8 datos
ingresados por el puerto 1. Considerar que cada dato es un entero signado y está formado
por los 16 bits menos significativos de dicho puerto. El resultado, también de 16 bits,
debe ser sacado por los pines P0.0 al P0.11 y P0.15 al P0.18.  Recordar que en un promedio
movil primero se descarta (est exclu) el dato mas viejo de los 8 datos guardados, se ingresa un nuevo
dato proveniente del puerto y se realiza la nueva operación de promedio con esos 8 datos
disponibles, así sucesivamente. Considerar el uso de un retardo antes de tomar una nueva muestra
por el puerto.
 */

#include "LPC17xx.h"
#include <stdio.h>
#include <string.h>

void retardo(uint32_t tiempo);

int main(void){

	uint32_t nbrValue = 0;
	uint32_t sum = 0;
	uint32_t promedio = 0;

	LPC_GPIO1->FIODIR &= ~(0xFFFF<<0); //Entrada P1.0 a P1.15
	LPC_GPIO0->FIODIR |= (0xFFF<<0); //El resultado, también de 16 bits, debe ser sacado por los pines P0.0 al P0.11 y P0.15 al P0.18
	LPC_GPIO0->FIODIR |= (0xF<<15);

	int value[16];

	for (int i=0; i<16; i++){ //initialisation de Value
		value[i]= 0b0;
	}

	int datos[8] = {0,0,0,0,0,0,0,0};

		while(1){

			for(int i = 0; i<8; i++){ //Pacours tableau de valeurs

					for(int j = 0; j<16; j++){ //Parcours bits de l'entree

					value[j]= (LPC_GPIO1->FIOPIN & 0b1<<j);

					}
			nbrValue++;

			if(nbrValue>=8){
				datos[i]=value[16];
				nbrValue=8;
			}

			datos[i]=value[16]; //remplissage dato
			sum = sum + datos[i];
			promedio = sum / nbrValue; //calcul moyenne
			//printf("Promedio : %u \n", promedio);

			//LPC_GPIO0->FIOSET0 &= result; //pour afficher
			//LPC_GPIO0->FIOSET0 |= result;

			}

		retardo(10000000);
		}
		return 0;
}

void retardo(uint32_t tiempo){
	for(int i=0; i<tiempo; i++);
}

/*
 * Estudiante: Justin Lafay
 * Carrera: Electronica
 *

#include "LPC17xx.h"

int main(void){
	short buffer[8];
	short result = 0;
	short pin_out_l = 0;
	short pin_out_h = 0;
	int point = 0;

	LPC_GPIO1->FIODIR &= ~(0b1111111111111111<<0); // input mode from P1.0 to P1.15
	LPC_GPIO0->FIODIR |= (0b1111000111111111111<<0); // output mode

	while(1){
		result = 0;
		if (point == 7){ //reinit de la tailla du tab de valeurs
			point = 0;
		}
		buffer[point] = LPC_GPIO1->FIOPINL;

		for (int i; i<7; i++){
			result = result+(buffer[i]); // calculate the buffer
		}

		 pin_out_h = result & (0b1111<<15);
		 pin_out_l = result & (0b111111111111<<0);
		 result = pin_out_l | pin_out_h;

		LPC_GPIO0->FIOSET0 &= result;
		LPC_GPIO0->FIOSET0 |= result;

		point++;
	}
	return 0;
}*/
