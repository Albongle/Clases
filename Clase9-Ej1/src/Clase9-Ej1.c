/*
 ============================================================================
 Name        : Clase9-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "anb_f.h"
#define ELEMENTOS 2
#define SIZE_CARACTERES 50

void mostrarDato(int aLegajo, char aNombre[50], char aApellido[50], char aSexo, int aEdad, float aNota1, float aNota2, float aPromNota);
void mostrarDatos(int* aLegajo, char aNombre[][50], char aApellido[][50], char* aSexo, int* aEdad, float* aNota1, float* aNota2, float* aPromNota, int size);
int getSetDeDatos(int* aLegajo, char aNombre[][50], char aApellido[][50], char* aSexo, int* aEdad, float* aNota1, float* aNota2, float* aPromNota, int sizeArray);
int main(void) {

		setbuf(stdout, NULL);
		int arrayLegajo[ELEMENTOS];
		char arrayNombre[ELEMENTOS][SIZE_CARACTERES];
		char arrayApellido[ELEMENTOS][SIZE_CARACTERES];
		char arraySexo[ELEMENTOS];
		int arrayEdad[ELEMENTOS];
		float arrayNotas1[ELEMENTOS];
		float arrayNotas2[ELEMENTOS];
		float promNota[ELEMENTOS];



		iniArrayInt(arrayLegajo,ELEMENTOS,0);
		iniArrayString(arrayNombre,ELEMENTOS,'\0');
		iniArrayString(arrayApellido,ELEMENTOS,'\0');
		iniArrayInt(arrayEdad,ELEMENTOS,0);
		iniArrayChar(arraySexo,ELEMENTOS,'\0');
		iniArrayFloat(arrayNotas1,ELEMENTOS,0);
		iniArrayFloat(arrayNotas2,ELEMENTOS,0);
		iniArrayFloat(promNota,ELEMENTOS,0);


		getSetDeDatos(arrayLegajo,arrayNombre,arrayApellido,arraySexo,arrayEdad,arrayNotas1,arrayNotas2,promNota,ELEMENTOS);
		mostrarDatos(arrayLegajo,arrayNombre,arrayApellido,arraySexo,arrayEdad,arrayNotas1,arrayNotas2,promNota,ELEMENTOS);






			system("PAUSE()");;

return 0;
}




int getSetDeDatos(int* aLegajo, char aNombre[][50], char aApellido[][50], char* aSexo, int* aEdad, float* aNota1, float* aNota2, float* aPromNota, int sizeArray)
{
	int i;
	int ret=0;
	int auxLegajo;
	char auxNombre[50];
	char auxApellido[50];
	char auxSexo;
	int auxEdad;
	float auxNota1;
	float auxNota2;
	int flag;



	if(aLegajo!=NULL && aNombre!=NULL && aApellido!=NULL && aSexo!=NULL && aEdad!=NULL && aNota1!=NULL && aNota2!=NULL && aPromNota!=NULL && sizeArray>0)
	{

		for(i=0;i<sizeArray;i++)
		{
			fflush(stdin);

			if(utn_getNumero(&auxLegajo,"Ingrese el legajo del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",1,999,3))
			{
				aLegajo[i]=auxLegajo;
				do
				{
					flag=0;
					flag=utn_getTexto(auxNombre,"Ingrese el nombre del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);

				strcpy(aNombre[i],auxNombre);
				do
				{
					flag=0;
					flag=utn_getTexto(auxApellido,"Ingrese el Apellido del alumno\n","Error verifique los datos ingresados quedan %d intentos\n",3,50);

				}while(!flag);

				strcpy(aApellido[i],auxApellido);

				do
				{
					flag=0;
					flag=utn_getCaracter(&auxSexo,"Ingrese el sexo del alumno (m o f)\n","Error verifique los datos ingresados debe ser (m o f) quedan %d intentos\n","mf\0",3);

				}while(!flag);

				aSexo[i]=auxSexo;

				do
				{
					flag=0;
					flag=utn_getNumero(&auxEdad,"Ingrese la edad del alumno (1-99)\n","Error verifique los datos ingresados quedan %d intentos\n",1,99,3);

				}while(!flag);

				aEdad[i]=auxEdad;

				do
				{
					flag=0;
					flag=utn_getNumeroConDecimales(&auxNota1,"Ingrese la nota1 del alumno (0-10)\n","Error verifique los datos ingresados quedan %d intentos\n",0,10,3);

				}while(!flag);

				aNota1[i]=auxNota1;

				do
				{
					flag=0;
					flag=utn_getNumeroConDecimales(&auxNota2,"Ingrese la nota2 del alumno (0-10)\n","Error verifique los datos ingresados quedan %d intentos\n",0,10,3);

				}while(!flag);

				aNota2[i]=auxNota2;
				aPromNota[i]=(auxNota1+auxNota2)/2;
				ret=1;
			}
			else
			{
				printf("No se ingreso ningun dato");
				aLegajo[i]=0;
				break;
				ret=0;
			}



		}

	}

return ret;

}


void mostrarDato(int aLegajo, char aNombre[50], char aApellido[50], char aSexo, int aEdad, float aNota1, float aNota2, float aPromNota)
{
	printf("%d					%s				%s				%c				%d				%.2f				%.2f				%.2f\n",aLegajo,aNombre,aApellido,aSexo,aEdad,aNota1,aNota2,aPromNota);

}

void mostrarDatos(int* aLegajo, char aNombre[][50], char aApellido[][50], char* aSexo, int* aEdad, float* aNota1, float* aNota2, float* aPromNota, int size)
{
	int i;
	printf("Legajo					Nombre				Apellido				Sexo				Edad				Nota_1				Nota_2				Prom_Nota\n");

	if(aLegajo!=NULL && aNombre!=NULL && aApellido!=NULL && aSexo!=NULL && aEdad!=NULL && aNota1!=NULL && aNota2!=NULL && aPromNota!=NULL && size>0)
		{
			for(i=0;i<size;i++)
			{
				mostrarDato(aLegajo[i],aNombre[i],aApellido[i],aSexo[i],aEdad[i],aNota1[i],aNota2[i],aPromNota[i]);
			}
		}
}

/*int arrayLegajo[QTY_ALUMNOS];
	char arrayNombre[QTY_ALUMNOS][SIZE_CARACTERES];
	char arrayApellido[QTY_ALUMNOS][SIZE_CARACTERES];
	char arraySexo[QTY_ALUMNOS];
	int arrayEdades[QTY_ALUMNOS];
	float arrayNotas1[QTY_ALUMNOS];
	float arrayNotas2[QTY_ALUMNOS];
	int eMax;
	int eMin;
	float nMax;
	float nMin;
	int i;

	iniArrayInt(arrayEdades,QTY_ALUMNOS,0);
	iniArrayInt(arrayLegajo,QTY_ALUMNOS,0);
	iniArrayFloat(arrayNotas1,QTY_ALUMNOS,0);
	iniArrayString(arrayNombre,QTY_ALUMNOS,'\0');
	iniArrayString(arrayApellido,QTY_ALUMNOS,'\0');

	getArrayInt(arrayLegajo,QTY_ALUMNOS,"Ingrese el legajo del alumno \n","Error debe ser entre 0 y 100\n",0,100,3, &i);
	getArrayString(arrayNombre,i,SIZE_CARACTERES ,"Ingrese el nombre del Alumno:\n","Error verifique el dato ingresado, quedan %d reintentos\n",2,&i);
	getArrayString(arrayApellido,i,SIZE_CARACTERES ,"Ingrese el apellido del Alumno:\n","Error verifique el dato ingresado, quedan %d reintentos\n",2,&i);
	getArrayChar(arraySexo,i,"Ingrese el sexo del Alumno (f o m):\n","Error verifique el dato ingresado, quedan %d reintentos\n","fm\0",3,&i);
	getArrayInt(arrayEdades,i,"Ingrese la edad\n","Error debe ser entre 0 y 100\n",0,100,3, &i);
	getArrayFloat(arrayNotas1,i,"Ingrese la nota\n","Error debe ser entre 0 y 10\n",0,10,3, &i);


	printf("imprimo ingreso \n");
	imprimirArrayString(arrayNombre,i);
	ordenaArrayString(arrayNombre,i,'<');
	printf("\n");
	printf("imprimo ordenado \n");
	imprimirArrayString(arrayNombre,i);







	imprimirArrayInt(arrayEdades,i);
	printf("\n");
	imprimirArrayFloat(arrayNotas1,QTY_ALUMNOS);
	printf("\n");

	if(devuelveMaxAndMin(arrayEdades,i,&eMax,&eMin))
	{
		printf("El minimo de edad es %d\n", eMin);
		printf("El maximo de edad es %d\n", eMax);
		printf("\n");
	}
	if(devuelveMaxAndMinFloat(arrayNotas1,QTY_ALUMNOS,&nMax,&nMin))
	{
		printf("El minimo de nota es %.2f\n", nMin);
		printf("El maximo de nota es %.2f\n", nMax);
	}*/


