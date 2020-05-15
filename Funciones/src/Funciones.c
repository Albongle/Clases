/*
 ============================================================================
 Name        : Funciones.c
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
#define CANTIDAD 5

typedef struct{
	int entero;
	float floatante;
	char cadena[20];
	int isEmpty;

}eExamen;
int vocales(char arrayString[], char* vocal);
int hardcodearArray(eExamen* pArray, int tam, int cantidad);
int ordenaArray(eExamen* pArray,int tamArray, int sentido);
void swap(eExamen* pArray, int pos);
void imprimeArrays(eExamen* pArray, int tamArray);
void imprimeArray(eExamen pArray);
int main(void) {
 eExamen variable[CANTIDAD];
 int cant;
 char cadena[30];
 char vocal;
 int qVocales;

 setbuf(stdout, NULL);

 cant=hardcodearArray(variable, CANTIDAD,5);
 ordenaArray(variable,cant,1);
 imprimeArrays(variable,CANTIDAD);
 printf("Ingrese un texto de 30 Carcteres:\n");
 scanf("%s", cadena);
 qVocales=vocales(cadena, &vocal);

 printf("\n\n");
 printf("el texto tiene %d vocales [%c]",qVocales,vocal);

}


int ordenaArray(eExamen* pArray,int tamArray, int sentido)
{
	int flagSwap=1;
	int i;
	int cont=0;
	int retorno = 0;




	if(pArray != NULL && tamArray> 0  && (sentido==0 || sentido ==1))
			{
				while(flagSwap)
				{
					cont++;
					flagSwap = 0;
					for(i = 0 ; i < tamArray-cont ; i++)
					{
						switch (sentido)
						{
						case 0:
							{
							if((stricmp(pArray[i].cadena,pArray[i+1].cadena))<0 && pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0)
								{
									flagSwap = 1;
									swap(pArray, i);
								}
							else if((stricmp(pArray[i].cadena,pArray[i+1].cadena))==0 && pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0)
							{

								if(pArray[i].floatante<pArray[i+1].floatante)
								{
									flagSwap = 1;
									swap(pArray, i);
								}

							}
							break;
							}
						case 1:
							{
							if((stricmp(pArray[i].cadena,pArray[i+1].cadena))>0 && pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0)
								{
									flagSwap = 1;
									swap(pArray, i);
								}

							else if((stricmp(pArray[i].cadena,pArray[i+1].cadena))==0 && pArray[i].isEmpty==0 && pArray[i+1].isEmpty==0)
								{

									if(pArray[i].floatante>pArray[i+1].floatante)
									{
										flagSwap = 1;
										swap(pArray, i);
									}

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

void swap(eExamen* pArray, int pos)
{
	eExamen buffer;

	if (pArray!=NULL && pos >=0)
	{
		buffer=pArray[pos];
		pArray[pos]=pArray[pos+1];
		pArray[pos+1]=buffer;
	}
}

int hardcodearArray(eExamen* pArray, int tam, int cantidad)
{

	int cont=0;
	int i;
	if(pArray!=NULL && tam>0 && cantidad >0)
	{
		eExamen listaAuxiliar[]=
		{
			{0, 10.5, "Alejandro",0},
			{1, 9.5, "Pedro",0},
			{2, 18.5, "Samuel",0},
			{3, 5.5, "Alejandro",0},
			{4, 4.5, "Pedro",0},
			{5, 2.5, "Jose",0},
			{6, 0.5, "Jose",0},
			{7, 10.5, "Roberto",0},
			{8, 177.5, "Sebastian",0},
			{9, 14.5, "Jose",0},

		};


		if (cantidad <=tam && cantidad && cantidad <11)
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



void imprimeArrays(eExamen* pArray, int tamArray)
{
	int i;
	int flag=0;


	if(pArray!=NULL && tamArray>=0)
		{
			printf("Entero	Flotante	Cadena\n");
			for(i=0;i<tamArray;i++)
			{
				if(pArray[i].isEmpty==0)
				{
					imprimeArray(pArray[i]);
					flag=1;
				}
			}
		}

	if(flag==0)
	{
		system("CLS()");
		printf("\n---No hay Empleados que mostrar---\n\n");
	}
}

void imprimeArray(eExamen pArray)
{


		printf("%d	%.2f	%s\n",pArray.entero, pArray.floatante,pArray.cadena);

}


int vocales(char arrayString[], char* vocal)
{
	int cantidad;
	int maxVocal;
	int i;
	int j;
	char vocales[]={'a','e','i','o','u'};
	char caracter;


	if(arrayString!=NULL)
	{
		for(i=0; i<6; i++)
		{
			cantidad=0;
			for(j=0; j<strlen(arrayString); j++)
			{
				if(vocales[i]==arrayString[j])
				{
					cantidad++;
				}
			}
			if(i==0 || cantidad>maxVocal)
			{
				maxVocal=cantidad;
				caracter=vocales[i];
			}
		}
	}
	*vocal=caracter;
	return maxVocal;
}
