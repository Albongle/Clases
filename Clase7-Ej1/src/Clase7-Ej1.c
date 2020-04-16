/*
 ============================================================================
 Name        : Clase7-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "anb_f.h"
#define TAMANIO 5

int main(void) {

		setbuf(stdout, NULL);
		int arrayIngreso[TAMANIO];
		int i;
		int num;
		int nMax;
		int nMin;


		for(i = 0; i < TAMANIO; i++)
		{

			if(utn_getNumero(&num, "Ingrese un numero\n","Error tiene que ser de 0 a 999\n",0,999,2))
			{
				arrayIngreso[i]=num;
			}
		}

		if(devuelveMax(arrayIngreso,TAMANIO,&nMax))
		{
			printf("El maximo es %d\n", nMax);
		}
		if(devuelveMin(arrayIngreso,TAMANIO,&nMin))
		{
			printf("El minimo es %d\n", nMin);
		}


		system("PAUSE()");

		return 0;


}
