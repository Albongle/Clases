/*
 ============================================================================
 Name        : Clase10-Ej1.c
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
#include "alumnos.h"

#define ELEMENTOS 5
#define SIZE_CARACTERES 50







int main(void) {

system("COLOR FD");

		setbuf(stdout, NULL);
		eAlumnos datos[ELEMENTOS];
		int ingreso;
		int posicionImpr=0;
		int posLibres=ELEMENTOS;

		iniArrayLeg(datos,ELEMENTOS,-1); // inicializo array de legajos en -1

		do
		{



			system("CLS()");
			printf("Hay %d posiciones libres\n\n\n", posLibres);
			utn_getNumero(&ingreso,"1-ingreso de datos\n2-Modificacion de datos\n3-Ordena por Nombre e imprime\n4-Imprimir todos los datos\n5-Salir\n\nElija un opcion:","Error verifique los datos ingresados quedan %d intentos\n",1,5,3);

			switch (ingreso)
			{
				case 1:
				{
					getSetDeDatos(datos,ELEMENTOS,&posicionImpr);
					posLibres=ELEMENTOS-posicionImpr;
					break;
				}

				case 3:
				{

				ordenaNombre(datos,posicionImpr,'>');
				mostrarDatos(datos, posicionImpr);
				system("PAUSE()");

				break;
				}

				case 4:
				{
					mostrarDatos(datos, posicionImpr);
					system("PAUSE()");
					break;
				}
			}



		}while(ingreso!=5);



			system("PAUSE()");

return 0;
}



