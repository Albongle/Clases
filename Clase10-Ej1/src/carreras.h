/*
 * carreras.h
 *
 *  Created on: 30 abr. 2020
 *      Author: aleja
 */



#ifndef CARRERAS_H_
#define CARRERAS_H_
typedef struct eCarrera{

	int id;
	char descripcion[10];

}eCarrera;

void mostrarCarreras(eCarrera* pArray,int size);
void mostrarCarrera(eCarrera pArray);
int buscarCarrera(eCarrera* pArray,int valorBuscado, int size, char* descrCarrera);
int cargarIdCarrera(eCarrera* pArray,char* valorBuscado, int size, int* idCarrera);

#endif /* CARRERAS_H_ */



