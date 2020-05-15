/*
 ============================================================================
 Name        : Clase10-Ej1.c
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
#include "alumnos.h"
#include "carreras.h"
#include "informes.h"
#define CARR_ELEMENTOS 3
#define CARR_SIZE_CARACTERES 50
#define Q_ALUMNOS 10
#define A_SIZE_CARACTERES 50






int menu();
int subMenu();

int main(void) {

system("COLOR FD");

		setbuf(stdout, NULL);
		eAlumnos listadoAlumnos[Q_ALUMNOS];
		eCarrera carreras[]= {{1000, "TUP"},{1001, "TUSI"},{1002, "LIC"}}; //Hardcodeo carreras
		int ingreso;
		int ingreso_sub;
		int legajo=20000;
		iniArrayAlumnos(listadoAlumnos,Q_ALUMNOS,1); // inicializo array alumnos poniendo en isEmpty 1

		legajo=legajo+hardcodearAlumnos(listadoAlumnos,Q_ALUMNOS,5);




		do
		{

			system("CLS()");


			ingreso=menu();
			switch (ingreso)
			{
				case 1:
				{
					altaAlumno(listadoAlumnos, Q_ALUMNOS,legajo,carreras,CARR_ELEMENTOS);

					legajo++;

					break;
				}
				case 2:
				{
					bajaAlumno(listadoAlumnos,Q_ALUMNOS,legajo,carreras,CARR_ELEMENTOS);
					system("PAUSE()");
					break;
				}

				case 3:
				{
					modificarAlumno(listadoAlumnos,Q_ALUMNOS,legajo,carreras,CARR_ELEMENTOS);
					//bajaAlumno(listadoAlumnos,Q_ALUMNOS,legajo,carreras,CARR_ELEMENTOS);
					system("PAUSE()");
					break;
				}

				case 4:
				{
					mostrarAlumnos(listadoAlumnos, Q_ALUMNOS,carreras,CARR_ELEMENTOS);
					system("PAUSE()");
					break;
				}
				case 5:
				{

					ordenaAlumnos(listadoAlumnos,Q_ALUMNOS,'>');
					printf("\n\n");
					mostrarAlumnos(listadoAlumnos, Q_ALUMNOS,carreras,CARR_ELEMENTOS);
					system("PAUSE()");

				break;
				}

				case 6:
				{
					do
					{
						system("CLS()");
						ingreso_sub=subMenu();
						switch (ingreso_sub)
						{
							case 1:
									{

										mostrarAlumnosPorCarrera(listadoAlumnos,Q_ALUMNOS,carreras,CARR_ELEMENTOS);
										system("PAUSE()");
										break;
									}

						}


					}while(ingreso_sub!=2);

					break;
				}

				case 7:
				{
					printf("\n\n");
					mostrarCarreras(carreras,CARR_ELEMENTOS);
					system("PAUSE()");
					break;
				}
			}



		}while(ingreso!=8);



			system("PAUSE()");

return 0;
}



int menu()
{
	int opcion=0;

	printf("Menu de opciones\n\n");
	printf("1-Alta de Alumno\n");
	printf("2-Baja de Alumno\n");
	printf("3-Modificar Alumno\n");
	printf("4-Listar Alumnos\n");
	printf("5-Ordenar Alumno\n");
	printf("6-Informes\n");
	printf("7-Mostrar carreras\n");
	printf("8-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,8,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}



return opcion;
}


int subMenu()
{
	int opcion=0;

	printf("Menu de informes\n\n");
	printf("1-Mostrar alumnos de una carrera\n");
	printf("2-Salir\n");

	if(!(utn_getNumero(&opcion,"Elija un opcion: ","Error verifique los datos ingresados quedan %d intentos\n",1,2,3)))
	{
		printf("No se reconocio el ingreso, supero el maximo de posibilidades\n");
		system("PAUSE()");
	}



return opcion;
}


