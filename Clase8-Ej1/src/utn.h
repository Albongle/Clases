/*
 * utn.h
 *
 *  Created on: 10 abr. 2020
 *      Author: aleja
 */

#ifndef UTN_H_
#define UTN_H_
int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroConDecimales(float* pNumero, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);
int utn_getTexto(char* pIngreso, char* pMensaje, char* pMensajeError, int reintentos, int size);
int utn_getCaracter(char* pCaracter, char* pMensaje, char* pMensajeError,char* pRango, int reintentos);


#endif /* UTN_H_ */
