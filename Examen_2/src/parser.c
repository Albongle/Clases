#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ventas.h"


int parser_VentasComoTexto(FILE* pFile , LinkedList* pArrayList)
{
	int ret=0;
	char buffer[5][50];
	int cant=0;
	eVentas* pAuxVenta=NULL;

	if(pFile!=NULL && pArrayList!=NULL)
	{
			 fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
			 while(!feof(pFile))
			 {
				 cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
			     if(cant<6)
			     {
			    	 ret=0;
			    	 break;
			     }
			     else
			     {
			    	 if((pAuxVenta=eVentas_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5],"0"))!=NULL)
			    	 {
			    		 ll_add(pArrayList,pAuxVenta);
			    		 ret=1;
			    	 }
			    	 else
			    	 {
			    		 ret=-1;
			    		 break;
			    	 }
			     }
			 }
	}
    return ret;
}



int guardarVentascomoTexto(FILE* path,LinkedList* pArrayList)
{
	int ret=0;
	int tam;
	int i;
	char id_VentaStr[30];
	char nombre_Pelicula[128];
	char diaStr[30];
	char horarioStr[30];
	char sala[64];
	char q_EntradasStr[30];
	char montoStr[30];
	int flag=0;
	int cant;
	char* titulo="id_Venta,Nombre_Pelicula,dia,horario,sala,Cantidad_entradas,Monto\n";
	eVentas* ventasAux=NULL;

	if(path!=NULL &&  pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		if(tam>0)
		{
			ll_map(pArrayList,funcionCalculoMonto);
			fwrite(titulo,sizeof(char),strlen(titulo),path);
			for(i=0;i<tam;i++)
			{
				if((ventasAux=ll_get(pArrayList,i))!=NULL)
				{

					if(ventas_getDatos(ventasAux,id_VentaStr,nombre_Pelicula,diaStr,horarioStr,sala,q_EntradasStr,montoStr))
					{
						cant=fprintf(path,"%s,%s,%s,%s,%s,%s,%s\n",id_VentaStr,nombre_Pelicula,diaStr,horarioStr,sala,q_EntradasStr,montoStr);
						if(cant<7)
						{
							flag=1;
						}
					}
				}
			}
			if(flag>0)
			{
				ret=-1;
			}
			else
			{
				ret=1;
			}
		}
	}
	return ret;
}
