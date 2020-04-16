/*
 * anb_f.c
 *
 *  Created on: 9 abr. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * Funcion usada para realizar el promedio de numeros enteros de una Array
 *
 */

int devuelvePromedio(int* pArray, int size, float* resultado)
{
	int ret=0;
	int i;
	int suma=0;
	float result;

	 if(pArray!=NULL && size>0 && resultado != NULL)
	 {
		 for (i=0; i<size; i++)
		 {
			 suma=suma+pArray[i];
		 }

	result=(float)suma/i;
	*resultado= result;
	ret=1;
	 }
return ret;
}


/**
 * Busca un numero INT dentro del array
 */

int buscaNumint(int* pArray, int size, int* pos)
{
int ret=0;
int valorB;
int i;
if(pArray!=NULL && size>0 )
{
	if (utn_getNumero(&valorB,"\ningrese el numero a buscar\n","Error verifique el numero ingresado\n",1,999,3))
	{
	for(i=0; i<size; i++)
	{
		if (pArray[i]==valorB)
		{ret=1;
		*pos=i;
		break;
		}
	}
	}

}

return ret;
}
/**
 * Esta funcion devuelme el minimo de un array
 *
 */

int devuelveMin(int* pArray, int size, int* resultado)
{
	int ret=0;
	int i;
	int min;
	if(pArray!=NULL && size>0 && resultado!=NULL)
	{

		for (i=0; i<size; i++)
				 {
					if(i==0 || pArray[i]< min)
					{
						min=pArray[i];
					}
				 }
		*resultado=min;
		ret=1;
	}
	return ret;
}

/**
 * Esta funcion devuelve el Maximo de un array
 *
 */
int devuelveMax(int* pArray, int size, int* resultado)
{
	int ret=0;
	int i;
	int max;
	if(pArray!=NULL && size>0 && resultado!=NULL)
	{

		for (i=0; i<size; i++)
				 {
					if(i==0 || pArray[i]> max)
					{
						max=pArray[i];
					}
				 }
		*resultado=max;
		ret=1;
	}
	return ret;
}







/**
 * Esta funcion imprime un array Int
 */


int imprimirArrayInt(int* pArray,int size)
{
	int i;
	int retorno=0;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			printf("El indice [%d] tiene como valor %d\n", i, pArray[i]);
		}
		retorno=1;
	}

	return retorno;
}



/**
 * Esta funcion recibe un array y lo ordena
 */

static int swap(int* pArray, int pos);
int ordenaArray(int* pArray,int size, char sentido)
{
	int flagSwap=1;
	int i;
	int cont=0;
	int retorno = 0;
	if(pArray != NULL && size > 0)
			{
				while(flagSwap)
				{
					cont++;
					flagSwap = 0;
					for(i = 0 ; i < size-cont ; i++)
					{
						switch (sentido)
						{
						case '>':
							{
							if(pArray[i] > pArray[i+1])
								{
									flagSwap = 1;
									swap(pArray, i);
								}
							break;
							}
						case '<':
							{
							if(pArray[i] < pArray[i+1])
								{
									flagSwap = 1;
									swap(pArray, i);
								}
							break;
							}
						}
					}
				}
		retorno = 1;
			}
	return retorno;
}

static int swap(int* pArray, int pos)
{
int buffer;

if (pArray!=NULL && pos >=0)
{
	buffer = pArray[pos];
	pArray[pos] = pArray[pos+1];
	pArray[pos+1] = buffer;
}

return 1;
}
