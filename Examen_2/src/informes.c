/*
 * informes.c
 *
 *  Created on: 18 jun. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ventas.h"
#include "utn.h"
#include "LinkedList.h"


int informePorSala(LinkedList* list)
{
	int ret=0;
	int i;
	int j;
	int tam;
	int sala;
	int ingreso;
	int acum=0;
	int cont;
	float totalF=0;
	float monto;
	int qEntradas;
	eVentas* ventasAux;
	LinkedList* listPeliculas= ll_newLinkedList();
	char* peliculaAux;
	char nomPeliVentas[30];


	if(list!=NULL)
	{
		tam=ll_len(list);
		ll_map(list,funcionCalculoMonto);
		if(utn_getNumero(&ingreso,"\n\nElija una sala\n","Error verifique los datos ingresados quedan %d intentos\n",1,10,3))
		{
			for(i=0; i<tam; i++)
			{
				ventasAux=ll_get(list,i);
				eVentas_getSala(ventasAux,&sala);

				if(sala==ingreso)
				{
					cont=0;
					eVentas_getNombrePelicula(ventasAux,nomPeliVentas); //obtengo el nombre de la peli de la sala ingresada

					for(j=0; j<ll_len(listPeliculas);j++)// recorro la linkedlist de peliculas
					{
						peliculaAux=ll_get(listPeliculas,j);
						if(strcmp(peliculaAux,nomPeliVentas)==0)
						{
							cont++;
							break;
						}
					}
					if(cont==0)// si no esta en la lista reservo memoria y la cargo a la linkedlist de peliculas
					{
						char* pelicula=(char*) malloc(sizeof(char)*30);
						strcpy(pelicula,nomPeliVentas);
						ll_add(listPeliculas,pelicula);
					}

					eVentas_getEntradas(ventasAux,&qEntradas);
					eVentas_getMonto(ventasAux,&monto);
					acum+=qEntradas;
					totalF+=monto;
				}
			}
		}

		printf("\n\nLa cantidad de entradas vendidas para la sala es %d\n", acum);
		printf("\n\nEl monto Facturado es %.2f\n", totalF);
		printf("\n\nLas peliculas de la sala son:\n");
		for(j=0; j<ll_len(listPeliculas);j++)
		{
			peliculaAux=ll_get(listPeliculas,j);
			printf("Pelicula [%d] %s\n",j+1,peliculaAux);
		}


	}

	return ret;
}
