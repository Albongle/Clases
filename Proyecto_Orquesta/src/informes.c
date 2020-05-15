/*
 * informes.c
 *
 *  Created on: 10 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "musicos.h"
#include "orquestas.h"
#include "instrumentos.h"
#include "utn.h"
int instrumentosPorMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos,eInstrumento* pArrayInstrumentos, int tamArrayInstrumentos, int idOrquesta);
int mostrarLugares(eOrquesta* pArrayOrquestas, int tamArrayOrquestas, char lugares[][30]);
int qMusicosOrquesta(eMusicos* pArrayMusicos, int tamArrayMusicos, int idOrquesta);



int listarOrquestas(eOrquesta* pArrayOrquestas, int tamArrayOrquestas, eMusicos* pArrayMusicos, int tamArrayMusicos)
{
	int ret=0;
	int i;

	if(pArrayOrquestas!=NULL && pArrayMusicos!=NULL && tamArrayOrquestas>0 && tamArrayMusicos>0)
	{
		printf("ID          Nombre          Lugar          Tipo\n");
		for(i=0; i<tamArrayOrquestas; i++)
		{

			if(musicosMismaOrquesta(pArrayMusicos,tamArrayMusicos,pArrayOrquestas[i].idOrquesta))
			{
				ret=1;
				mostrarOrquesta(pArrayOrquestas[i]);
			}

		}

	}

return ret;
}

int listarMusicosMas30(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas, int tamArrayOrquestas, eInstrumento* pArrayInstrumento, int tamArrayInstrumento)
{
	int ret=0;
	int i;
	if(pArrayMusicos!=NULL && tamArrayMusicos>0 && pArrayOrquestas!=NULL && tamArrayOrquestas>0 && pArrayInstrumento!=NULL && tamArrayInstrumento>0)
	{
		printf("ID          Nombre          Apellido          Edad          Nombre Instrumento          Tipo de Instrumento          Nombre Orquesta\n");
		for(i=0; i<tamArrayMusicos; i++)
		{
			if(pArrayMusicos[i].isEmpty==0 && pArrayMusicos[i].edad>=30)
			{
				ret=1;
				mostrarMusico(pArrayMusicos[i],pArrayOrquestas,tamArrayOrquestas,pArrayInstrumento,tamArrayInstrumento);

			}

		}

	}

return ret;
}


int listarOrquestaLugar(eOrquesta* pArrayOrquestas, int tamArrayOrquestas)
{
	int ret=0;
	char lugar[tamArrayOrquestas][30];
	int qlugares;
	int i;
	int ingreso;
	if(pArrayOrquestas!=NULL && tamArrayOrquestas>0)
	{
		qlugares=mostrarLugares(pArrayOrquestas,tamArrayOrquestas,lugar);
		printf("\n");
		if(qlugares>0)
		{
			for(i=0; i<qlugares; i++)
			{
				printf("lugar [%d] %s\n",i,lugar[i]);
			}


			if(utn_getNumero(&ingreso,"Ingrese el numero del lugar\n","Error verifique los datos ingresados quedan %d intentos\n",0,(qlugares-1),3))
			{
				printf("\n");
				printf("ID          Nombre          Lugar          Tipo\n");
				for(i=0; i<tamArrayOrquestas; i++)
				{
					if(pArrayOrquestas[i].isEmpty==0  && (stricmp(pArrayOrquestas[i].lugar,lugar[ingreso]))==0)
					{
						mostrarOrquesta(pArrayOrquestas[i]);
					}
				}
			}
		}

	}
return ret;
}

int mostrarLugares(eOrquesta* pArrayOrquestas, int tamArrayOrquestas, char lugares[][30])
{

	int pos=-1;
	int i;
	int j;
	int flag=0;

	if(pArrayOrquestas!=NULL && tamArrayOrquestas>0)
	{
		for(i=0; i<tamArrayOrquestas; i++)
		{
			for(j=0; j<(pos+1);j++)
			{
				if(pArrayOrquestas[i].isEmpty==1 || stricmp(pArrayOrquestas[i].lugar,lugares[j])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				pos++;
				strcpy(lugares[pos],pArrayOrquestas[i].lugar);
				flag=0;
			}
		}

	}
return (pos+1);
}

int orquestasCompletas(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas, int tamArrayOrquestas, eInstrumento* pArrayInstrumentos, int tamArrayInstrumentos)
{
	int i;
	int ret=0;

	if(pArrayMusicos!=NULL && tamArrayMusicos>0 && pArrayOrquestas!=NULL && tamArrayOrquestas>0 && pArrayInstrumentos!=NULL && tamArrayInstrumentos>0)
	{

		printf("\n");
		printf("ID          Nombre          Lugar          Tipo\n");
		for(i=0;i<tamArrayOrquestas;i++)
		{

			if(instrumentosPorMusicos(pArrayMusicos,tamArrayMusicos,pArrayInstrumentos,tamArrayInstrumentos,pArrayMusicos[i].idOrquesta))
			{
				mostrarOrquesta(pArrayOrquestas[i]);
				ret=1;
			}

		}



	}
return ret;
}

int instrumentosPorMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos,eInstrumento* pArrayInstrumentos, int tamArrayInstrumentos, int idOrquesta)
{
	int i;
	int ret=0;
	int tipoInstrumento;
	int viento=0;
	int cuerdas=0;
	int percu=0;

	if(pArrayMusicos!=NULL && tamArrayMusicos>0 && pArrayInstrumentos!=NULL && tamArrayInstrumentos>0)
	{
		for(i=0; i<tamArrayMusicos; i++)
		{

			if(pArrayMusicos[i].isEmpty==0 && buscarIDTipoInstrumento_IDInstrumento(pArrayInstrumentos,pArrayMusicos[i].idInstrumento, tamArrayInstrumentos,&tipoInstrumento))
				switch (tipoInstrumento)
				{
					case 1000:
								{
									cuerdas++;
									break;
								}
					case 1001:
					case 1002:
								{

									viento++;
									break;
								}
					case 1003:
								{
									percu++;
									break;
								}
				}
		}

		if(cuerdas>=5 && viento>=3 && percu>=2)
		{
			ret=1;
		}
	}

return ret;
}

int listarMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas, int tamArrayOrquestas,eInstrumento* pArrayInstrumentos,int tamArrayInstrumentos)
{
	int ret=0;
	int i;
	int idOrquesta;


	if(pArrayMusicos!=NULL && tamArrayMusicos>0 && pArrayOrquestas!=NULL && tamArrayOrquestas>0)
	{
		mostrarOrquestas(pArrayOrquestas,tamArrayOrquestas);
		printf("\n\n");
		if(utn_getNumero(&idOrquesta,"Ingrese el ID de orquesta de los musicos que desea listar \n","Error verifique los datos ingresados quedan %d intentos\n",0,50,3))
		{
			printf("\n\n");
			printf("ID          Nombre          Apellido          Edad          Nombre Instrumento          Tipo de Instrumento          Nombre Orquesta\n");
			for(i=0; i<tamArrayMusicos; i++)
			{
				if(pArrayMusicos[i].isEmpty==0 &&pArrayMusicos[i].idOrquesta==idOrquesta)
				{
					mostrarMusico(pArrayMusicos[i],pArrayOrquestas,tamArrayOrquestas,pArrayInstrumentos,tamArrayInstrumentos);
					ret=1;
				}
			}
		}
	}

	return ret;
}

int orquestasMasMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas,int tamArrayOrquestas)
{
	int ret=0;
	int i;
	int posOrq;
	int qMusicos;
	int max;

	if(pArrayMusicos!=NULL && tamArrayMusicos>0 && pArrayOrquestas!=NULL && tamArrayOrquestas>0)
	{
		for(i=0; i <tamArrayOrquestas; i++)
		{
			qMusicos=qMusicosOrquesta(pArrayMusicos,tamArrayMusicos,pArrayOrquestas[i].idOrquesta);
			if(i==0 ||qMusicos>max)
			{
				max=qMusicos;
				posOrq=i;
			}
		}
		printf("La orquesta con (%d) musicos es la que mas musicos tiene, siendo la siguiente:\n",max);
		printf("\n\n");
		printf("ID          Nombre          Lugar          Tipo\n");
		mostrarOrquesta(pArrayOrquestas[posOrq]);
		ret=1;
	}


	return ret;

}

int qMusicosOrquesta(eMusicos* pArrayMusicos, int tamArrayMusicos, int idOrquesta)
{
	int i;
	int cont=0;
	if(pArrayMusicos!=NULL && tamArrayMusicos>0 && idOrquesta>=0 )
	{
		for(i=0;i<tamArrayMusicos; i++)
		{
			if(pArrayMusicos[i].isEmpty==0 && pArrayMusicos[i].idOrquesta==idOrquesta)
			{
				cont++;
			}
		}
	}


	return cont;
}

