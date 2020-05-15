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
#include "carreras.h"








eAlumnos nuevoAlumno(int legajo,char nombre[],char apellido[], char sexo, int edad, float nota1, float nota2,eFecha fecha,int idCarrera);
int altaAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera)
{
	int indice;
	int ret=0;
	int flag=0;
	char bufferNombre[50];
	char bufferApellido[50];
	int bufferEdad;
	char bufferSexo;
	float bufferNota1;
	float bufferNota2;
	int bufferIdCarrera;
	eFecha fecha;

			system("CLS()");
			printf("*****Alta Alumno*****\n\n");
	if(pArrayAlumno!=NULL && sizeArrayAlumno>=0 && pArrayCarrera!=NULL && sizeArrayCarrera>0)
	{
			indice=buscaIndice(pArrayAlumno,sizeArrayAlumno);

			if(indice==-1)
			{
				printf("Sistema completo, no se puede agregar mas Alumnos\n\n");
				system("PAUSE()");
			}
			else
			{
				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getTexto(bufferNombre,"Ingrese el nombre del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50);
				}while(!flag);
				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getTexto(bufferApellido,"Ingrese el Apellido del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);

				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getCaracter(&bufferSexo,"Ingrese el sexo de Alumno (m o f)\n","Error verifique los datos ingresados debe ser (m o f) quedan %d intentos\n","mf\0",3);

				}while(!flag);

				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getNumero(&bufferEdad,"Ingrese la edad del Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",1,99,3);

				}while(!flag);


				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getNumeroConDecimales(&bufferNota1,"Ingrese la primer nota del Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",0,10,3);

				}while(!flag);

				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getNumeroConDecimales(&bufferNota2,"Ingrese la segunda nota del Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",0,10,3);

				}while(!flag);

				do
				{
					flag=0;
					fflush(stdin);
					flag=utn_getFecha(&fecha.dia,&fecha.mes,&fecha.anio,"Ingrese fecha de ingreso\n","Error verifique la fecha ingresada\n",1,31,1,12,2000,2025,3);
				}while(!flag);

				do
				{
					flag=0;
					fflush(stdin);
					mostrarCarreras(pArrayCarrera,sizeArrayCarrera);
					flag=utn_getNumero(&bufferIdCarrera,"\nIngrese Id de Carrera para el Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",1000,1002,3);

				}while(!flag);


				pArrayAlumno[indice]=nuevoAlumno(legajo,bufferNombre,bufferApellido,bufferSexo,bufferEdad,bufferNota1,bufferNota2,fecha,bufferIdCarrera);
				ret=1;
			}
	}

return ret;

}

eAlumnos nuevoAlumno(int legajo,char nombre[],char apellido[], char sexo, int edad, float nota1, float nota2,eFecha fecha,int idCarrera)
{
	eAlumnos nuevoAlumno;

	nuevoAlumno.legajo=legajo;
	strcpy(nuevoAlumno.nombre,nombre);
	strcpy(nuevoAlumno.apellido,apellido);
	nuevoAlumno.edad=edad;
	nuevoAlumno.sexo=sexo;
	nuevoAlumno.evaluacion.nota1=nota1;
	nuevoAlumno.evaluacion.nota2=nota2;
	nuevoAlumno.evaluacion.promNotas=(nota1+nota2)/2;
	nuevoAlumno.fechaIngreso=fecha;
	nuevoAlumno.idCarrera=idCarrera;
	nuevoAlumno.isEmpty=0;

return nuevoAlumno;
}




void mostrarAlumno(eAlumnos pArrayAlumno,eCarrera* pArrayCarrera,int sizeArrayCarrera);
void mostrarAlumnos(eAlumnos* pArrayAlumno, int sizeArrayAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera)
{
	int i;
	int flag=0;


	if(pArrayAlumno!=NULL && sizeArrayAlumno>=0 && pArrayCarrera!=NULL && sizeArrayCarrera>0)
		{
			printf("Legajo\tNombre\tApellido\tEdad\tSexo\tNota_1\tNota_2\tPromedio_Notas\tFecha de Ingreso\tCarrera\n");
			for(i=0;i<sizeArrayAlumno;i++)
			{
				if(pArrayAlumno[i].isEmpty==0)
				{
					mostrarAlumno(pArrayAlumno[i],pArrayCarrera,sizeArrayCarrera);
					flag=1;
				}
			}
		}

	if(flag==0)
	{
		system("CLS()");
		printf("\n---No hay alumnos que mostrar---\n\n");
	}
}

