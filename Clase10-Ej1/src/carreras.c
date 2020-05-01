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


static void mostrarCarrera(eCarrera pArray);
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

static void mostrarCarrera(eCarrera pArray)
{
	printf("%d          %s\n",pArray.id, pArray.descripcion);

}
