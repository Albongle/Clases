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
#define QTY_ALUMNOS 3
#define SIZE_CARACTERES 128



int main(void) {

		setbuf(stdout, NULL);


		//int arrayEdades[QTY_ALUMNOS];
		//float arrayNotas[QTY_ALUMNOS];
		//int eMax;
		//int eMin;
		//float nMax;
		//float nMin;
		int i;
		char nombre[QTY_ALUMNOS][SIZE_CARACTERES];


		getArrayString(nombre,QTY_ALUMNOS,SIZE_CARACTERES,"Ingrese el nombre del Allumno:\n","Error verifique el dato ingresado, quedan %d reintentos\n",2,&i);


		imprimirArrayString(nombre,QTY_ALUMNOS);






		/*iniArrayInt(arrayEdades,QTY_ALUMNOS,0);
		getArrayInt(arrayEdades,QTY_ALUMNOS,"Ingrese la edad\n","Error debe ser entre 0 y 100\n",0,100,3, &i);
		getArrayFloat(arrayNotas,QTY_ALUMNOS,"Ingrese la nota\n","Error debe ser entre 0 y 10\n",0,10,3, &i);

		imprimirArrayInt(arrayEdades,i);
		printf("\n");
		imprimirArrayFloat(arrayNotas,QTY_ALUMNOS);
		printf("\n");

		if(devuelveMaxAndMin(arrayEdades,i,&eMax,&eMin))
		{
			printf("El minimo de edad es %d\n", eMin);
			printf("El maximo de edad es %d\n", eMax);
			printf("\n");
		}
		if(devuelveMaxAndMinFloat(arrayNotas,QTY_ALUMNOS,&nMax,&nMin))
		{
			printf("El minimo de nota es %.2f\n", nMin);
			printf("El maximo de nota es %.2f\n", nMax);
		}*/



			system("PAUSE()");;

					return 0;
}


