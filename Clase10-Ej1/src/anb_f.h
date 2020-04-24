/*
 * anb_f.h
 *
 *  Created on: 9 abr. 2020
 *      Author: aleja
 */

#ifndef ANB_F_H_
#define ANB_F_H_
/***
 * brief devuelve el promedio de un array de enteros
 * param pArray es el array sobre el cual se va a realizar el promedio de los numeros
 * param size es el tamaño del array
 * *resultado es la variable donde se va a devolver el promedio de los numeros de array
 * return 1 en caso exitoso
 */
int devuelvePromedio(int* pArray, int size, float* resultado);

 /***
 * brief imprime los numeros enteros del array
 * param pArray es el array sobre el cual se va a realizar la impresion de los numeros
 * param size es el tamaño del array
 * return 1 en caso exitoso
 */
int imprimirArrayInt(int* pArray,int size);
/***
 * brief imprime los numeros flotantes del array
 * param pArray es el array sobre el cual se va a realizar la impresion de los numeros
 * param size es el tamaño del array
 * return 1 en caso exitoso
 */
int imprimirArrayFloat(float* pArray,int size);
/***
 * brief imprime el string del array
 * param pArray es el array sobre el cual se va a realizar la impresion de los datos
 * param size es el tamaño del array
 * return 1 en caso exitoso
 */
int imprimirArrayString(char pArray[][50],int size);
/***
 * brief solicita un numero entero y lo busca dentto del array
 * param pArray es el array sobre el cual se va a realizar la busqueda de los datos
 * param size es el tamaño del array
 * *pos es la posicion donde se encontro el numero buscado
 * return 1 en caso exitoso
 */
int buscaNumint(int* pArray, int size, int* pos);
/***
 * brief Ordena el array de numeros enteros
 * param pArray es el array sobre el cual se va a realizar el ordenamiento
 * param size es el tamaño del array
 * param sentido, indica la forma que se va a ordenar > o <
 * return 1 en caso exitoso
 */
int ordenaArray(int* pArray,int size, char sentido);
/***
 * brief Ordena el array de numeros strings
 * param pArray es el array sobre el cual se va a realizar el ordenamiento
 * param size es el tamaño del array
 * param sentido, indica la forma que se va a ordenar > o <
 * return 1 en caso exitoso
 */
int ordenaArrayString(char pArray[][50],int size, char sentido);
/***
 * brief devuelve el numero maximo y minimo dentro de un array de enteros
 * param pArray es el array sobre el cual se va a realizar la busqueda de max y min
 * param size es el tamaño del array
 * *max es el numero maximo encontrado *min es el numero minimo encontrado
 * return 1 en caso exitoso
 */
int devuelveMaxAndMin(int* pArray, int size, int* max, int* min);
/***
 * brief devuelve el numero maximo y minimo dentro de un array de flotantes
 * param pArray es el array sobre el cual se va a realizar la busqueda de max y min
 * param size es el tamaño del array
 * *max es el numero maximo encontrado *min es el numero minimo encontrado
 * return 1 en caso exitoso
 */
int devuelveMaxAndMinFloat(float* pArray, int size, float* max, float* min);
/**
 * brief inicializa un array de numeros enteros
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array
 * return 1 en caso exitoso
 */
int iniArrayInt(int* pArray, int size, int valor);
/**
 * brief inicializa un array de strings
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array, ejemplo '\0'
 * return 1 en caso exitoso
 */
int iniArrayString(char pArray[][50], int size, char valor);
/**
 * brief inicializa un array de numeros flotantes
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array
 * return 1 en caso exitoso
 */
int iniArrayFloat(float* pArray, int size, float valor);
/**
 * brief realiza la carga de numeros enteros dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param size es el tamaño del array
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */
int getArrayInt(int* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos);
/**
 * brief inicializa un array de char
 * param pArray es el array sobre el cual se va a realizar la inicializacion
 * param size es el tamaño del array
 * param valor, es el valor a cargar en todas las posiciones del array, ejemplo '\0'
 * return 1 en caso exitoso
 */
int iniArrayChar(char* pArray,int size,char valor);
/**
 * brief realiza la carga de numeros flotantes dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param size es el tamaño del array
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param minimo es donde se debera establecer el numero minimo permitido a ingresar
 * param maximo es donde se debera establecer el numero maximo permitido a ingresar
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */

int getArrayFloat(float* pArray, int size,char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos, int* pos);
/**
 * brief realiza la carga de cadenas de textos dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param sizeY es el tamaño del array
 * param sizeX es el tamaño que puede tener cada string
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */
int getArrayString(char pArray[][50],int sizeY,int sizeX,char* pMensaje, char* pMensajeError, int reintentos, int* pos);
/**
 * brief realiza la carga de caracteres dentro del un array de manera aleatoria
 * param pArray es el array sobre el cual se va a realizar la carga de datos
 * param size es el tamaño del array
 * param pMensaje es el mensaje que se va a mostrar antes de solicitar el ingreso
 * param pMensajeError es el mensaje de error que se va a informar en caso que el ingreso no cumpla las condiciones
 * param pCaractes son los caracteres que se le va a permitir al usuarios ingresar. la ultima posicion debe ser '\0' para indicar el final de la cadena
 * param reintentos es la cantidad de reintentos que se le va a birndar al usuario en caso de error
 * *pos devolvera la posicion hasta la cual se cargo el array en caso que el usuario no quiera continuar con el ingreso de datos
 * return 1 en caso exitoso
 */
int getArrayChar(char* pArray,int size,char* pMensaje, char* pMensajeError, char* pCaracteres, int reintentos, int* pos);
#endif /* ANB_F_H_ */
