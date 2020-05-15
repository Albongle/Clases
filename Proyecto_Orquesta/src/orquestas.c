/*
 * orquestas.c
 *
 *  Created on: 7 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "orquestas.h"
#include "utn.h"


void mostrarOrquesta(eOrquesta pArrayOrquestas);
int buscaPosOrquesta_ID(eOrquesta* pArray,int valorBuscado, int size);
int buscaIndiceOrquesta(eOrquesta* pArray, int size);
/*Usados para el alta de la orquesta*/
int buscarTipoOrquesta_ID(eTipoOrquesta* pArray,int valorBuscado, int size, char* descrTipoOrquesta);
void mostrarTipoOrquestas(eTipoOrquesta* pArrayTipoOrquesta, int tamArrayTipoOrquesta);
void mostrarTipoOrquesta(eTipoOrquesta pArrayTipoOrquesta);
eOrquesta nuevaOrquesta(int idOrquesta,char nombre[],char lugar[], int tipoOrquesta, char descrTipoOrquesta[]);



void iniArrayOrquestas(eOrquesta* pArray,int size,int valorInt)
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

int hardcodearOrquestas(eOrquesta* pArray, int size, int cantidad)
{

	int cont=0;
	int i;
	if(pArray!=NULL && size>0 && cantidad >0)
	{
		eOrquesta listaAuxiliar[]=
		{
			{0, "Orquesta Uno", "Lanus",{1000,"Sinfonica"},0},
			{1, "Orquesta Dos", "Avellaneda",{1002,"Camara"},0},
			{2, "Orquesta Tres", "CABA",{1000,"Sinfonica"},0},
			{3, "Orquesta Cuatro", "Lomas de Zamora",{1001},0},
			{4, "Orquesta Cinco", "Gerli",{1001,"Filarmonica"},0},
			{5, "Orquesta Seis", "CABA",{1000,"Sinfonica"},0},
			{6, "Orquesta Siete", "CABA",{1001,"Filarmonica"},0},
			{7, "Orquesta Ocho", "Lanus",{1002,"Camara"},0},
			{8, "Orquesta Nueve", "Banfield",{1002,"Camara"},0},
			{9, "Orquesta Diez","Banfield",{1002,"Camara"},0},

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

int altaOrquesta(eOrquesta* pArrayOrquesta,int tamArrayOrquesta, int idOrquesta,eTipoOrquesta* pArrayTipoOrquesta,int tamArrayTipoOrquesta)
{
	int indice;
	int ret=0;
	char bufferNombre[50];
	char bufferLugar[50];
	int bufferTipo;
	char descrTipoOrquesta[20];



			system("CLS()");
			printf("*****Alta Orquesta*****\n\n");
	if(pArrayOrquesta!=NULL && tamArrayOrquesta>=0 && pArrayTipoOrquesta!=NULL && tamArrayTipoOrquesta>=0)
	{
			indice=buscaIndiceOrquesta(pArrayOrquesta,tamArrayOrquesta);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas orquestas\n\n");
				system("PAUSE()");
			}
			else
			{
				fflush(stdin);
				if(utn_getTexto(bufferNombre,"Ingrese el nombre de la orquesta\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
				{
					fflush(stdin);
					if(utn_getTexto(bufferLugar,"Ingrese el lugar de la orquesta\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						//mostrar tipo de orquesta
						mostrarTipoOrquestas(pArrayTipoOrquesta,tamArrayTipoOrquesta);
						fflush(stdin);
						if(utn_getNumero(&bufferTipo,"Ingrese el tipo de orquesta\n","Error verifique los datos ingresados quedan %d intentos\n",1000,1002,3))
						{
							buscarTipoOrquesta_ID(pArrayTipoOrquesta,bufferTipo,tamArrayTipoOrquesta,descrTipoOrquesta); // busco la descripcion del Id de orquesta y la cargo en la posicion de la orquesta el nombre
							pArrayOrquesta[indice]=nuevaOrquesta(idOrquesta,bufferNombre,bufferLugar,bufferTipo,descrTipoOrquesta);
							ret=1;
						}
					}
				}
			}
	}

return ret;

}


int buscaIndiceOrquesta(eOrquesta* pArray, int size)
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

int buscarTipoOrquesta_ID(eTipoOrquesta* pArray,int valorBuscado, int size, char* descrTipoOrquesta)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idTipo==valorBuscado && pArray[i].isEmpty==0)
		{
			strcpy(descrTipoOrquesta,pArray[i].nombre);
			ret=1;
			break;
		}
	}

}
return ret;
}

eOrquesta nuevaOrquesta(int idOrquesta,char nombre[],char lugar[], int tipoOrquesta, char descrTipoOrquesta[])
{
	eOrquesta nuevaOrquesta;

	nuevaOrquesta.idOrquesta=idOrquesta;
	strcpy(nuevaOrquesta.nombre,nombre);
	strcpy(nuevaOrquesta.lugar,lugar);
	nuevaOrquesta.tipo.idTipo=tipoOrquesta;
	strcpy(nuevaOrquesta.tipo.nombre,descrTipoOrquesta);
	nuevaOrquesta.isEmpty=0;

return nuevaOrquesta;
}

int bajaOrquesta(eOrquesta* pArrayOrquesta, int tamArrayOrquesta,int *idOrquestaBaja)
{
	int indice=-1;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Baja Orquesta*****\n\n");
	if(pArrayOrquesta!=NULL && tamArrayOrquesta>0 && idOrquestaBaja>=0)
	{

		mostrarOrquestas(pArrayOrquesta,tamArrayOrquesta);
		printf("\n\n\n");
		if(utn_getNumero(&valorBuscado,"Ingrese el ID de orquesta dar de baja \n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3))
		{
			indice=buscaPosOrquesta_ID(pArrayOrquesta,valorBuscado,tamArrayOrquesta);
		}

		if(indice==-1)
		{
			printf("No se encontro Orquesta para el ID ingresado\n");

		}
		else
		{

			printf("ID          Nombre          Lugar          Tipo\n");
			mostrarOrquesta(pArrayOrquesta[indice]);
			printf("\n\n");

			utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);


			if(respuesta=='s')
			{
				pArrayOrquesta[indice].isEmpty=1;
				*idOrquestaBaja=pArrayOrquesta[indice].idOrquesta;
				printf("Se elimino la orquesta y sus musicos\n");
				ret=1;
			}

			else
			{
			printf("Se cancelo la baja\n");
			}

		}
	}

return ret;
}


int buscaPosOrquesta_ID(eOrquesta* pArray,int valorBuscado, int size)
{
int indice=-1;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].isEmpty==0 && pArray[i].idOrquesta==valorBuscado)
		{
			indice=i;
			break;
		}

	}

}

