/*
 * ventas.c
 *
 *  Created on: 17 jun. 2020
 *      Author: aleja
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ventas.h"


/*typedef struct eDia{
	int idDia;
	char diaStr[20];
}eDia;

typedef struct eVentas{

	int id_Venta;
	char nombre_Pelicula[128];
	eDia dia;
	char horario [30];
	char sala [64];
	int q_Entradas;
	float monto;
}eVentas;*/
static int selectDia(int dia, char* diaStr);


eVentas* eVentas_new()
{
	eVentas* this=(eVentas*) malloc(sizeof(eVentas));
	if(this!=NULL)
	{
		eVentas_setId(this,0);
		eVentas_setFecha(this,0);
		eVentas_setNombrePelicula(this,"");
		eVentas_setHorario(this,"");
		eVentas_setSala(this,0);
		eVentas_setEntradas(this,0);
		eVentas_setMonto(this,0);

	}
	return this;
}

eVentas* eVentas_newParametros(char* id_VentaStr,char* nombre_Pelicula,char* diaStr, char* horarioStr, char* sala, char* q_EntradasStr, char* montoStr)
{
	eVentas* this=eVentas_new();

		if(this!=NULL)
		{
			eVentas_setId(this,atoi(id_VentaStr));
			eVentas_setFecha(this,atoi(diaStr));
			eVentas_setNombrePelicula(this,nombre_Pelicula);
			eVentas_setHorario(this,horarioStr);
			eVentas_setSala(this,atoi(sala));
			eVentas_setEntradas(this,atoi(q_EntradasStr));
			eVentas_setMonto(this,atof(montoStr));
		}
		return this;

}

int eVentas_setId(eVentas* this,int id)
{
	int ret=0;
	static int maxId=0;
	if (this!=NULL)
	{
		if(id<0)
		{
			maxId++;
			this->id_Venta=maxId;
		}
		else
		{
			if(id>maxId)
			{
				maxId=id;
			}
			this->id_Venta=id;
		}
		ret=1;
	}
	return ret;
}

int eVentas_getId(eVentas* this,int* id)
{
	int ret=0;
		if (this!=NULL && id !=NULL)
		{
			*id=this->id_Venta;
			ret=1;
		}
		return ret;

}

int eVentas_setFecha(eVentas* this,int dia)
{
	int ret=0;
	char diaStr[20];

	if (this!=NULL && dia>=0 && dia <7)
	{
		selectDia(dia,diaStr);
		this->dia.idDia=dia;
		strcpy(this->dia.diaStr,diaStr);
		ret=1;
	}
	return ret;
}

static int selectDia(int dia, char* diaStr)
{
	int ret=0;

	if (dia>=0 && dia <7)
	{
		switch(dia)
		{
			case 0: {strcpy(diaStr,"Domingo");break;}
			case 1: {strcpy(diaStr,"Lunes");break;}
			case 2: {strcpy(diaStr,"Martes");break;}
			case 3: {strcpy(diaStr,"Miercoles");break;}
			case 4: {strcpy(diaStr,"Jueves");break;}
			case 5: {strcpy(diaStr,"Viernes");break;}
			case 6: {strcpy(diaStr,"Sabado");break;}
		}
		ret=1;
	}
	return ret;
}

int eVentas_getFecha(eVentas* this,int* dia)
{
	int ret=0;
		if (this!=NULL && dia !=NULL)
		{
			*dia=this->dia.idDia;
			ret=1;
		}
		return ret;

}

int eVentas_getDiaChar(eVentas* this,char* diaStr)
{
	int ret=0;
		if (this!=NULL && diaStr!=NULL)
		{
			strcpy(diaStr,this->dia.diaStr);
			ret=1;
		}
		return ret;

}

int eVentas_setNombrePelicula(eVentas* this,char* nombre)
{
	int ret=0;

	if (this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre_Pelicula,nombre);
		ret=1;
	}
	return ret;
}

int eVentas_getNombrePelicula(eVentas* this,char* nombre)
{
	int ret=0;

	if (this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre_Pelicula);
		ret=1;
	}
	return ret;
}


int eVentas_setHorario(eVentas* this,char* horario)
{
	int ret=0;

	if (this!=NULL && horario!=NULL)
	{
		strcpy(this->horario,horario);
		ret=1;
	}
	return ret;
}

