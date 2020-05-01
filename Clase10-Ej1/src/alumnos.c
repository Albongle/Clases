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

				printf("Ingrese la fecha de ingreso: dd/mm/aaaa"); // Hacer funcion para validar Fechas
				scanf("%d/%d/%d", &fecha.dia, &fecha.mes,&fecha.anio);


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




static void mostrarAlumno(eAlumnos pArray);
void mostrarAlumnos(eAlumnos* pArray, int size)
{
	int i;
	int flag=0;
	printf("Legajo          Nombre          Apellido          Edad          Sexo          Nota_1          Nota_2          Promedio_Notas          Fecha de Ingreso\n");

	if(pArray!=NULL && size>=0)
		{
			for(i=0;i<size;i++)
			{
				if(pArray[i].isEmpty==0)
				{
					mostrarAlumno(pArray[i]);
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

static void mostrarAlumno(eAlumnos pArray)
{
	printf("%d          %10s          %10s          %d          %c          %.2f          %.2f          %.2f         %d/%d/%d\n",pArray.legajo,pArray.nombre, pArray.apellido,pArray.edad,pArray.sexo,pArray.evaluacion.nota1,pArray.evaluacion.nota2, pArray.evaluacion.promNotas,pArray.fechaIngreso.dia,pArray.fechaIngreso.mes,pArray.fechaIngreso.anio);

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
							if(pArray[i].evaluacion.promNotas<pArray[i+1].evaluacion.promNotas)
								{
									flagSwap = 1;
									change(pArray, i);
								}
							break;
							}
						case '<':
							{
							if(pArray[i].evaluacion.promNotas>pArray[i+1].evaluacion.promNotas)
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
	eAlumnos listaAuxiliar[]=
	{
			{20000, "The", "Negan", 33, 'm',{9,9,8},{1,2,2020},1000,0},
			{20001, "Monica", "Gaztambide", 35, 'f',{5,5,5},{1,2,2019},1001,0},
			{20002, "Raquel", "Murillo", 43, 'f',{9,9,8},{1,2,2018},1002,0},
			{20003, "Rick", "Grimes", 29, 'm',{8,4,6},{1,5,2020},1002,0},
			{20004, "Daryl", "Dixon", 30, 'm',{10,10,10},{1,3,2020},1001,0},
			{20005, "Rosita", "Espinoza", 31, 'f',{8,10,9},{1,2,2020},1001,0},
			{20006, "Judith", "Grimes", 25, 'f',{4,10,7},{5,5,2020},1002,0},
			{20007, "Marty", "Byrde", 22, 'f',{7,7,7},{14,2,2020},1001,0},
			{20008, "Eugene", "Porter", 19, 'm',{10,2,6},{10,2,2020},1000,0},
			{20009, "Jacob", "Shell", 38, 'm',{6,6,6},{15,3,2018},1002,0},

	};

if (cantidad <=size && cantidad && cantidad <11)
{
	for(i=0; i<cantidad; i++)
	{
		pArray[i]=listaAuxiliar[i];
		cont++;
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
		i++;
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
	utn_getNumero(&valorBuscado,"Ingrese el legajo del Alumno dar de baja \n","Error verifique los datos ingresados quedan %d intentos\n",0,99999,3);


	indice=buscarAlumno(pArrayAlumno,valorBuscado,sizeArrayAlumno);
	if(indice==-1)
	{
		printf("No se encontro el alumno para el legajo ingresado\n");
		system("PAUSE()");
	}
	else
	{

		printf("Legajo          Nombre          Apellido          Edad          Sexo          Nota_1          Nota_2          Promedio_Notas          Fecha de Ingreso\n");
		mostrarAlumno(pArrayAlumno[indice]);

		utn_getCaracter(&respuesta,"Confirma la baja (s-n)\n","Error, verifique la respuesta ingresada, quedan %d reintentos","sn\0",3);
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




return ret;
}








