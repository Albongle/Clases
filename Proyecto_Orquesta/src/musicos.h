/*
 * musicos.h
 *
 *  Created on: 7 may. 2020
 *      Author: aleja
 */



#ifndef MUSICOS_H_
#define MUSICOS_H_
#include "instrumentos.h"
#include "orquestas.h"
typedef struct eMusicos{

	int idMusico;
	char nombre[50];
	char apellido [50];
	int edad;
	int idOrquesta;
	int idInstrumento;
	int isEmpty;
}eMusicos;

void iniArrayMusicos(eMusicos* pArray,int size,int valorInt);
int hardcodearMusicos(eMusicos* pArray, int size, int cantidad);
int altaMusico(eMusicos* pArrayMusico, int tamArrayMusico, int idMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta,eInstrumento* pArrayInstrumento, int tamArrayInstrumento);
int bajaMusico(eMusicos* pArrayMusico, int tamArrayMusico, int idMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta,eInstrumento* pArrayInstrumento,int tamArrayInstrumento);
int modificarMusico(eMusicos* pArrayMusico, int tamArrayMusico, int idMusico, eOrquesta* pArrayOrquesta, int tamArrayOrquesta, eInstrumento* pArrayInstrumento, int tamArrayInstrumento);
void mostrarMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquesta, int tamArrayOrquesta,eInstrumento* pArrayInstrumento,int tamArrayInstrumento);
void mostrarMusico(eMusicos pArrayMusicos,eOrquesta* pArrayOrquesta,int tamArrayOrquesta,eInstrumento* pArrayInstrumento,int tamArrayInstrumento);
void bajaMusicoPorIdOrquesta(eMusicos* pArrayMusico,int tamArrayMusico,int idOrquestaBaja);

int musicosMismaOrquesta(eMusicos* pArrayMusicos, int tamArrayMusicos, int idOrquesta);

#endif /* MUSICOS_H_ */
