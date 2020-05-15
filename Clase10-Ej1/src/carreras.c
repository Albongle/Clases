/*
 * carreras.c
 *
 *  Created on: 30 abr. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "carreras.h"


void mostrarCarrera(eCarrera pArray);
void mostrarCarreras(eCarrera* pArray, int size)
{
	int i;
	printf("ID          Descripcion\n");

	if(pArray!=NULL && size>=0)
		{
			for(i=0;i<size;i++)
			{
				mostrarCarrera(pArray[i]);
			}
		}
}

void mostrarCarrera(eCarrera pArray)
{
	printf("%d          %s\n",pArray.id, pArray.descripcion);

}


int buscarCarrera(eCarrera* pArray,int valorBuscado, int size, char* descrCarrera)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].id==valorBuscado)
		{
			strcpy(descrCarrera,pArray[i].descripcion);
			ret=1;
			break;
		}
	}

}
return ret;
}

int cargarIdCarrera(eCarrera* pArray,char* valorBuscado, int size, int* idCarrera)
{
	int ret=0;
	int i;
	if(pArray!=NULL && size>0 )
	{

		for(i=0;i<size;i++)
		{
			if ((stricmp(pArray[i].descripcion,valorBuscado))==0)
			{
				*idCarrera=pArray[i].id;
				ret=1;
				break;
			}
		}

	}
	return ret;

}
