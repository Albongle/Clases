/*
 * alumnos.c
 *
 *  Created on: 29 abr. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "alumnos.h"








int getSetDeDatos(eAlumnos* datosAux, int sizeArray, int* pos)
{
	int i;
	int ret=0;
	int flag=0;
	int bufferLegajo;
	char bufferNombre[50];
	char bufferApellido[50];
	float bufferNota;
	char respuesta;
	char mensaje[1024];
	char numeroTexto[10];
	int posLegajo;
	char bufferSexo;

	if(*pos==0)
	{
		i=0;

	}
	else
	{
		i=*pos;
	}

	if(datosAux!=NULL)
	{


		do
		{
			system("CLS()");
			strcpy(mensaje,"Ingrese el legajo del alumno ");
			strcat(mensaje,itoa((i+1),numeroTexto,10));
			strcat(mensaje,"\n");
			fflush(stdin);

			do
			{
				flag=0;
				fflush(stdin);

				flag=utn_getNumero(&bufferLegajo,mensaje,"Error verifique los datos ingresados quedan %d intentos\n",1,999,3);
				if(flag==1 && !(buscaLegajo(datosAux,bufferLegajo,i,&posLegajo)))
				{
					datosAux[i].legajo=bufferLegajo;

				}
				else if (flag==0)
				{

					printf("Supero el maximo de intentos\n\n");
					break;


				}
				else
				{
					printf("Se encontro el legajo ingresado en la posicion %d\n", posLegajo);
					strcpy(mensaje,"Ingrese otro legajo para el alumno ");
					strcat(mensaje,itoa((i+1),numeroTexto,10));
					strcat(mensaje,"\n");
					flag=0;
				}

			}while(!flag);

			if(flag==1)
			{

				do
				{
					strcpy(mensaje,"Ingrese el nombre del alumno ");
					strcat(mensaje,itoa((i+1),numeroTexto,10));
					strcat(mensaje,"\n");

					flag=0;
					fflush(stdin);
					flag=utn_getTexto(bufferNombre,mensaje,"Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);

				strcpy(datosAux[i].nombre,bufferNombre);
				do
				{

					strcpy(mensaje,"Ingrese el apellido del alumno ");
					strcat(mensaje,itoa((i+1),numeroTexto,10));
					strcat(mensaje,"\n");
					flag=0;
					fflush(stdin);
					flag=utn_getTexto(bufferApellido,mensaje,"Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);


				strcpy(datosAux[i].apellido,bufferApellido);

				strcpy(mensaje,"Ingrese el sexo del alumno ");
				strcat(mensaje,itoa((i+1),numeroTexto,10));
				strcat(mensaje,"(m-f)\n");
				flag=0;
				fflush(stdin);

				do
				{
					flag=0;
					flag=utn_getCaracter(&bufferSexo,mensaje,"Error verifique los datos ingresados debe ser (m o f) quedan %d intentos\n","mf\0",3);

				}while(!flag);

				datosAux[i].sexo=bufferSexo;

				do
				{
					strcpy(mensaje,"Ingrese la primera nota del alumno ");
					strcat(mensaje,itoa((i+1),numeroTexto,10));
					strcat(mensaje," (0-10)\n");
					flag=0;
					fflush(stdin);
					flag=utn_getNumeroConDecimales(&bufferNota,mensaje,"Error verifique los datos ingresados quedan %d intentos\n",0,10,3);

				}while(!flag);

				datosAux[i].evaluacion.nota1=bufferNota;

				do
				{
					strcpy(mensaje,"Ingrese la segunda nota del alumno ");
					strcat(mensaje,itoa((i+1),numeroTexto,10));
					strcat(mensaje," (0-10)\n");
					flag=0;
					fflush(stdin);
					flag=utn_getNumeroConDecimales(&bufferNota,mensaje,"Error verifique los datos ingresados quedan %d intentos\n",0,10,3);

				}while(!flag);

				datosAux[i].evaluacion.nota2=bufferNota;
				datosAux[i].evaluacion.promNotas=(datosAux[i].evaluacion.nota1+datosAux[i].evaluacion.nota2)/2;

				i++;

				if((sizeArray)>i)
				{
					fflush(stdin);
					if(!(utn_getCaracter(&respuesta,"Desea seguir ingresado datos (s-n)\n","Error, verifique la respuesta ingresada, quedan %d reintentos","sn\0",3)))
					{
						printf("Supero el maximo de intentos");
						break;
					}
				}


				ret=1;
			}
			else
			{
				printf("No se ingreso ningun dato\n\n\n");
				system("PAUSE()");
				datosAux[i].legajo=-1;
				break;
				ret=0;

			}


			*pos=i;

		}while(respuesta!='n' && i <sizeArray);

	}

return ret;

}



static void mostrarDato(eAlumnos datosAux);
void mostrarDatos(eAlumnos* datosAux, int size)
{
	int i;
	printf("Legajo          Nombre          Apellido          Nota_1          Nota_2          Promedio_Notas\n");

	if(datosAux!=NULL && size>=0)
		{
			for(i=0;i<size;i++)
			{
				mostrarDato(datosAux[i]);
			}
		}
}

static void mostrarDato(eAlumnos datosAux)
{
	printf("%d          %s          %s          %.2f          %.2f          %.2f\n",datosAux.legajo,datosAux.nombre, datosAux.apellido,datosAux.evaluacion.nota1,datosAux.evaluacion.nota2, datosAux.evaluacion.promNotas);

}


int buscaLegajo(eAlumnos* datosAux,int valorBuscado, int size, int* pos)
{
int ret=0;
int i=0;
if(datosAux!=NULL && size>0 )
{

	while(datosAux[i].legajo!=-1 && i<size)
	{
		if (datosAux[i].legajo==valorBuscado)
		{ret=1;
		*pos=i;
		break;
		}
		i++;
	}

}

return ret;
}

iniArrayAlumnos(eAlumnos* datosAux,int size,int valorInt, char valorStr)
{
	int i;
	int ret=0;

	if(datosAux!=NULL && size>0)
	{
		for(i = 0; i < size; i++)
		{

			datosAux[i].legajo=valorInt;

		}
	ret=1;
	}
return ret;
}



static void change(eAlumnos* datosAux, int pos);
int ordenaNombre(eAlumnos* datosAux,int size, char sentido)
{
	int flagSwap=1;
	int i;
	int cont=0;
	int retorno = 0;
	if(datosAux != NULL && size > 0)
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
							if(strcmp(datosAux[i].nombre,datosAux[i+1].nombre)>0)
								{
									flagSwap = 1;
									change(datosAux, i);
								}
							break;
							}
						case '<':
							{
							if(strcmp(datosAux[i].nombre,datosAux[i+1].nombre)<0)
								{
									flagSwap = 1;
									change(datosAux, i);
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

static void change(eAlumnos* datosAux, int pos)
{
	eAlumnos buffer;

if (datosAux!=NULL && pos >=0)
{
	buffer=datosAux[pos];
	datosAux[pos]=datosAux[pos+1];
	datosAux[pos+1]=buffer;
}
}







