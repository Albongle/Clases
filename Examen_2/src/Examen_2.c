/*
 ============================================================================
 Name        : Examen_2.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "ventas.h"
#include "informes.h"
#include "parser.h"
#define ACRHNUEVO "dataCopy.csv"

int menu();



int main()
{
	system("COLOR 1F");
	setbuf(stdout, NULL);
    int opcion;
    int i;
    int tam;
    char arch[30];
    FILE* pFile;
    eVentas* ventaAux=NULL;
    LinkedList* listaVentas= ll_newLinkedList();
    do{
    	system("CLS()");
    	printf("\t\t****Linkedist posee %d  en su lista****\n\n",ll_len(listaVentas));
    	opcion=menu();
        switch(opcion)
        {
            case 1:
            {
            	fflush(stdin);
            	printf("\nIngrese el nombre del archivo\n");
            	scanf("%s",arch);
            	if((pFile=fopen(arch,"r"))!=NULL)
            	{
            		if(parser_VentasComoTexto(pFile,listaVentas))
            		{
            			printf("\n\n****Se cargaron los datos****\n");
            			fclose(pFile);
            		}
            	}
            	else
            	{
            		printf("\n\n****No se pudo abrir el archivo****\n");
            	}

            	break;
            }
            case 2:
            {
            	if ((tam=ll_len(listaVentas))>0)
            	{
            		system("CLS()");
            		printf("\n\n****Listado de Ventas****\n");
            		printf("\n\n\nId\tdia\tNombre Pelicula\t\tHorario\tSala\tQ_Entradas\n");
            		for (i=0;i<tam;i++)
            		{
            			ventaAux=ll_get(listaVentas,i);
            			if(ventaAux!=NULL)
            			{
            				ventas_Print(ventaAux);
            			}
            		}
            	}
            	else
            	{

            		printf("\n\n\nEl sitema no posee Ventas\n");
            	}

            	break;
            }
            case 3:
            {

            	if((pFile=fopen(ACRHNUEVO,"w"))!=NULL)
            	{
            		if(guardarVentascomoTexto(pFile,listaVentas))
            		{
            			printf("\n\n****Se guardaron los datos****\n");
            			fclose(pFile);
            		}
            	}

            	break;
            }
            case 4:
            {
            	informePorSala(listaVentas);

            	  system("PAUSE()");
            	break;
            }

            default:
            {


            	break;
            }
        }
        system("PAUSE()");
    }while(opcion != 10);


    return 0;
}



int menu()
{
	int opcion=-1;
	printf("Menu de opciones\n\n");
	printf("1-Cargar archivo\n");
	printf("2-Imprimir Ventas\n");
	printf("3-Generar archivo de montos\n");
	printf("4-Informes\n");
	printf("5-Salir\n");
	fflush(stdin);
	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,5,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}

return opcion;
}

