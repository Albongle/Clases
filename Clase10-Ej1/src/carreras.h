/*
 * carreras.h
 *
 *  Created on: 30 abr. 2020
 *      Author: aleja
 */

#ifndef CARRERAS_H_
#define CARRERAS_H_
#define CARR_ELEMENTOS 3
#define CARR_SIZE_CARACTERES 50

typedef struct eCarrera{

	int id;
	char descripcion[CARR_SIZE_CARACTERES];

}eCarrera;

#endif /* CARRERAS_H_ */


void mostrarCarreras(eCarrera* pArray,int size);