void mostrarAlumno(eAlumnos pArrayAlumno,eCarrera* pArrayCarrera,int sizeArrayCarrera)
{
	char descrCarrera [20];

	if(pArrayCarrera!=NULL && sizeArrayCarrera>0)
	{
		buscarCarrera(pArrayCarrera,pArrayAlumno.idCarrera,sizeArrayCarrera,descrCarrera);
		printf("%d\t%-2.5s\t%-2.5s\t\t%d\t%c\t%.2f\t%.2f\t%.2f\t\t%d/%d/%d\t\t%s\n",pArrayAlumno.legajo,pArrayAlumno.nombre, pArrayAlumno.apellido,pArrayAlumno.edad,pArrayAlumno.sexo,pArrayAlumno.evaluacion.nota1,pArrayAlumno.evaluacion.nota2, pArrayAlumno.evaluacion.promNotas,pArrayAlumno.fechaIngreso.dia,pArrayAlumno.fechaIngreso.mes,pArrayAlumno.fechaIngreso.anio,descrCarrera);
	}
}


int buscaIndice(eAlumnos* pArray, int size)
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

void iniArrayAlumnos(eAlumnos* pArray,int size,int valorInt)
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



static void change(eAlumnos* pArray, int pos);
int ordenaAlumnos(eAlumnos* pArray,int size, char sentido)
{
	int flagSwap=1;
	int i;
	int cont=0;
	int retorno = 0;
	if(pArray != NULL && size > 0 && sentido!=' ')
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
							if(pArray[i].evaluacion.promNotas<pArray[i+1].evaluacion.promNotas && pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0)
								{
									flagSwap = 1;
									change(pArray, i);
								}
							break;
							}
						case '<':
							{
							if(pArray[i].evaluacion.promNotas>pArray[i+1].evaluacion.promNotas && pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0)
								{
									flagSwap = 1;
									change(pArray, i);
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

static void change(eAlumnos* pArray, int pos)
{
	eAlumnos buffer;

	if (pArray!=NULL && pos >=0)
	{
		buffer=pArray[pos];
		pArray[pos]=pArray[pos+1];
		pArray[pos+1]=buffer;
	}
}


int hardcodearAlumnos(eAlumnos* pArray, int size, int cantidad)
{

	int cont=0;
	int i;
	if(pArray!=NULL && size>0 && cantidad >0)
	{
		eAlumnos listaAuxiliar[]=
		{
			{20000, "The", "Negan", 33, 'm',{9,9,8},{01,02,2020},1000,0},
			{20001, "Monica", "Gaztambide", 35, 'f',{5,5,5},{01,02,2019},1001,0},
			{20002, "Raquel", "Murillo", 43, 'f',{9,9,8},{01,02,2018},1002,0},
			{20003, "Rick", "Grimes", 29, 'm',{8,4,6},{01,05,2020},1002,0},
			{20004, "Daryl", "Dixon", 30, 'm',{10,10,10},{01,03,2020},1001,0},
			{20005, "Rosita", "Espinoza", 31, 'f',{8,10,9},{01,02,2020},1001,0},
			{20006, "Judith", "Grimes", 25, 'f',{4,10,7},{05,05,2020},1002,0},
			{20007, "Marty", "Byrde", 22, 'f',{7,7,7},{14,02,2020},1001,0},
			{20008, "Eugene", "Porter", 19, 'm',{10,2,6},{10,02,2020},1000,0},
			{20009, "Jacob", "Shell", 38, 'm',{6,6,6},{15,03,2018},1002,0},

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


int buscarAlumno(eAlumnos* pArray,int valorBuscado, int size)
{
int indice=-1;
int i;
if(pArray!=NULL && size>0 )
{

	for(i=0;i<size;i++)
	{
		if (pArray[i].isEmpty==0 && pArray[i].legajo==valorBuscado)
		{
			indice=i;
			break;
		}

	}

}

return indice;
}

int bajaAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera)
{
	int indice;
	int valorBuscado;
	char respuesta;
	int ret=0;

	system("CLS()");
	printf("*****Baja Alumno*****\n\n");
	if(pArrayAlumno!=NULL && pArrayCarrera!=NULL && sizeArrayAlumno>0 &&sizeArrayCarrera>0)
	{

		utn_getNumero(&valorBuscado,"Ingrese el legajo del Alumno dar de baja \n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3);

		indice=buscarAlumno(pArrayAlumno,valorBuscado,sizeArrayAlumno);
		if(indice==-1)
		{
			printf("No se encontro el alumno para el legajo ingresado\n");
			system("PAUSE()");
		}
		else
		{

			printf("Legajo\tNombre\tApellido\tEdad\tSexo\tNota_1\tNota_2\tPromedio_Notas\tFecha de Ingreso\tCarrera\n");
			mostrarAlumno(pArrayAlumno[indice],pArrayCarrera,sizeArrayCarrera);
			printf("\n\n");

			utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);


			if(respuesta=='s')
			{
				pArrayAlumno[indice].isEmpty=1;
				printf("Se elmino el Alumno\n");
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

int modifAlumno(eAlumnos alumnoRec ,int opcion, eAlumnos* auxAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera);
int opcionesModificacion();
int modificarAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera)
{
	int indice;
	int valorBuscado;
	char respuesta;
	eAlumnos auxAlumno;
	int ret=0;
	int opcion;

	system("CLS()");
	printf("*****Modificar Alumno*****\n\n");
	if(pArrayAlumno!=NULL && pArrayCarrera!=NULL && sizeArrayAlumno>0 &&sizeArrayCarrera>0)
	{

		utn_getNumero(&valorBuscado,"Ingrese el legajo del Alumno que desea modificar \n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3);

		indice=buscarAlumno(pArrayAlumno,valorBuscado,sizeArrayAlumno);
		if(indice==-1)
		{
			printf("No se encontro el alumno para el legajo ingresado\n");
			system("PAUSE()");
		}
		else
		{

			printf("\n\n\n");
			printf("Legajo\tNombre\tApellido\tEdad\tSexo\tNota_1\tNota_2\tPromedio_Notas\tFecha de Ingreso\tCarrera\n");
			mostrarAlumno(pArrayAlumno[indice],pArrayCarrera,sizeArrayCarrera);
			printf("\n\n");
			opcion=opcionesModificacion();

			if(modifAlumno(pArrayAlumno[indice],opcion,&auxAlumno,pArrayCarrera,sizeArrayCarrera))
			{

				utn_getCaracter(&respuesta,"Confirma la modificacion (s-n)\n","Error, verifique la respuesta ingresada\n","sn\0",3);

			}
			if(respuesta=='s')
			{
				pArrayAlumno[indice]=auxAlumno;
				printf("Se modifico el Alumno\n");
				ret=1;
			}

			else
			{
			printf("Se cancelo la modificacion\n");
			}

		}
	}

return ret;
}


int modifAlumno(eAlumnos alumnoRec ,int opcion, eAlumnos* auxAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera)
{
	eAlumnos modifAlumno;
	int ret=0;
	char nombre[50];
	char apellido[50];
	char sexo;
	int edad;
	float nota1;
	float nota2;
	eFecha fecha;
	int idCarrera;

	modifAlumno=alumnoRec;

	switch(opcion)
	{
		case 1:
				{
					if(utn_getTexto(nombre,"Ingrese el nombre del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						strcpy(modifAlumno.nombre,nombre);
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el nombre\n");
					}

					break;
				}
		case 2:
				{
					if(utn_getTexto(nombre,"Ingrese el Apellido del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50))
					{
						strcpy(modifAlumno.apellido,apellido);
						*auxAlumno=modifAlumno;
						ret=1;
							}
					else
					{
						printf("No se pudo modificar el Apellido\n");
					}

					break;
				}
		case 3:
				{
					if(utn_getCaracter(&sexo,"Ingrese el sexo de Alumno (m o f)\n","Error verifique los datos ingresados debe ser (m o f) quedan %d intentos\n","mf\0",3))
					{
						modifAlumno.sexo=sexo;
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
								printf("No se pudo modificar el sexo del alumno\n");
					}

					break;
				}
		case 4:
				{
					if(utn_getNumero(&edad,"Ingrese la edad del Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",1,99,3))
					{
						modifAlumno.edad=edad;
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar la edad del alumno\n");
					}

					break;
				}
		case 5:
				{
					if(utn_getNumeroConDecimales(&nota1,"Ingrese la primer nota del Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",0,10,3))
					{
						modifAlumno.evaluacion.nota1=nota1;
						modifAlumno.evaluacion.promNotas=(modifAlumno.evaluacion.nota1+modifAlumno.evaluacion.nota2)/2;
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar la nota 1 del alumno\n");
					}

					break;
				}
		case 6:
				{
					if(utn_getNumeroConDecimales(&nota2,"Ingrese la segunda nota del Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",0,10,3))
					{
						modifAlumno.evaluacion.nota2=nota2;
						modifAlumno.evaluacion.promNotas=(modifAlumno.evaluacion.nota1+modifAlumno.evaluacion.nota2)/2;
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar la nota 2 del alumno\n");
					}

					break;
				}
		case 7:
				{

					mostrarCarreras(pArrayCarrera,sizeArrayCarrera);
					if(utn_getNumero(&idCarrera,"\nIngrese Id de Carrera para el Alumno\n","Error verifique los datos ingresados quedan %d intentos\n",1000,1002,3))
					{
						modifAlumno.idCarrera=idCarrera;
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar el Id de carrera del alumno\n");
					}

					break;
				}

		case 8:
				{
					if(utn_getFecha(&fecha.dia,&fecha.mes,&fecha.anio,"Ingrese fecha de ingreso\n","Error verifique la fecha ingresada\n",1,31,1,12,2000,2025,3))
					{
						modifAlumno.fechaIngreso=fecha;
						*auxAlumno=modifAlumno;
						ret=1;
					}
					else
					{
						printf("No se pudo modificar la fecha de ingreso del alumno\n");
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

	printf("1-Nombre\n");
	printf("2-Apellido\n");
	printf("3-Sexo\n");
	printf("4-Edad\n");
	printf("5-Nota 1\n");
	printf("6-Nota 2\n");
	printf("7-Id Carrera\n");
	printf("8-Fecha de Ingreso\n");
	printf("9-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: \n","Error verifique los datos ingresados quedan %d intentos\n",1,9,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}








