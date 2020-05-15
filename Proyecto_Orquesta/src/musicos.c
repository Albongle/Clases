/*
 * musicos.c
 *
 *  Created on: 7 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "musicos.h"
#include "orquestas.h"
#include "instrumentos.h"
#define Q_MUSICOS 1000

int buscarPosMusico_ID(eMusicos* pArray,int valorBuscado, int size);
eMusicos nuevoMusico(int idMusico,char nombre[],char apellido[],int edad, int idOrquesta, int idInstrumento);
int buscaIndiceMusicos(eMusicos* pArray, int size);
int modiMusico(eMusicos musicoRec ,int opcion, eMusicos* auxMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta);
int opcionesModificacion();


void iniArrayMusicos(eMusicos* pArray,int size,int valorInt)
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

int hardcodearMusicos(eMusicos* pArray, int size, int cantidad)
{

	int cont=0;
	int i;
	if(pArray!=NULL && size>0 && cantidad >0)
	{
		eMusicos listaAuxiliar[]=
		{
			{0, "Musico", "Uno",40,0,0,0},
			{1, "Musico", "Dos",25,2,1,0},
			{2, "Musico", "Tres",70,0,2,0},
			{3, "Musico", "Cuatro",88,1,2,0},
			{4, "Musico", "Cinco",55,2,3,0},
			{5, "Musico", "Seis",50,0,2,0},
			{6, "Musico", "Siete",40,1,0,0},
			{7, "Musico", "Ocho",35,2,2,0},
			{8, "Musico", "Nueve",25,2,3,0},
			{9, "Musico", "Diez",19,2,1,0},

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




int altaMusico(eMusicos* pArrayMusico, int tamArrayMusico, int idMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta,eInstrumento* pArrayInstrumento, int tamArrayInstrumento)
{
	int indice;
	int ret=0;
	char bufferNombre[50];
	char bufferApellido[50];
	int bufferEdad;
	int bufferidOrquesta;
	int bufferIdinstrumento;


			system("CLS()");
			printf("*****Alta Musico*****\n\n");
	if(pArrayMusico!=NULL && tamArrayMusico>=0 && pArrayOrquesta!=NULL && tamArrayOrquesta>=0 && pArrayInstrumento!=NULL && tamArrayInstrumento>=0)
	{
			indice=buscaIndiceMusicos(pArrayMusico,tamArrayMusico);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas musicos\n\n");
				system("PAUSE()");
			}
			else
			{
				fflush(stdin);
				if(utn_getTexto(bufferNombre,"Ingrese el nombre del musico\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
				{
					fflush(stdin);
					if(utn_getTexto(bufferApellido,"Ingrese el Apellido del musico\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						fflush(stdin);
						if(utn_getNumero(&bufferEdad,"Ingrese la edad del musico \n","Error verifique los datos ingresados quedan %d intentos\n",1,99,3))
						{
							//mostrar orquestas
							mostrarOrquestas(pArrayOrquesta,tamArrayOrquesta);
							fflush(stdin);
							if(utn_getNumero(&bufferidOrquesta,"Ingrese el ID de orquesta del musico \n","Error verifique los datos ingresados quedan %d intentos\n",0,50,3))
							{
								//Mostrar  instrumentos
								mostrarInstrumentos(pArrayInstrumento,tamArrayInstrumento);
								fflush(stdin);
								if(utn_getNumero(&bufferIdinstrumento,"Ingrese el ID del instrumento del musico \n","Error verifique los datos ingresados quedan %d intentos\n",0,20,3))
								{
									pArrayMusico[indice]=nuevoMusico(idMusico,bufferNombre,bufferApellido,bufferEdad,bufferidOrquesta,bufferIdinstrumento);
									ret=1;
								}
							}
						}
					}
				}
			}
	}
return ret;

}

int buscaIndiceMusicos(eMusicos* pArray, int size)
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

eMusicos nuevoMusico(int idMusico,char nombre[],char apellido[],int edad, int idOrquesta, int idInstrumento)
{
	eMusicos nuevoMusico;

	nuevoMusico.idMusico=idMusico;
	strcpy(nuevoMusico.nombre,nombre);
	strcpy(nuevoMusico.apellido,apellido);
	nuevoMusico.edad=edad;
	nuevoMusico.idOrquesta=idOrquesta;
	nuevoMusico.idInstrumento=idInstrumento;
	nuevoMusico.isEmpty=0;

return nuevoMusico;
}




void mostrarMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquesta,int tamArrayOrquesta,eInstrumento* pArrayInstrumento,int tamArrayInstrumento)
{
	int i;
	int flag=0;
	printf("ID          Nombre          Apellido          Edad          Nombre Instrumento          Tipo de Instrumento          Nombre Orquesta\n");

	if(pArrayMusicos!=NULL && tamArrayMusicos>=0 && pArrayOrquesta!=NULL && tamArrayOrquesta>=0 && pArrayInstrumento!=NULL && tamArrayInstrumento>=0)
		{
			for(i=0;i<tamArrayMusicos;i++)
			{
				if(pArrayMusicos[i].isEmpty==0)
				{
					mostrarMusico(pArrayMusicos[i],pArrayOrquesta,tamArrayOrquesta,pArrayInstrumento,tamArrayInstrumento);
					flag=1;
				}
			}

			if(flag==0)
			{
				system("CLS()");
				printf("\n---No hay musicos que mostrar---\n\n");
			}
		}

}

void mostrarMusico(eMusicos pArrayMusicos,eOrquesta* pArrayOrquesta,int tamArrayOrquesta,eInstrumento* pArrayInstrumento,int tamArrayInstrumento)
{
	char descrInstrumento[20];
	char descTipoInstrumento[20];
	char descrOrquesta[20];

	fflush(stdin);

	buscarNombreInstrumento_IDInstrumento(pArrayInstrumento,pArrayMusicos.idInstrumento,tamArrayInstrumento,descrInstrumento);
	buscarNombreTipoInstrumento_IDInstrumento(pArrayInstrumento,pArrayMusicos.idInstrumento,tamArrayInstrumento,descTipoInstrumento);
	buscarNombreOrquesta_IDOrquesta(pArrayOrquesta,pArrayMusicos.idOrquesta,tamArrayOrquesta,descrOrquesta);

	printf("%d          %s          %s          %d          %s          %s          %s\n",pArrayMusicos.idMusico,pArrayMusicos.nombre,pArrayMusicos.apellido,pArrayMusicos.edad,descrInstrumento,descTipoInstrumento,descrOrquesta);

}



int bajaMusico(eMusicos* pArrayMusico, int tamArrayMusico, int idMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta,eInstrumento* pArrayInstrumento,int tamArrayInstrumento)
{
	int indice=-1;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Baja Musico*****\n\n");
	if(pArrayMusico!=NULL && tamArrayMusico>0 && pArrayOrquesta && tamArrayOrquesta>0 && pArrayInstrumento!=NULL && tamArrayInstrumento>0)
	{


		mostrarMusicos(pArrayMusico,tamArrayMusico,pArrayOrquesta,tamArrayOrquesta, pArrayInstrumento,tamArrayInstrumento);
		printf("\n\n\n");
		if(utn_getNumero(&valorBuscado,"Ingrese el ID del musico a dar de baja \n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3))
		{
		indice=buscarPosMusico_ID(pArrayMusico,valorBuscado,tamArrayMusico);
		}

		if(indice==-1)
		{
			printf("No se encontro musico para el ID ingresado\n");

		}
		else
		{

			printf("ID          Nombre          Apellido          Edad          Nombre Instrumento          Tipo de Instrumento          Nombre Orquesta\n");

			mostrarMusico(pArrayMusico[indice],pArrayOrquesta,tamArrayOrquesta,pArrayInstrumento,tamArrayInstrumento);
			printf("\n\n");

			utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);


			if(respuesta=='s')
			{
				pArrayMusico[indice].isEmpty=1;
				printf("Se elimino el musico\n");
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
int buscarPosMusico_ID(eMusicos* pArray,int valorBuscado, int size)
{
int indice=-1;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].isEmpty==0 && pArray[i].idMusico==valorBuscado)
		{
			indice=i;
			break;
		}

	}

}

return indice;
}

void bajaMusicoPorIdOrquesta(eMusicos* pArrayMusico,int tamArrayMusico,int idOrquestaBaja)
{
	int i;
	if (pArrayMusico!=NULL && tamArrayMusico>0 && idOrquestaBaja>=0 )
	{
		for(i=0;i<tamArrayMusico;i++)
			{
				if (pArrayMusico[i].isEmpty==0 && pArrayMusico[i].idOrquesta==idOrquestaBaja)
				{
					pArrayMusico[i].isEmpty=1;
				}

			}
	}

}

int modificarMusico(eMusicos* pArrayMusico, int tamArrayMusico, int idMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta, eInstrumento* pArrayInstrumento, int tamArrayInstrumento)
{
	int indice=-1;
	int valorBuscado;
	char respuesta;
	eMusicos auxMusico;
	int ret=0;
	int opcion;

	system("CLS()");
	printf("*****Modificar Musico*****\n\n");
	if(pArrayMusico!=NULL && pArrayOrquesta!=NULL && tamArrayMusico>0 && tamArrayOrquesta>0 && pArrayInstrumento !=NULL && tamArrayInstrumento>0)
	{


		mostrarMusicos(pArrayMusico,tamArrayMusico,pArrayOrquesta,tamArrayOrquesta, pArrayInstrumento,tamArrayInstrumento);
		if(utn_getNumero(&valorBuscado,"Ingrese el Id del musico que desea modificar \n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3))
		{

			indice=buscarPosMusico_ID(pArrayMusico,valorBuscado,tamArrayMusico);
		}


		if(indice==-1)
		{
			printf("No se encontro el musico para el id ingresado\n");
			system("PAUSE()");
		}
		else
		{

			printf("\n\n\n");
			printf("ID          Nombre          Apellido          Edad          Nombre Instrumento          Tipo de Instrumento          Nombre Orquesta\n");
			mostrarMusico(pArrayMusico[indice],pArrayOrquesta,tamArrayOrquesta,pArrayInstrumento,tamArrayInstrumento);
			printf("\n\n");


			opcion=opcionesModificacion();
			if(modiMusico(pArrayMusico[indice],opcion,&auxMusico,pArrayOrquesta,tamArrayOrquesta))
			{

				utn_getCaracter(&respuesta,"Confirma la modificacion (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);

			}

			if(respuesta=='s')
			{
				pArrayMusico[indice]=auxMusico;
				printf("Se modifico el Alumno\n");
				ret=1;
			}

			else
			{
			printf("Se cancelo la modificacion\n");
			system("PAUSE()");
			}

		}
	}

return ret;
}


int modiMusico(eMusicos musicoRec ,int opcion, eMusicos* auxMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta)
{
	eMusicos modifMusico;
	int ret=0;
	int edad;
	int idOrquesta;

	modifMusico=musicoRec;

	switch(opcion)
	{
		case 1:
				{
					if(utn_getNumero(&edad,"Ingrese la edad del musico \n","Error verifique los datos ingresados quedan %d intentos\n",1,99,3))
					{
						modifMusico.edad=edad;
						*auxMusico=modifMusico;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar la edad\n");
					}

					break;
				}
		case 2:
				{

					mostrarOrquestas(pArrayOrquesta,tamArrayOrquesta);

					if(utn_getNumero(&idOrquesta,"Ingrese el ID nuevo de orquesta del musico \n","Error verifique los datos ingresados quedan %d intentos\n",0,50,3))
					{
						modifMusico.idOrquesta=idOrquesta;
						*auxMusico=modifMusico;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el id de orquesta\n");
					}

					break;
				}

		default:
				{
					break;
				}
	}

return ret;
}



int opcionesModificacion()
{
	int opcion=0;
	printf("*****Opciones de Modificacion*****\n\n");

	printf("1-Edad\n");
	printf("2-Id Orquesta\n");
	printf("3-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: \n","Error verifique los datos ingresados quedan %d intentos\n",1,3,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}

// funciones de informes

int musicosMismaOrquesta(eMusicos* pArrayMusicos, int tamArrayMusicos, int idOrquesta)
{
	int ret=0;
	int i;
	int cont=0;

	if(pArrayMusicos!=NULL  && tamArrayMusicos>0)
	{
		for(i=0; i<tamArrayMusicos; i++)
		{
			if(pArrayMusicos[i].isEmpty==0 && pArrayMusicos[i].idOrquesta==idOrquesta)
			{
				cont++;
				if(cont>=5)
				{
					ret=1;
					break;
				}
			}
		}
	}
return ret;
}

