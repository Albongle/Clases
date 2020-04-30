/*
 * alumnos.h
 *
 *  Created on: 29 abr. 2020
 *      Author: aleja
 */

#ifndef ALUMNOS_H_
#define ALUMNOS_H_
#define A_ELEMENTOS 5
#define A_SIZE_CARACTERES 50

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


int getSetDeDatos(eAlumnos* datosAux, int sizeArray, int* pos);
void mostrarDatos(eAlumnos* datosAux, int size);
int buscaLegajo(eAlumnos* datosAux,int valorBuscado, int size, int* pos);
int iniArrayAlumnos(eAlumnos* datosAux,int size,int valorInt, char valorStr);
int ordenaNombre(eAlumnos* datosAux,int size, char sentido);


#endif /* ALUMNOS_H_ */
