/*
 ============================================================================
 Name        : Clase13-Ej1.c
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
#include "musicos.h"
#include "orquestas.h"
#include "instrumentos.h"
#include "informes.h"
#define Q_MUSICOS 1000
#define Q_ORQUESTAS 50
#define Q_TIPOSORQUESTAS 3
#define Q_INSTRUMENTOS 20
#define Q_TIPOINSTRUMENTOS 4

int menu();
int subMenuInformes();
int main(void) {

system("COLOR E");

		setbuf(stdout, NULL);
		eMusicos listadoMusicos[Q_MUSICOS];
		eOrquesta listadoOrquestas[Q_ORQUESTAS];
		eTipoOrquesta tiposOrquesta[]= {{1000, "Sinfonica",0},{1001, "Filarmonica",0},{1002, "Camara",0}}; //Hardcodeo tipo orquesta
		eInstrumento listadoInstrumentos[Q_INSTRUMENTOS];
		eTipoInstrumento tiposInstrumento[]= {{1000,"Cuerdas",0},{1001,"Viento-madera",0},{1002,"Viento-metal",0},{1003,"Percusion",0}}; //Hardcodeo tipo instrumento

		int ingreso;
		int ingresoInforme;
		int idMusico=0;
		int idOrquesta=0;
		int idOrquestaBaja;
		int idInstrumento=0;

		iniArrayMusicos(listadoMusicos,Q_MUSICOS,1); // inicializo array Musicos poniendo en isEmpty 1
		iniArrayOrquestas(listadoOrquestas,Q_ORQUESTAS,1); // inicializo array Orquestas poniendo en isEmpty 1
		iniArrayInstrumentos(listadoInstrumentos,Q_INSTRUMENTOS,1); // inicializo array Orquestas poniendo en isEmpty 1

		///*
		idMusico=idMusico+hardcodearMusicos(listadoMusicos,Q_MUSICOS,5);
		idOrquesta=idOrquesta+hardcodearOrquestas(listadoOrquestas,Q_ORQUESTAS,5);
		idInstrumento=idInstrumento+hardcodearInstrumentos(listadoInstrumentos,Q_INSTRUMENTOS,5);
		 //*/

		do
		{
			system("CLS()");
			ingreso=menu();
			switch (ingreso)
			{
				case 1: //Alta Orquesta
				{
					if(altaOrquesta(listadoOrquestas,Q_ORQUESTAS,idOrquesta,tiposOrquesta,Q_TIPOSORQUESTAS))
					{
						idOrquesta++;

					}
					else
					{
						printf("Se cancelo el alta del la orquesta");
					}

					break;
				}
				case 2: //Eliminar Orquesta
				{


					if(bajaOrquesta(listadoOrquestas,Q_ORQUESTAS,&idOrquestaBaja))
					{
					bajaMusicoPorIdOrquesta(listadoMusicos,Q_MUSICOS,idOrquestaBaja);
					}
					else
					{
						printf("Se cancelo la baja de Orquesta\n");
					}
					system("PAUSE()");
					break;
				}

				case 3: //Imprimir Orquestas
				{
					printf("\n\n\n");
					mostrarOrquestas(listadoOrquestas,Q_ORQUESTAS);

					system("PAUSE()");
					break;
				}

				case 4: //Alta Musico
				{
					if(altaMusico(listadoMusicos,Q_MUSICOS,idMusico,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS))
					{
						idMusico++;
					}
					else
					{
						printf("Se cancelo el alta del musico");
					}
					break;
				}
				case 5: //Modificacion Musico
				{
					modificarMusico(listadoMusicos,Q_MUSICOS,idMusico,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS);

					break;
				}
				case 6: //Eliminar Musico
				{
					bajaMusico(listadoMusicos,Q_MUSICOS,idMusico,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS);
					system("PAUSE()");

					break;
				}

				case 7: //Imprimir Musicos
				{
					printf("\n\n\n");
					mostrarMusicos(listadoMusicos,Q_MUSICOS,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS);
					system("PAUSE()");
					break;
				}
				case 8: //Alta Instrumento
				{
					if(altaInstrumento(listadoInstrumentos,Q_INSTRUMENTOS,idInstrumento,tiposInstrumento,Q_TIPOINSTRUMENTOS))
					{
						idInstrumento++;
					}
					else
					{
						printf("Se cancelo el alta del musico");
					}
					break;
				}

				case 9: //Imprimir Instrumentos
				{
					printf("\n\n\n");
					mostrarInstrumentos(listadoInstrumentos,Q_INSTRUMENTOS);
					system("PAUSE()");
					break;
				}
				case 10: //Imprimir Instrumentos
				{
					system("CLS()");
					ingresoInforme=subMenuInformes();
					switch (ingresoInforme)
					{
						case 1:
						{
							printf("\n\n\n");
							if(!(listarOrquestas(listadoOrquestas,Q_ORQUESTAS,listadoMusicos,Q_MUSICOS)))
							{
								system("CLS()");
								printf("No se encontraron orquestas con mas de 5 musicos\n");
							}
							system("PAUSE()");
							break;
						}
						case 2:
						{
							if(!(listarMusicosMas30(listadoMusicos,Q_MUSICOS,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS)))
							{
								system("CLS()");
								printf("No se encontraron musicos con mas de 30 anios\n");
							}
							system("PAUSE()");
							break;
						}

						case 3:
						{
							listarOrquestaLugar(listadoOrquestas,Q_ORQUESTAS);
							system("PAUSE()");
							break;
						}
						case 4:
						{

							if(!(orquestasCompletas(listadoMusicos,Q_MUSICOS,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS)))
							{
								system("CLS()");
								printf("No se encontraron orquestas completas\n");
							}

							system("PAUSE()");
							break;
						}
						case 5:
						{
							if(!(listarMusicos(listadoMusicos,Q_MUSICOS,listadoOrquestas,Q_ORQUESTAS,listadoInstrumentos,Q_INSTRUMENTOS)))
							{
								system("CLS()");
								printf("No se encontraron musicos para la orquesta ingresada\n");
							}
							system("PAUSE()");
							break;
						}
						case 6:
						{
							printf("\n\n");
							orquestasMasMusicos(listadoMusicos,Q_MUSICOS,listadoOrquestas,Q_ORQUESTAS);
							system("PAUSE()");
							break;
						}

					}
					break;
				}

			}

		}while(ingreso!=0);



