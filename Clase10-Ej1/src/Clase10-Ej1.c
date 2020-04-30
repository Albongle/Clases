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






int menu();

int main(void) {

system("COLOR FD");

		setbuf(stdout, NULL);
		eAlumnos datos[A_ELEMENTOS];
		int ingreso;
		int posicionImpr=0;
		int posLibres=A_ELEMENTOS;

		iniArrayLeg(datos,A_ELEMENTOS,-1); // inicializo array de legajos en -1

		do
		{



			system("CLS()");
			printf("Hay %d posiciones libres\n\n\n", posLibres);

			ingreso=menu();
			switch (ingreso)
			{
				case 1:
				{
					getSetDeDatos(datos,A_ELEMENTOS,&posicionImpr);
					posLibres=A_ELEMENTOS-posicionImpr;
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



		}while(ingreso!=8);



			system("PAUSE()");

return 0;
}

int menu()
{
	int opcion=0;

	printf("Menu de opciones\n\n");
	printf("1-Alta de Alumno\n");
	printf("2-Baja de Alumno\n");
	printf("3-Modificar Alumno\n");
	printf("4-Listar Alumnos\n");
	printf("5-Ordenar Alumno\n");
	printf("6-Informes\n");
	printf("7-Mostrar carreras\n");
	printf("8-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,8,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}



return opcion;
}



