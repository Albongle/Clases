/*
 * informes.h
 *
 *  Created on: 10 may. 2020
 *      Author: aleja
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "musicos.h"
#include "orquestas.h"
#include "instrumentos.h"


int listarOrquestas(eOrquesta* pArrayOrquestas, int tamArrayOrquestas, eMusicos* pArrayMusicos, int tamArrayMusicos);
int listarMusicosMas30(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas, int tamArrayOrquestas, eInstrumento* pArrayInstrumento, int tamArrayInstrumento);
int listarOrquestaLugar(eOrquesta* pArrayOrquestas, int tamArrayOrquestas);
int orquestasCompletas(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas, int tamArrayOrquestas, eInstrumento* pArrayInstrumentos, int tamArrayInstrumentos);
int listarMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas, int tamArrayOrquestas,eInstrumento* pArrayInstrumentos,int tamArrayInstrumentos);
int orquestasMasMusicos(eMusicos* pArrayMusicos, int tamArrayMusicos, eOrquesta* pArrayOrquestas,int tamArrayOrquestas);
#endif /* INFORMES_H_ */
