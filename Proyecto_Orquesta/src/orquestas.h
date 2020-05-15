/*
 * orquestas.h
 *
 *  Created on: 7 may. 2020
 *      Author: aleja
 */

#ifndef ORQUESTAS_H_
#define ORQUESTAS_H_
typedef struct eTipoOrquesta{

	int idTipo;
	char nombre[50];
	int isEmpty;

}eTipoOrquesta;

typedef struct eOrquesta{

	int idOrquesta;
	char nombre[50];
	char lugar[50];
	eTipoOrquesta tipo; // anidar con tipo de orquesta
	int isEmpty;
}eOrquesta;


void iniArrayOrquestas(eOrquesta* pArray,int size,int valorInt);
int hardcodearOrquestas(eOrquesta* pArray, int size, int cantidad);
int altaOrquesta(eOrquesta* pArrayOrquesta,int tamArrayOrquesta, int idOrquesta,eTipoOrquesta* pArrayTipoOrquesta,int tamArrayTipoOrquesta);
int bajaOrquesta(eOrquesta* pArrayOrquesta, int tamArrayOrquesta,int *idOrquestaBaja);
void mostrarOrquestas(eOrquesta* pArrayOrquestas, int tamArrayOrquesta);
void mostrarOrquesta(eOrquesta pArrayOrquestas);
int buscarNombreTipoOrquesta_IDOrquesta(eOrquesta* pArray,int valorBuscado, int size, char* descrTipoOrquesta); //Llamo desde musicos para devoler desvripcion de Orquesta
int buscarNombreOrquesta_IDOrquesta(eOrquesta* pArray,int valorBuscado, int size, char* descrOrquesta);

#endif /* ORQUESTAS_H_ */
