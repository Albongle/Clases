/*
 * ventas.h
 *
 *  Created on: 17 jun. 2020
 *      Author: aleja
 */

#ifndef VENTAS_H_
#define VENTAS_H_

typedef struct eDia{
	int idDia;
	char diaStr[20];
}eDia;

typedef struct eVentas{

	int id_Venta;
	char nombre_Pelicula[128];
	eDia dia;
	char horario [30];
	int sala;
	int q_Entradas;
	float monto;
}eVentas;

eVentas* eVentas_new();
eVentas* eVentas_newParametros(char* id_VentaStr,char* nombre_Pelicula,char* diaStr, char* horarioStr, char* sala, char* q_EntradasStr, char* montoStr);

int eVentas_setId(eVentas* this,int id);
int eVentas_getId(eVentas* this,int* id);
int eVentas_setFecha(eVentas* this,int dia);
int eVentas_getFecha(eVentas* this,int* dia);
int eVentas_getDiaChar(eVentas* this,char* diaStr);
int eVentas_setNombrePelicula(eVentas* this,char* nombre);
int eVentas_getNombrePelicula(eVentas* this,char* nombre);
int eVentas_setHorario(eVentas* this,char* horario);
int eVentas_getHorario(eVentas* this,char* horario);
int eVentas_setSala(eVentas* this,int sala);
int eVentas_getSala(eVentas* this,int* sala);
int eVentas_setEntradas(eVentas* this,int qEntradas);
int eVentas_getEntradas(eVentas* this,int* qEntradas);
int eVentas_setMonto(eVentas* this,float monto);
int eVentas_getMonto(eVentas* this,float* monto);

int ventas_Print(eVentas* this);
int ventas_getDatos(eVentas* this,char* id_VentaStr,char* nombre_Pelicula,char* diaStr, char* horarioStr, char* sala, char* q_EntradasStr, char* montoStr);
void funcionCalculoMonto(void* this);

#endif /* VENTAS_H_ */
