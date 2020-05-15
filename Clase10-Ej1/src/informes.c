/*
 * informes.c
 *
 *  Created on: 3 may. 2020
 *      Author: aleja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "alumnos.h"
#include "carreras.h"
#include "utn.h"

void cargarAlumnPorCarrera(eAlumnos* pArrayAlumno, int sizeArrayAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera, int idCarrera);
int mostrarAlumnosPorCarrera(eAlumnos* pArrayAlumno, int sizeArrayAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera)
{
	int ret=0;
	char nombreCarrera[20];
	int idCarrera;


	mostrarCarreras(pArrayCarrera,sizeArrayCarrera);
	fflush(stdin);
	if(utn_getTexto(nombreCarrera,"Ingrese la descripcion de la carrera a buscar \n","Error verifique los datos ingresados quedan %d intentos\n",3,20))
	{
		if(cargarIdCarrera(pArrayCarrera,nombreCarrera,sizeArrayCarrera,&idCarrera))
		{
			cargarAlumnPorCarrera(pArrayAlumno,sizeArrayAlumno,pArrayCarrera,sizeArrayCarrera,idCarrera);

		}
		else
		{
			printf("\n\nNo se verifican datos para el parametro ingresado\n");
		}

	}


	return ret;
}


void cargarAlumnPorCarrera(eAlumnos* pArrayAlumno, int sizeArrayAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera, int idCarrera)
{
	int i;
	printf("Legajo\tNombre\tApellido\tEdad\tSexo\tNota_1\tNota_2\tPromedio_Notas\tFecha de Ingreso\tCarrera\n");
	for(i=0;i<sizeArrayAlumno;i++)
	{
		if(pArrayAlumno[i].idCarrera==idCarrera && pArrayAlumno[i].isEmpty==0)
		{
			mostrarAlumno(pArrayAlumno[i],pArrayCarrera,sizeArrayCarrera);
		}

	}

}