system("PAUSE()");

return 0;
}


int menu()
{
	int opcion=-1;

	printf("Menu de opciones musicos\n\n");
	printf("1-Alta de Orquesta\n");
	printf("2-Baja de Orquesta\n");
	printf("3-Imprimir Orquestas\n");
	printf("4-Alta de Musico\n");
	printf("5-Modificar de Musico\n");
	printf("6-Baja Musico\n");
	printf("7-Imprimir Musicos\n");
	printf("8-Alta de Instrumentos\n");
	printf("9-Imprimir Instrumentos\n");
	printf("10-Informes\n");
	printf("0-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",0,10,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}



return opcion;
}

int subMenuInformes()
{
	int opcion=-1;

	printf("Menu de informes\n\n");
	printf("1-Listar las orquestas con más de 5 músicos\n");
	printf("2-Listar los músicos de más de 30 anios,\n");
	printf("3-Listar las orquestas de un lugar\n");
	printf("4-Listar las orquestas completas\n");
	printf("5-Listar todos los músicos de una orquesta determinada\n");
	printf("6-Imprimir la orquesta con más músicos\n");
	printf("7-Listar los músicos que toquen instrumentos de cuerdas\n");
	printf("8-Imprimir el promedio de músicos por orquesta\n");
	printf("0-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",0,8,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}



return opcion;
}

