/*
 * anb_f.h
 *
 *  Created on: 9 abr. 2020
 *      Author: aleja
 */

#ifndef ANB_F_H_
#define ANB_F_H_

int devuelvePromedio(int* pArray, int size, float* resultado);
int imprimirArrayInt(int* pArray,int size);
int imprimirArrayFloat(float* pArray,int size);
int imprimirArrayString(char pArray[][128],int size);
int buscaNumint(int* pArray, int size, int* pos);
int ordenaArray(int* pArray,int size, char sentido);
int devuelveMaxAndMin(int* pArray, int size, int* max, int* min);
int devuelveMaxAndMinFloat(float* pArray, int size, float* max, float* min);
int iniArrayInt(int* pArray, int size, int valor);
int getArrayInt(int* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos);
int getArrayFloat(float* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos);
int getArrayString(char pArray[][128],int sizeY,int sizeX,char* pMensaje, char* pMensajeError, int reintentos, int* pos);
#endif /* ANB_F_H_ */
