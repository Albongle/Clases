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
#include "anb_f.h"
#define ELEMENTOS 2
#define SIZE_CARACTERES 50




typedef struct datosPersonales{

	int legajo;
	char nombre[SIZE_CARACTERES];
	char apellido[SIZE_CARACTERES];

}datosPersonales;

int getSetDeDatos(datosPersonales* datosAux, int sizeArray);
void mostrarDato(datosPersonales datosAux);
void mostrarDatos(datosPersonales* datosAux, int size);
int main(void) {

		setbuf(stdout, NULL);
		datosPersonales datos[ELEMENTOS];




		getSetDeDatos(datos,ELEMENTOS);

		mostrarDatos(datos, ELEMENTOS);





			system("PAUSE()");;

return 0;
}







int getSetDeDatos(datosPersonales* datosAux, int sizeArray)
{
	int i;
	int ret=0;
	int flag=0;
	int bufferLegajo;
	char bufferNombre[50];
	char bufferApellido[50];


	if(datosAux!=NULL)
	{

		for(i=0;i<sizeArray;i++)
		{
			fflush(stdin);

			if(utn_getNumero(&bufferLegajo,"Ingrese el legajo del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",1,999,3))
			{
				datosAux[i].legajo=bufferLegajo;
				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getTexto(bufferNombre,"Ingrese el nombre del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);

				strcpy(datosAux[i].nombre,bufferNombre);
				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getTexto(bufferApellido,"Ingrese el Apellido del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);


				strcpy(datosAux[i].apellido,bufferApellido);


				ret=1;
			}
			else
			{
				printf("No se ingreso ningun dato");
				datosAux[i].legajo=0;
				break;
				ret=0;
			}



		}

	}

return ret;

}


void mostrarDato(datosPersonales datosAux)
{
	printf("%d					%s				%s\n",datosAux.legajo,datosAux.nombre, datosAux.apellido);

}

void mostrarDatos(datosPersonales* datosAux, int size)
{
	int i;
	printf("Legajo					Nombre				Apellido\n");

	if(datosAux!=NULL && size>0)
		{
			for(i=0;i<size;i++)
			{
				mostrarDato(datosAux[i]);
			}
		}
}
