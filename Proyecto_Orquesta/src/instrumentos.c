/*
 * instrumentos.c
 *
 *  Created on: 7 may. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "instrumentos.h"
#include "utn.h"

eInstrumento nuevoInstrumento(int idInstrumento,char nombre[], int tipoInstrumento, char descrTipoInstrumento[]);
int buscaIndiceInstrumento(eInstrumento* pArray, int size);
void mostrarInstrumento(eInstrumento pArrayInstrumentos);
int buscarTipoInstrumento_ID(eTipoInstrumento* pArray,int valorBuscado, int size, char* descrInstrumento);
void mostrarTipoInstrumentos(eTipoInstrumento* pArrayTipoInstrumento, int tamArrayTipoInstrumento);
void mostrarTipoInstrumento(eTipoInstrumento pArrayTipoInstrumento);



void iniArrayInstrumentos(eInstrumento* pArray,int size,int valorInt)
{
	int i;

	if(pArray!=NULL && size>0)
	{
		for(i = 0; i < size; i++)
		{

			pArray[i].isEmpty=valorInt;

		}
	}

}

int hardcodearInstrumentos(eInstrumento* pArray, int size, int cantidad)
{

	int cont=0;
	int i;
	if(pArray!=NULL && size>0 && cantidad >0)
	{
		eInstrumento listaAuxiliar[]=
		{
			{0, "Instrumento Uno",{1000,"Cuerdas"},0},
			{1, "Instrumento Dos",{1002,"Viento-metal"},0},
			{2, "Instrumento Tres",{1003,"Percusion"},0},
			{3, "Instrumento Cuatro",{1001,"Viento-madera"},0},
			{4, "Instrumento Cinco",{1002,"Viento-metal"},0},
			{5, "Instrumento Sesis",{1000,"Cuerdas"},0},
			{6, "Instrumento Siete",{1001,"Viento-madera"},0},
			{7, "Instrumento Ocho",{1002,"Viento-metal"},0},
			{8, "Instrumento Nueve",{1002,"Viento-metal"},0},
			{9, "Instrumento Diez",{1002,"Viento-metal"},0},

		};


		if (cantidad <=size && cantidad && cantidad <11)
		{
			for(i=0; i<cantidad; i++)
			{
				pArray[i]=listaAuxiliar[i];
				cont++;
			}


		}
	}

return cont;
}

int altaInstrumento(eInstrumento* pArrayInstrumento,int tamArrayInstrumento, int idInstrumento,eTipoInstrumento* pArrayTipoInstrumento,int tamArrayTipoInstrumento)
{
	int indice;
	int ret=0;
	char bufferNombre[50];
	int bufferTipo;
	char descrTipoInstrumento[20];



			system("CLS()");
			printf("*****Alta Instrumento*****\n\n");
	if(pArrayInstrumento!=NULL && tamArrayInstrumento>=0 && pArrayTipoInstrumento!=NULL && tamArrayTipoInstrumento>=0)
	{
			indice=buscaIndiceInstrumento(pArrayInstrumento,tamArrayInstrumento);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas instrumentos\n\n");
				system("PAUSE()");
			}
			else
			{
				fflush(stdin);
				if(utn_getTexto(bufferNombre,"Ingrese el nombre del instrumento\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
				{
					//mostrar tipo de instrumento
					mostrarTipoInstrumentos(pArrayTipoInstrumento,tamArrayTipoInstrumento);
					fflush(stdin);
					if(utn_getNumero(&bufferTipo,"Ingrese el tipo de instrumento\n","Error verifique los datos ingresados quedan %d intentos\n",1000,1003,3))
					{
						buscarTipoInstrumento_ID(pArrayTipoInstrumento,bufferTipo,tamArrayTipoInstrumento,descrTipoInstrumento);
						pArrayInstrumento[indice]=nuevoInstrumento(idInstrumento,bufferNombre,bufferTipo,descrTipoInstrumento);
						ret=1;
					}
				}
			}
	}

return ret;

}



int buscaIndiceInstrumento(eInstrumento* pArray, int size)
{
int indice=-1;
int i;

if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if(pArray[i].isEmpty==1)
		{
			indice=i;
			break;
		}
	}
}

return indice;
}

int buscarTipoInstrumento_ID(eTipoInstrumento* pArray,int valorBuscado, int size, char* descrInstrumento)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idTipo==valorBuscado && pArray[i].isEmpty==0)
		{
			strcpy(descrInstrumento,pArray[i].nombre);
			ret=1;
			break;
		}
	}

}
return ret;
}

eInstrumento nuevoInstrumento(int idInstrumento,char nombre[], int tipoInstrumento, char descrTipoInstrumento[])
{
	eInstrumento  nuevaInstrumento;

	nuevaInstrumento.idInstrumento=idInstrumento;
	strcpy(nuevaInstrumento.nombre,nombre);
	nuevaInstrumento.tipo.idTipo=tipoInstrumento;
	strcpy(nuevaInstrumento.tipo.nombre,descrTipoInstrumento);
	nuevaInstrumento.isEmpty=0;

return nuevaInstrumento;
}



void mostrarTipoInstrumentos(eTipoInstrumento* pArrayTipoInstrumento, int tamArrayTipoInstrumento)
{
	int i;
	int flag=0;
	printf("ID          Nombre\n");

	if(pArrayTipoInstrumento!=NULL && tamArrayTipoInstrumento>=0)
		{
			for(i=0;i<tamArrayTipoInstrumento;i++)
			{
				if(pArrayTipoInstrumento[i].isEmpty==0)
				{
					mostrarTipoInstrumento(pArrayTipoInstrumento[i]);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay tipos de instrumentos que mostrar---\n\n");
			}
		}

}

void mostrarTipoInstrumento(eTipoInstrumento pArrayTipoInstrumento)
{

	printf("%d          %s\n",pArrayTipoInstrumento.idTipo,pArrayTipoInstrumento.nombre);

}










void mostrarInstrumentos(eInstrumento* pArrayInstrumentos, int tamArrayInstrumento)
{
	int i;
	int flag=0;
	printf("ID          Nombre          Tipo\n");

	if(pArrayInstrumentos!=NULL && tamArrayInstrumento>=0)
		{
			for(i=0;i<tamArrayInstrumento;i++)
			{
				if(pArrayInstrumentos[i].isEmpty==0)
				{
					mostrarInstrumento(pArrayInstrumentos[i]);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay instrumento que mostrar---\n\n");
			}
		}

}


void mostrarInstrumento(eInstrumento pArrayInstrumentos)
{

	printf("%d          %s          %s\n",pArrayInstrumentos.idInstrumento, pArrayInstrumentos.nombre,pArrayInstrumentos.tipo.nombre); // revisar tipo de orquesta que muestr nombre

}


int buscarNombreInstrumento_IDInstrumento(eInstrumento* pArray,int valorBuscado, int size, char* descrInstrumento)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idInstrumento==valorBuscado && pArray[i].isEmpty==0)
		{
			strcpy(descrInstrumento,pArray[i].nombre);

			ret=1;
			break;
		}
	}

}
return ret;
}

int buscarNombreTipoInstrumento_IDInstrumento(eInstrumento* pArray,int valorBuscado, int size, char* descrTipoInstrumento)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idInstrumento==valorBuscado && pArray[i].isEmpty==0)
		{
			strcpy(descrTipoInstrumento,pArray[i].tipo.nombre);

			ret=1;
			break;
		}
	}

}
return ret;
}

int buscarIDTipoInstrumento_IDInstrumento(eInstrumento* pArray,int valorBuscado, int size, int* idTipo)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idInstrumento==valorBuscado && pArray[i].isEmpty==0)
		{
			*idTipo=pArray[i].tipo.idTipo;
			ret=1;
			break;
		}
	}

}
return ret;
}