int eVentas_getHorario(eVentas* this,char* horario)
{
	int ret=0;

	if (this!=NULL && horario!=NULL)
	{
		strcpy(horario,this->horario);
		ret=1;
	}
	return ret;
}

int eVentas_setSala(eVentas* this,int sala)
{
	int ret=0;

	if (this!=NULL && sala>=0)
	{
		this->sala=sala;
		ret=1;
	}
	return ret;
}

int eVentas_getSala(eVentas* this,int* sala)
{
	int ret=0;

	if (this!=NULL && sala!=NULL)
	{
		*sala=this->sala;
		ret=1;
	}
	return ret;
}


int eVentas_setEntradas(eVentas* this,int qEntradas)
{
	int ret=0;

	if (this!=NULL && qEntradas>=0)
	{
		this->q_Entradas=qEntradas;
		ret=1;
	}
	return ret;
}

int eVentas_getEntradas(eVentas* this,int* qEntradas)
{
	int ret=0;

	if (this!=NULL && qEntradas!=NULL)
	{
		*qEntradas=this->q_Entradas;
		ret=1;
	}
	return ret;
}

int eVentas_setMonto(eVentas* this,float monto)
{
	int ret=0;

	if (this!=NULL && monto>=0)
	{
		this->monto=monto;
		ret=1;
	}
	return ret;
}

int eVentas_getMonto(eVentas* this,float* monto)
{
	int ret=0;

	if (this!=NULL && monto!=NULL)
	{
		*monto=this->monto;
		ret=1;
	}
	return ret;
}

int ventas_Print(eVentas* this)
{
	int ret=0;
	int id;
	char diaStr[30];
	char nombre_Pelicula[128];
	char horarioStr [30];
	int sala;
	int q_Entradas;
	if (this!=NULL)
	{
		if(eVentas_getId(this,&id))
		{
			if(eVentas_getDiaChar(this,diaStr))
			{
				if(eVentas_getNombrePelicula(this,nombre_Pelicula))
				{
					if(eVentas_getHorario(this,horarioStr))
					{
						if(eVentas_getSala(this,&sala))
						{
							if(eVentas_getEntradas(this,&q_Entradas))
							{

								printf("%d\t%s\t%-15.15s\t\t%s\t%d\t%d\n",id,diaStr,nombre_Pelicula,horarioStr,sala,q_Entradas);
							}
						}
						ret=1;
					}
				}
			}
		}
	}

	return ret;
}


int ventas_getDatos(eVentas* this,char* id_VentaStr,char* nombre_Pelicula,char* diaStr, char* horarioStr, char* sala, char* q_EntradasStr, char* montoStr)
{
	int ret=0;

	if (this!=NULL && id_VentaStr!=NULL && nombre_Pelicula!=NULL && diaStr!=NULL && horarioStr!=NULL && sala!=NULL && q_EntradasStr!=NULL && montoStr!=NULL)
	{
		sprintf(id_VentaStr,"%d",this->id_Venta);
		strcpy(nombre_Pelicula,this->nombre_Pelicula);
		sprintf(diaStr,"%d",this->dia.idDia);
		strcpy(horarioStr,this->horario);
		sprintf(sala,"%d",this->sala);
		sprintf(q_EntradasStr,"%d",this->q_Entradas);
		sprintf(montoStr,"%.2f",this->monto);
		ret=1;
	}
return ret;
}

void funcionCalculoMonto(void* this)
{
	int idDia;
	int qEntradas;
	float precio;
	int descuento=0;
	int total;
	float monto;


	if(this!=NULL)
	{
		this=(eVentas*)this;
		eVentas_getId(this,&idDia);
		eVentas_getEntradas(this,&qEntradas);
		 switch(idDia)
		 {

		 case 1:
		 case 2:
		 case 3:
		 	 {
		 		 precio=240;
		 		 break;
		 	 }
		 default:
		 	 {
		 		precio=350;
		 	 }
		 }
		 if(qEntradas>3)
		 {
			 descuento=10;
		 }
		 total=qEntradas*precio;
		 descuento=total*descuento/100;
		 monto=total-descuento;
		eVentas_setMonto(this,monto);
	}
}
