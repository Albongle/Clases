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
		int arrayIngreso[QTY_EDADES];
		int nMax;
		int nMin;






		iniArrayInt(arrayIngreso,QTY_EDADES,0);
		if(getArrayInt(arrayIngreso,QTY_EDADES,"Ingrese la edad\n","Error debe ser entre 0 y 100\n",0,100,3))
		{
			imprimirArrayInt(arrayIngreso,QTY_EDADES);
		}



		if(devuelveMaxAndMin(arrayIngreso,QTY_EDADES,&nMax,&nMin))
		{
			printf("El minimo es %d\n", nMin);
			printf("El maximo es %d\n", nMax);
		}




		system("PAUSE()");;

		return 0;


}
