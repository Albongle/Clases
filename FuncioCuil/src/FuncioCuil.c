/*
 ============================================================================
 Name        : FuncioCuil.c
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
int utn_getCuil(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size);
int main(void) {
	setbuf(stdout, NULL);
	char cuil[15];


	utn_getCuil(cuil,"Ingrese el cuil 00-00000000-0\n","Error verifique los datos ingresados\n",3,15);
	printf("El cuil ingresado fue %s", cuil);

}


static int getCadena(char* pTexto);
int utn_getCuil(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size)
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
		if(getCadena(bufferIng))
		{

			break;
		}
		else
		{
			printf(pMensajeError, reintentos);
			reintentos--;

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
static int getCadena(char* pTexto)
{
int ret=0;
int i=0;
int contGuion=0;
int largo =strlen(pTexto);

if(pTexto!=NULL && largo==13)
{

	while(pTexto[i]!='\0')
	{
		if(isdigit(pTexto[i])||pTexto[i]=='-')
		{
			if(pTexto[i]=='-')
			{
				if(i!=2 && i !=11)
				{
					break;
				}
				else
				{
					contGuion++;
				}
			}

			i++;
		}
		else
		{break;}
	}
	if(pTexto[i]=='\0'&&contGuion==2)
	{ret=1;}
}
return ret;
}


