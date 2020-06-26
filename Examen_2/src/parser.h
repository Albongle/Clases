/*
 * parser.h
 *
 *  Created on: 6 jun. 2020
 *      Author: aleja
 */

#include "LinkedList.h"
#ifndef PARSER_H_
#define PARSER_H_



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path FILE* es el puntero a la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int parser_VentasComoTexto(FILE* pFile , LinkedList* pArrayList);

/** \brief guarda los datos de los empleados en un archivo el archivo datadataCopy.csv (modo texto).
 *
 * \param path FILE* es el puntero a la referencia del archivo
 * \param pArrayListEmployee LinkedList*, es el listado que almacena las posiciones de memorias de los empleados
 * \return int
 *
 */
int guardarVentascomoTexto(FILE* path , LinkedList* pArrayListEmployee);



#endif /* PARSER_H_ */
