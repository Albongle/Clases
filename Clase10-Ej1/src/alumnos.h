/*
 * alumnos.h
 *
 *  Created on: 29 abr. 2020
 *      Author: aleja
 */



#ifndef ALUMNOS_H_
#define ALUMNOS_H_
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
	char nombre[50];
	char apellido[50];
	int edad;
	char sexo;
	eNotas evaluacion;
	eFecha fechaIngreso;
	int idCarrera;
	int isEmpty;
}eAlumnos;

int buscaIndice(eAlumnos* pArray, int size);
int ordenaAlumnos(eAlumnos* pArray,int size, char sentido);
int hardcodearAlumnos(eAlumnos* pArray, int size, int cantidad);
void iniArrayAlumnos(eAlumnos* pArray,int size,int valorInt);
int altaAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera);
int bajaAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera);
int modificarAlumno(eAlumnos* pArrayAlumno, int sizeArrayAlumno, int legajo, eCarrera* pArrayCarrera, int sizeArrayCarrera);
void mostrarAlumno(eAlumnos pArrayAlumno,eCarrera* pArrayCarrera,int sizeArrayCarrera);
void mostrarAlumnos(eAlumnos* pArrayAlumno, int sizeArrayAlumno, eCarrera* pArrayCarrera, int sizeArrayCarrera);


#endif /* ALUMNOS_H_ */
