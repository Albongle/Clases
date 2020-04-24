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

/***
 * brief devuelve el promedio de un array de enteros
 * param pArray es el array sobre el cual se va a realizar el promedio de los numeros
 * param size es el tamaño del array
 * *resultado es la variable donde se va a devolver el promedio de los numeros de array
 * return 1 en caso exitoso
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
/***
 * brief solicita un numero entero y lo busca dentto del array
 * param pArray es el array sobre el cual se va a realizar la busqueda de los datos
 * param size es el tamaño del array
 * *pos es la posicion donde se encontro el numero buscado
 * return 1 en caso exitoso
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
/***
 * brief devuelve el numero maximo y minimo dentro de un array de enteros
 * param pArray es el array sobre el cual se va a realizar la busqueda de max y min
 * param size es el tamaño del array
 * *max es el numero maximo encontrado *min es el numero minimo encontrado
 * return 1 en caso exitoso
 */
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
/***
 * brief devuelve el numero maximo y minimo dentro de un array de flotantes
 * param pArray es el array sobre el cual se va a realizar la busqueda de max y min
 * param size es el tamaño del array
 * *max es el numero maximo encontrado *min es el numero minimo encontrado
 * return 1 en caso exitoso
 */
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

/***
* brief imprime los numeros enteros del array
* param pArray es el array sobre el cual se va a realizar la impresion de los numeros
* param size es el tamaño del array
* return 1 en caso exitoso
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
/***
 * brief imprime los numeros flotantes del array
 * param pArray es el array sobre el cual se va a realizar la impresion de los numeros
 * param size es el tamaño del array
 * return 1 en caso exitoso
 */
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
/***
 * brief imprime el string del array
 * param pArray es el array sobre el cual se va a realizar la impresion de los datos
 * param size es el tamaño del array
 * return 1 en caso exitoso
 */
int imprimirArrayString(char pArray[][50],int size)
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

/***
 * brief Ordena el array de numeros enteros
 * param pArray es el array sobre el cual se va a realizar el ordenamiento
 * param size es el tamaño del array
 * param sentido, indica la forma que se va a ordenar > o <
 * return 1 en caso exitoso
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
/**
 * brief inicializa un array de numeros enteros
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array
 * return 1 en caso exitoso
 */
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
/**
 * brief inicializa un array de numeros flotantes
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array
 * return 1 en caso exitoso
 */
int iniArrayFloat(float* pArray,int size,float valor)
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
/**
 * brief inicializa un array de strings
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array, ejemplo '\0'
 * return 1 en caso exitoso
 */
int iniArrayString(char pArray[][50],int size,char valor)
{
	int i;
	int ret=0;

	if(pArray!=NULL && size>0)
	{
		for(i = 0; i < size; i++)
		{

			*pArray[i]=valor;

		}
	ret=1;
	}
return ret;
}
/**
 * brief inicializa un array de char
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array, ejemplo '\0'
 * return 1 en caso exitoso
 */
int iniArrayChar(char* pArray,int size,char valor)
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
/**
 * brief realiza la carga de numeros enteros dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param size es el tamaño del array
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */

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
			else
			{break;}
			if(i<size)
			{
				utn_getCaracter(&respuesta,"\nDesea seguir ingresando numeros (s/n)\n","Error debe ser (s o n) quedan %d reintentos ","sn\0",3);
			}
		}while(respuesta!='n' && i<size);

		*pos=i;
		 ret=1;
	}
	return ret;

}
/**
 * brief realiza la carga de numeros flotantes dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param size es el tamaño del array
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */
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
			else
			{break;}
			if(i<size)
			{
			utn_getCaracter(&respuesta,"\nDesea seguir ingresando numeros (s/n)\n","Error debe ser (s o n) quedan %d reintentos ","sn\0",3);
			}
		}while(respuesta!='n' && i<size);

		*pos=i;
		 ret=1;
	}
	return ret;

}
/**
 * brief realiza la carga de cadenas de textos dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param sizeY es el tamaño del array
 * param sizeX es el tamaño que puede tener cada string
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */
int getArrayString(char pArray[][50],int sizeY,int sizeX,char* pMensaje, char* pMensajeError, int reintentos, int* pos)
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
			else
			{
				break;
			}

			if(i<sizeY)
			{
			utn_getCaracter(&respuesta,"\nDesea seguir ingresando (s/n)\n","Error la respuesta debe ser (s o n) quedan %d reintentos ","sn\0",3);
			}
		}while(respuesta!='n' && i<sizeY);

		*pos=i;
		 ret=1;
	}
	return ret;

}
/**
 * brief realiza la carga de caracteres dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param size es el tamaño del array
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param pCaractes son los caracteres que se le va a permitir al usuarios ingresar. la ultima posicion debe ser '\0' para indicar el final de la cadena
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */
int getArrayChar(char* pArray,int size,char* pMensaje, char* pMensajeError, char* pCaracteres, int reintentos, int* pos)
{

	int ret=0;
	char buffer;
	int i=0;
	char respuesta;


	if(pArray!=NULL && size >0 && pos!=NULL && pMensaje!=NULL && pMensajeError!=NULL)
	{

		do
		{

			fflush(stdin);
			if(utn_getCaracter(&buffer,pMensaje,pMensajeError,pCaracteres,reintentos))
			{
				pArray[i]=buffer;
				i++;
			}
			else
			{
				break;
			}

			if(i<size)
			{
			utn_getCaracter(&respuesta,"\nDesea seguir ingresando (s/n)\n","Error la respuesta debe ser (s o n) quedan %d reintentos ","sn\0",3);
			}
		}while(respuesta!='n' && i<size);

		*pos=i;
		 ret=1;
	}
	return ret;


}
/***
 * brief Ordena el array de numeros strings
 * param pArray es el array sobre el cual se va a realizar el ordenamiento
 * param size es el tamaño del array
 * param sentido, indica la forma que se va a ordenar > o <
 * return 1 en caso exitoso
 */
static int swapString(char pArray[][50], int pos);
int ordenaArrayString(char pArray[][50],int size, char sentido)
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
							if(strcmp(pArray[i],pArray[i+1])>0)
								{
									flagSwap = 1;
									swapString(pArray, i);
								}
							break;
							}
						case '<':
							{
							if(strcmp(pArray[i],pArray[i+1])<0)
								{
									flagSwap = 1;
									swapString(pArray, i);
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

static int swapString(char pArray[][50], int pos)
{
char buffer[50];

if (pArray!=NULL && pos >=0)
{
	strcpy(buffer,pArray[pos]);
	strcpy(pArray[pos],pArray[pos+1]);
	strcpy(pArray[pos+1],buffer);
}

return 1;
}