return indice;
}




void mostrarOrquestas(eOrquesta* pArrayOrquestas, int tamArrayOrquesta)
{
	int i;
	int flag=0;
	printf("ID          Nombre          Lugar          Tipo\n");

	if(pArrayOrquestas!=NULL && tamArrayOrquesta>=0)
		{
			for(i=0;i<tamArrayOrquesta;i++)
			{
				if(pArrayOrquestas[i].isEmpty==0)
				{
					mostrarOrquesta(pArrayOrquestas[i]);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay orquestas que mostrar---\n\n");
			}
		}

}

void mostrarOrquesta(eOrquesta pArrayOrquestas)
{

	printf("%d          %s          %s          %s\n",pArrayOrquestas.idOrquesta, pArrayOrquestas.nombre,pArrayOrquestas.lugar,pArrayOrquestas.tipo.nombre);

}



void mostrarTipoOrquestas(eTipoOrquesta* pArrayTipoOrquesta, int tamArrayTipoOrquesta)
{
	int i;
	int flag=0;
	printf("ID          Nombre\n");

	if(pArrayTipoOrquesta!=NULL && tamArrayTipoOrquesta>=0)
		{
			for(i=0;i<tamArrayTipoOrquesta;i++)
			{
				if(pArrayTipoOrquesta[i].isEmpty==0)
				{
					mostrarTipoOrquesta(pArrayTipoOrquesta[i]);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay tipos de orquestas que mostrar---\n\n");
			}
		}

}

void mostrarTipoOrquesta(eTipoOrquesta pArrayTipoOrquesta)
{

	printf("%d          %s\n",pArrayTipoOrquesta.idTipo,pArrayTipoOrquesta.nombre);

}


int buscarNombreTipoOrquesta_IDOrquesta(eOrquesta* pArray,int valorBuscado, int size, char* descrTipoOrquesta)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idOrquesta==valorBuscado && pArray[i].isEmpty==0)
		{
			strcpy(descrTipoOrquesta,pArray[i].tipo.nombre);
			ret=1;
			break;
		}
	}

}
return ret;
}
int buscarNombreOrquesta_IDOrquesta(eOrquesta* pArray,int valorBuscado, int size, char* descrOrquesta)
{
int ret=0;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].idOrquesta==valorBuscado && pArray[i].isEmpty==0)
		{
			strcpy(descrOrquesta,pArray[i].nombre);
			ret=1;
			break;
		}
	}

}
return ret;
}


