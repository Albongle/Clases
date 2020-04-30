/*
 * alumnos.h
 *
 *  Created on: 29 abr. 2020
 *      Author: aleja
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_
#define ELEMENTOS 5


#define SIZE_CARACTERES 50
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
	char nombre[SIZE_CARACTERES];
	char apellido[SIZE_CARACTERES];
	int edad;
	char sexo;
	eNotas evaluacion;
	eFecha fechaIngreso;
	int idCarrera;
	int isEmpty;
}eAlumnos;


int getSetDeDatos(eAlumnos* datosAux, int sizeArray, int* pos);
void mostrarDatos(eAlumnos* datosAux, int size);
int buscaLegajo(eAlumnos* datosAux,int valorBuscado, int size, int* pos);
int iniArrayLeg(eAlumnos* datosAux,int size,int valor);
int ordenaNombre(eAlumnos* datosAux,int size, char sentido);


#endif /* ALUMNOS_H_ */
