/*
 * anb_f.h
 *
 *  Created on: 9 abr. 2020
 *      Author: aleja
 */

#ifndef ANB_F_H_
#define ANB_F_H_

int devuelveMax(int* pArray, int size, int* resultado);
int devuelveMin(int* pArray, int size, int* resultado);
int devuelvePromedio(int* pArray, int size, float* resultado);
int imprimirArrayInt(int* pArray,int size);
int buscaNumint(int* pArray, int size, int* pos);
int ordenaArray(int* pArray,int size, char sentido);

#endif /* ANB_F_H_ */
