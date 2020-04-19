/*
 * utn.c
 *
 *  Created on: 10 abr. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int getInt(int* pResultado);
static int esNumerica(char* cadena);
int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
int ret=0;
int ingreso;
if (pNumero!= NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo && reintentos >=0 )
{
	do
	{
		printf(pMensaje);
		if(getInt(&ingreso))
		{
			if(ingreso<minimo || ingreso>maximo)
			{
				fflush(stdin);
				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{
			printf(pMensajeError,reintentos);
			reintentos--;
		}


	}while (reintentos>=0 && (ingreso<minimo || ingreso>maximo));

	if (reintentos>=0)
	{
		ret=1;
		*pNumero=ingreso;
	}

	}
	else
	{
		printf(pMensajeError, reintentos);
	}

return ret;
}



static int getInt(int* pResultado)
{
int ret=0;
char buffer[64];
if (pResultado!= NULL)
{
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';
	if (esNumerica(buffer))
	{
		*pResultado=atol(buffer);
		ret=1;
	}

}

return ret;
}

static int esNumerica(char* cadena)
{
int ret=0;
int i=0;
if(cadena!=NULL)
{
	while(cadena[i]!='\0')
	{
		if(!(isdigit(cadena[i])) && (cadena[i]!='-'))
		{
			break;
		}
		else if ((cadena[i]=='-' && i!=0)||(cadena[0]=='-' && cadena[1]=='0' && strlen(cadena)==2))
		{break;}
		i++;
	}
	if(cadena[i]=='\0' && cadena[0]!='\0')
	{ret=1;}
}

return ret;
}


static int getFloat(float* pResultado);
static int esNumeroDecimal(char* cadena);
int utn_getNumeroConDecimales(float* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
int ret=0;
float ingreso;
if (pNumero!= NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo && reintentos >=0 )
{
	do
	{
		printf(pMensaje);
		if(getFloat(&ingreso))
		{
			if(ingreso<minimo || ingreso>maximo)
			{
				fflush(stdin);
				printf(pMensajeError, reintentos);
				reintentos--;
			}
		}
		else
		{
			printf(pMensajeError,reintentos);
			reintentos--;
		}


	}while (reintentos>=0 && (ingreso<minimo || ingreso>maximo));

	if (reintentos>=0)
	{
		ret=1;
		*pNumero=ingreso;
	}
}
else
{
	printf(pMensajeError, reintentos);
}

return ret;
}

static int getFloat(float* pResultado)
{
int ret=0;
char ingreso[64];
fgets(ingreso,sizeof(ingreso),stdin);
ingreso[strlen(ingreso)-1]='\0';
if(esNumeroDecimal(ingreso))
{
	*pResultado = atof(ingreso);
	ret=1;
}
return ret;
}

static int esNumeroDecimal(char* cadena)
{
int ret=0;
int i=0;
int controlP=0;
if(cadena!=NULL && cadena[0]!='.' && cadena[strlen(cadena)-1]!='.')
{
	while(cadena[i]!='\0')
	{

		if(!(isdigit(cadena[i])) && (cadena[i]!='.') && (cadena[i]!='-'))
		{
			break;
		}
		else if ((cadena[i]=='-' && i!=0)||(cadena[0]=='-' && cadena[1]=='0' && strlen(cadena)==2))
		{break;}
		else if(cadena[i]=='.')
		{
			controlP++;
		}

		i++;
	}
	if(cadena[i]=='\0' && cadena[0]!='\0' && controlP<=1)
	{ret=1;}
	}

return ret;
}

static int getString(char* pTexto);
int utn_getTexto(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size)
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
static int getString(char* pTexto)
{
int ret=0;
int i=0;

if(pTexto!=NULL)
{

	while(pTexto[i]!='\0')
	{
		if(isalpha(pTexto[i])||pTexto[i]==' ')
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


int buscaChar(char* caracter,char* pArrayB, int size);
int getString(char* pTexto);
int utn_getCaracter(char* pCaracter, char* pMensaje, char* pMensajeError,char* pRango,int size, int reintentos)
{
int ret=0;
int flagC=0;
char bufferIng[size];

if (pCaracter!=NULL && pMensaje!=NULL && pMensajeError!=NULL && pRango!=NULL && size>0 && reintentos>=0)
{

	do
	{

		printf(pMensaje);
		fgets(bufferIng,sizeof(bufferIng),stdin);
		bufferIng[strlen(bufferIng)-1]='\0';
		fflush(stdin);
		if(getString(bufferIng))
		{

			if(buscaChar(bufferIng,pRango,size))
			{
				flagC=1;
				break;
			}

			else
			{
			printf(pMensajeError, reintentos);
			reintentos--;
			}
		}
		else
		{
			printf(pMensajeError, reintentos);
			reintentos--;

		}

	}while(reintentos>=0);


	if (reintentos>=0 && flagC==1)
	{
		strcpy(pCaracter,bufferIng);
		ret=1;
	}



}
return ret;
}


int buscaChar(char* caracter,char* pArrayAbuscar, int size)
{
int ret=0;
int i=0;
if(caracter!=NULL && pArrayAbuscar!=NULL && size>0 )
{

	while(pArrayAbuscar[i]!='\0')
	{
		if(pArrayAbuscar[i]==caracter[0])
		{ret=1;
		break;
		}
		i++;
	}

}

return ret;
}

