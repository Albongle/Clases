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

int devuelveMaxAndMin(int* pArray, int size, int* max, int* min)
{
	int ret=0;
	int i;
	int nMin;
	int nMax;
	if(pArray!=NULL && size>0 && max!=NULL && min!=NULL)
	{

		for (i=0; i<size; i++)
				 {
					if(i==0 || pArray[i]< nMin)
					{
						nMin=pArray[i];
					}
					if(i==0 || pArray[i]> nMax)
					{
						nMax=pArray[i];
					}
				 }

		*min=nMin;
		*max=nMax;
		ret=1;
	}
	return ret;
}

int devuelveMaxAndMinFloat(float* pArray, int size, float* max, float* min)
{
	int ret=0;
	int i;
	float nMin;
	float nMax;
	if(pArray!=NULL && size>0 && max!=NULL && min!=NULL)
	{

		for (i=0; i<size; i++)
				 {
					if(i==0 || pArray[i]< nMin)
					{
						nMin=pArray[i];
					}
					if(i==0 || pArray[i]> nMax)
					{
						nMax=pArray[i];
					}
				 }

		*min=nMin;
		*max=nMax;
		ret=1;
	}
	return ret;


}




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
int imprimirArrayFloat(float* pArray,int size)
{
	int i;
	int retorno=0;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			printf("El indice [%d] tiene como valor %.2f\n", i, pArray[i]);
		}
		retorno=1;
	}

	return retorno;
}

int imprimirArrayString(char* pArray,int size)
{
	int i;
	int retorno=0;
	if(pArray != NULL && size > 0)
	{
		for(i = 0; i < size; i++)
		{
			printf("El indice [%d] tiene como valor %s\n", i, pArray[i]);
		}
		retorno=1;
	}

	return retorno;
}





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


int iniArrayInt(int* pArray,int size,int valor)
{
	int i;
	int ret=0;

	if(pArray!=NULL && size>0)
	{
		for(i = 0; i < size; i++)
		{

			pArray[i]=valor;

		}
	ret=1;
	}
return ret;
}

int getArrayInt(int* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos)
{
	int ret=0;
	int buffer;
	int i=0;
	char respuesta;


	if(pArray!=NULL && size >0 && pos!=NULL && pMensaje!=NULL && pMensajeError!=NULL)
	{

		do
		{
			fflush(stdin);

			if(utn_getNumero(&buffer,pMensaje,pMensajeError,minimo,maximo,reintentos))
			{
				pArray[i]=buffer;
				i++;
			}
			utn_getCaracter(&respuesta,"\nDesea seguir ingresando numeros (s/n)\n","Error debe ser (s o n) quedan %d reintentos ","sn",3);
		}while(respuesta!='n' && i<=size);

		*pos=i;
		ret=1;
	}
	return ret;

}


int getArrayFloat(float* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos)
{
	int ret=0;
	float buffer;
	int i=0;
	char respuesta;


	if(pArray!=NULL && size >0 && pos!=NULL && pMensaje!=NULL && pMensajeError!=NULL)
	{
		do
		{
			fflush(stdin);


			if(utn_getNumeroConDecimales(&buffer,pMensaje,pMensajeError,minimo,maximo,reintentos))
			{
				pArray[i]=buffer;
				i++;
			}
			utn_getCaracter(&respuesta,"\nDesea seguir ingresando numeros (s/n)\n","Error debe ser (s o n) quedan %d reintentos ","sn",3);
		}while(respuesta!='n' && i<=size);

		ret=1;
	}
	return ret;

}

int getArrayString(char* pArray, int sizeY,int sizeX,char* pMensaje, char* pMensajeError, int reintentos, int* pos)
{
	int ret=0;
	char buffer[sizeX];
	int i=0;
	char respuesta;


	if(pArray!=NULL && sizeY >0 && sizeX >0 && pos!=NULL && pMensaje!=NULL && pMensajeError!=NULL)
	{
		do
		{
			fflush(stdin);


			if(utn_getTexto(buffer,pMensaje,pMensajeError,reintentos,sizeX))
			{
				strcpy(pArray[i],buffer);
				i++;
			}
			utn_getCaracter(&respuesta,"\nDesea seguir ingresando texto (s/n)\n","Error debe ser (s o n) quedan %d reintentos ","sn",3);
		}while(respuesta!='n' && i<=sizeY);

		ret=1;
	}
	return ret;

}

