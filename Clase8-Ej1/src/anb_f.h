/*
 * anb_f.h
 *
 *  Created on: 9 abr. 2020
 *      Author: aleja
 */

#ifndef ANB_F_H_
#define ANB_F_H_
/***
 * Devuelve el promedio de un array de enteros
 * el resultado es un numero float
 * recibe el array y el tamaño de este
 */
int devuelvePromedio(int* pArray, int size, float* resultado);
/**
 * Imprime un array de numeros enteros
 * recibe el array y el tamaño de este
 */
int imprimirArrayInt(int* pArray,int size);
/**
 * Imprime un array de numeros float
 * recibe el array y el tamaño de este
 */
int imprimirArrayFloat(float* pArray,int size);
/**
 * Imprime un array cadena de texto
 * recibe el array y el tamaño de este
 */
int imprimirArrayString(char pArray[][50],int size);
/**
 * Busca un numero entero dentro del array
 * recibe el array y el tamaño de este
 * devuelve por puntero la posicion donde se encontro este
 */
int buscaNumint(int* pArray, int size, int* pos);
/**
 * Ordena un array de enteros
 * recibe el array, el tamaño y el sentido a ordenar
 */
int ordenaArray(int* pArray,int size, char sentido);
/**
 * Ordena un array de string
 * recibe el array, el tamaño y el sentido a ordenar
 */
int ordenaArrayString(char pArray[][50],int size, char sentido);
/**
 * devuelve el maximo y el minimo de un array de enteros
 * recibe el array y el tamaño de este devuelve por puntero el max y el min
 */
int devuelveMaxAndMin(int* pArray, int size, int* max, int* min);
/**
 * devuelve el maximo y el minimo de un array de float
 * recibe el array y el tamaño de este devuelve por puntero el max y el min
 */
int devuelveMaxAndMinFloat(float* pArray, int size, float* max, float* min);
/**
 * inicializa un array de enteros
 * recibe el array, el tamaño y el valor a cargar en todas las posiciones
 */
int iniArrayInt(int* pArray, int size, int valor);
/**
 * inicializa un array de texto
 * recibe el array, el tamaño y el caracter a cargar en todas las posiciones
 */
int iniArrayString(char pArray[][50], int size, char valor);
/**
 * inicializa un array de float
 * recibe el array, el tamaño y el valor a cargar en todas las posiciones
 */
int iniArrayFloat(float* pArray, int size, float valor);
/**
 * Realiza la carga de datos en un array de enteros con opcion a desistir
 * recibe el array, tamaño de este, mensaje a imprimir antes de la carga
 * mensaje de error en caso de ingresar un valor erroneo, rango de numeros admitidos
 * Q de reitentos en caso de error. devuelve por puntero la ultima posicion hasta la cual se cargo datos
 *
 */
int getArrayInt(int* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos);
/**
 * Realiza la carga de datos en un array de float con opcion a desistir
 * recibe el array, tamaño de este, mensaje a imprimir antes de la carga
 * mensaje de error en caso de ingresar un valor erroneo, rango de numeros admitidos
 * Q de reitentos en caso de error. devuelve por puntero la ultima posicion hasta la cual se cargo datos
 *
 */

int getArrayFloat(float* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos);
/**
 * Realiza la carga de datos en un array de string con opcion a desistir
 * recibe el array, tamaño de este (sixeY) y Q de caracteres permitidos (sizeX), mensaje a imprimir antes de la carga
 * mensaje de error en caso de ingresar un valor erroneo
 * Q de reitentos en caso de error. devuelve por puntero la ultima posicion hasta la cual se cargo datos
 *
 */
int getArrayString(char pArray[][50],int sizeY,int sizeX,char* pMensaje, char* pMensajeError, int reintentos, int* pos);
/**
 * Realiza la carga de datos en un array de caracteres con opcion a desistir
 * recibe el array, tamaño de este , mensaje a imprimir antes de la carga
 * mensaje de error en caso de ingresar un valor erroneo, caracteres permitidos en el ingreso y la cantidad de estos
 * la cual debe ser uno mas ya que se debe evaluar el fin de la cadena '\0'
 * Q de reitentos en caso de error. devuelve por puntero la ultima posicion hasta la cual se cargo datos
 *
 */
int getArrayChar(char* pArray,int size,char* pMensaje, char* pMensajeError, char* pCaracteres,int qCaracteres, int reintentos, int* pos);
#endif /* ANB_F_H_ */
