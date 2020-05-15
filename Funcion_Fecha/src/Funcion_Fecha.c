/*
 ============================================================================
 Name        : Prueba2.c
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

int utn_getFecha(int* pDia,int* pMes, int* pAnio , char* pMensaje, char* pMensajeError, int minDia, int maxDia, int minMes, int maxMes,int minAnio, int maxAnio, int reintentos);
int main(void) {
	int dia;
	int mes;
	int anio;


	utn_getFecha(&dia,&mes,&anio,"Ingrese Fecha\n","Error verifique la fecha ingresada\n",1,31,1,12,2000,2025,3);
	printf("La fecha ingresada fue %d/%d/%d :", dia, mes, anio);


	system("PAUSE()");
	return EXIT_SUCCESS;
}


static int getIntFecha(int* pDia, int* pMes, int* pAnio);
int utn_getFecha(int* pDia,int* pMes, int* pAnio , char* pMensaje, char* pMensajeError, int minDia, int maxDia, int minMes, int maxMes,int minAnio, int maxAnio, int reintentos)
{
int ret=0;
int dia;
int mes;
int anio;
if (pDia!= NULL && pMes!= NULL && pAnio!= NULL && pMensaje != NULL && pMensajeError != NULL && maxDia >= minDia && maxMes >= minMes && maxAnio >= minAnio && reintentos >=0 )
{
	do
	{
		printf(pMensaje);
		fflush(stdin);
		if(getIntFecha(&dia, &mes, &anio))
		{

			if((dia<minDia || dia>maxDia)  || (mes<minMes || mes>maxMes) || (anio<minAnio || anio>maxAnio))
			{

				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{

			printf(pMensajeError,reintentos);
			reintentos--;
		}


	}while (reintentos>=0 && ((dia<minDia || dia>maxDia)  || (mes<minMes || mes>maxMes) || (anio<minAnio || anio>maxAnio)));

	if (reintentos>=0)
	{

		ret=1;
		*pDia=dia;
		*pMes=mes;
		*pAnio=anio;
	}

}
else
{

	ret=0;
	printf(pMensajeError, reintentos);
}

return ret;
}

static int esFecha(char* cadena);
static int validaFecha(int dia,int mes,int anio);
static int getIntFecha(int* pDia,int* pMes,int* pAnio)
{
int ret=0;
int dia;
int mes;
int anio;
char cDia[10];
char cMes[10];
char cAnio[10];
char fecha[20];

if (pDia!= NULL && pMes!=NULL && pAnio!=NULL)
{

	scanf("%d/%d/%d",&dia,&mes,&anio);
	fflush(stdin);
	strcpy(fecha,itoa(dia,cDia,10));
	strcat(fecha,itoa(mes,cMes,10));
	strcat(fecha,itoa(anio,cAnio,10));

	if(esFecha(fecha))
	{

		if(validaFecha(dia,mes,anio))
		{

			*pDia=dia;
			*pMes=mes;
			*pAnio=anio;
			ret=1;
		}
	}

}

return ret;
}

static int validaFecha(int dia, int mes, int anio)
{
int ret=0;
int chkDia;


if(dia>0 && mes>0 && anio>0)
{
	switch(mes)
	{
		case 2:
		{
			if((anio%4)==0)
			{
				chkDia=29;
			}
			else
			{
				chkDia=28;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
			{
				chkDia=30;
				break;
			}
		default:
		{
				chkDia=31;
				break;
		}

	}

	if (dia<=chkDia)
	{
		ret=1;
	}

}

return ret;
}

static int esFecha(char* cadena)
{
int ret=0;
int i=0;
if(cadena!=NULL)
{
	while(cadena[i]!='\0')
	{
		if(!(isdigit(cadena[i])) && (cadena[i]!='/'))
		{
			break;
		}
		else if ((cadena[i]=='/' && (i!=2 || i!=5)))
		{break;}
		i++;
	}
	if(cadena[i]=='\0' && cadena[0]!='\0')
	{ret=1;}
}

return ret;
}
