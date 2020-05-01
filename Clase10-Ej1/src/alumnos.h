/*
 * alumnos.h
 *
 *  Created on: 29 abr. 2020
 *      Author: aleja
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_
#define Q_ALUMNOS 10
#define A_SIZE_CARACTERES 50
#include "carreras.h"

typedef struct eFecha{

	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct eNotas{

	float nota1;
	float nota2;
	float promNotas;
}eNotas;



typedef struct eAlumnos{

	int legajo;
	char nombre[A_SIZE_CARACTERES];
	char apellido[A_SIZE_CARACTERES];
	int edad;
	char sexo;
	eNotas evaluacion;
	eFecha fechaIngreso;
	int idCarrera;
	int isEmpty;
}eAlumnos;


int getSetDeDatos(eAlumnos* pArray, int sizeArray, int* pos);
void mostrarAlumnos(eAlumnos* pArray, int size);
int buscaIndice(eAlumnos* pArray, int size);
void iniArrayAlumnos(eAlumnos* pArray,int size,int valorInt);
int ordenaAlumnos(eAlumnos* pArray,int size, char sentido);
int hardcodearAlumnos(eAlumnos* pArray, int size, int cantidad);
int altaAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera);
int bajaAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera);


#endif /* ALUMNOS_H_ */
