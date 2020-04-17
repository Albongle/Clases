/*
 ============================================================================
 Name        : Biblios.c
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
#define SIZE 128

int getTexto(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size);
int main(void) {
	char nombre[SIZE];
	setbuf(stdout, NULL);

	getTexto(nombre,"Ingrese el nombre del alumno\n","Error verifique los datos ingresados, quedan %d reintentos\n",2, SIZE);
	printf("\nEl nombre ingresado fue: %s ",nombre);



	return 0;
}

static int getString (char* pTexto);

int getTexto(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size)
	{
		int ret=0;
		char bufferIng[size];

		if (pIngreso!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>=0)
		{
			do
			{
				fflush(stdin);
				printf(pMensaje);
				fgets(bufferIng,sizeof(bufferIng),stdin);
				bufferIng[strlen(bufferIng)-1]='\0';
				if(getString (bufferIng))
				{
					break;
				}
				else
				{
					reintentos--;
					printf(pMensajeError, reintentos);

				}

			}while(reintentos>=0);
			if (reintentos>=0)
			{
				strcpy(pIngreso,bufferIng);
				ret=1;
			}



		}
	return ret;

	}

static int getString (char* pTexto)
{
	int ret=0;
	int i=0;

	if(pTexto!=NULL)
	{

		while(pTexto[i]!='\0')
		{
			if(isalpha(pTexto[i]))
			{
				i++;
			}
			else
			{break;}
		}
		if(pTexto[i]=='\0' && pTexto[0]!='\0')
		{ret=1;}
	}
return ret;
}
