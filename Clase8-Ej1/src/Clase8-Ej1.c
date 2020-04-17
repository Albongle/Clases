/*
 ============================================================================
 Name        : Clase8-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "anb_f.h"
#define QTY_EDADES 5

int main(void) {

		setbuf(stdout, NULL);
		int arrayEdades[QTY_EDADES];
		float arrayNotas[QTY_EDADES];
		int eMax;
		int eMin;
		float nMax;
		float nMin;






		iniArrayInt(arrayEdades,QTY_EDADES,0);
		getArrayInt(arrayEdades,QTY_EDADES,"Ingrese la edad\n","Error debe ser entre 0 y 100\n",0,100,3);
		getArrayFloat(arrayNotas,QTY_EDADES,"Ingrese la nota\n","Error debe ser entre 0 y 10\n",0,10,3);

		imprimirArrayInt(arrayEdades,QTY_EDADES);
		printf("\n");
		imprimirArrayFloat(arrayNotas,QTY_EDADES);
		printf("\n");

		if(devuelveMaxAndMin(arrayEdades,QTY_EDADES,&eMax,&eMin))
		{
			printf("El minimo de edad es %d\n", eMin);
			printf("El maximo de edad es %d\n", eMax);
			printf("\n");
		}
		if(devuelveMaxAndMinFloat(arrayNotas,QTY_EDADES,&nMax,&nMin))
		{
			printf("El minimo de nota es %.2f\n", nMin);
			printf("El maximo de nota es %.2f\n", nMax);
		}



		system("PAUSE()");;

		return 0;


}
