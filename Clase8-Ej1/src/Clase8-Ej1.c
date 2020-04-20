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
#define QTY_ALUMNOS 5
#define SIZE_CARACTERES 50



int main(void) {

		setbuf(stdout, NULL);
		int arrayLegajo[QTY_ALUMNOS];
		char arrayNombre[QTY_ALUMNOS][SIZE_CARACTERES];
		char arrayApellido[QTY_ALUMNOS][SIZE_CARACTERES];
		char arraySexo[QTY_ALUMNOS];
		int arrayEdades[QTY_ALUMNOS];
		float arrayNotas1[QTY_ALUMNOS];
		//float arrayNotas2[QTY_ALUMNOS];
		int eMax;
		int eMin;
		float nMax;
		float nMin;
		int i;

		iniArrayInt(arrayEdades,QTY_ALUMNOS,0);
		iniArrayInt(arrayLegajo,QTY_ALUMNOS,0);
		iniArrayFloat(arrayNotas1,QTY_ALUMNOS,0);
		iniArrayString(arrayNombre,QTY_ALUMNOS,'\0');
		iniArrayString(arrayApellido,QTY_ALUMNOS,'\0');

		getArrayInt(arrayLegajo,QTY_ALUMNOS,"Ingrese el legajo del alumno \n","Error debe ser entre 0 y 100\n",0,100,3, &i);
		getArrayString(arrayNombre,i,SIZE_CARACTERES ,"Ingrese el nombre del Alumno:\n","Error verifique el dato ingresado, quedan %d reintentos\n",2,&i);
		getArrayString(arrayApellido,i,SIZE_CARACTERES ,"Ingrese el apellido del Alumno:\n","Error verifique el dato ingresado, quedan %d reintentos\n",2,&i);
		getArrayChar(arraySexo,i,"Ingrese el sexo del Alumno (f o m):\n","Error verifique el dato ingresado, quedan %d reintentos\n","fm\0",3,&i);
		getArrayInt(arrayEdades,i,"Ingrese la edad\n","Error debe ser entre 0 y 100\n",0,100,3, &i);
		getArrayFloat(arrayNotas1,i,"Ingrese la nota\n","Error debe ser entre 0 y 10\n",0,10,3, &i);


		printf("imprimo ingreso \n");
		imprimirArrayString(arrayNombre,i);
		ordenaArrayString(arrayNombre,i,'<');
		printf("\n");
		printf("imprimo ordenado \n");
		imprimirArrayString(arrayNombre,i);







		imprimirArrayInt(arrayEdades,i);
		printf("\n");
		imprimirArrayFloat(arrayNotas1,QTY_ALUMNOS);
		printf("\n");

		if(devuelveMaxAndMin(arrayEdades,i,&eMax,&eMin))
		{
			printf("El minimo de edad es %d\n", eMin);
			printf("El maximo de edad es %d\n", eMax);
			printf("\n");
		}
		if(devuelveMaxAndMinFloat(arrayNotas1,QTY_ALUMNOS,&nMax,&nMin))
		{
			printf("El minimo de nota es %.2f\n", nMin);
			printf("El maximo de nota es %.2f\n", nMax);
		}



			system("PAUSE()");;

					return 0;
}


