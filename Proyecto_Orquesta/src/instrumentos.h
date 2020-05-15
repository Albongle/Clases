/*
 * instrumentos.h
 *
 *  Created on: 7 may. 2020
 *      Author: aleja
 */


#ifndef INSTRUMENTOS_H_
#define INSTRUMENTOS_H_

typedef struct eTipoInstrumento{

	int idTipo;
	char nombre[50];
	int isEmpty;

}eTipoInstrumento;

typedef struct eInstrumento{

	int idInstrumento;
	char nombre[50];
	eTipoInstrumento tipo; // anida rcon tipo de instrumento
	int isEmpty;

}eInstrumento;

void iniArrayInstrumentos(eInstrumento* pArray,int size,int valorInt);
int hardcodearInstrumentos(eInstrumento* pArray, int size, int cantidad);
int altaInstrumento(eInstrumento* pArrayInstrumento,int tamArrayInstrumento, int idInstrumento,eTipoInstrumento* pArrayTipoInstrumento,int tamArrayTipoInstrumento);
void mostrarInstrumentos(eInstrumento* pArrayInstrumentos, int tamArrayInstrumento);
int buscarNombreInstrumento_IDInstrumento(eInstrumento* pArray,int valorBuscado, int size, char* descrInstrumento);
int buscarNombreTipoInstrumento_IDInstrumento(eInstrumento* pArray,int valorBuscado, int size, char* descrTipoInstrumento);//Llamo desde musicos para devoler desvripcion de Instrumento
int buscarIDTipoInstrumento_IDInstrumento(eInstrumento* pArray,int valorBuscado, int size, int* idTipo);//Llamo desde informes para devoler ID de Instrumento



#endif /* INSTRUMENTOS_H_ */
