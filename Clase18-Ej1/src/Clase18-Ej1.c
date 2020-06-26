/*
 ============================================================================
 Name        : Clase18-Ej1.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


typedef struct{
    int dia;
    int mes;
    int anio;
}EFecha;

typedef struct{
    long int dni;
    char nombre[31];
    EFecha fechaNac;
}EPersona;

int main()
{
    EPersona per, *ptrPer, pers[2], *ptrPers;
    int i;

    ptrPer = &per;
   ptrPers = pers;

   printf("\n\nESTRUCTURA SIMPLE:");

    printf("DNI: ");
    scanf("%ld", &per.dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", &per.nombre);

    printf("FECHA NACIMIENTO\n");

   printf("\nDIA: ");
    scanf("%d", &per.fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &per.fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &per.fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", per.nombre, per.dni, per.fechaNac.dia, per.fechaNac.mes, per.fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA OPERADOR FLECHA:");

    printf("DNI: ");
    scanf("%ld", &ptrPer->dni);
    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", ptrPer->nombre);

    printf("FECHA NACIMIENTO\n");
    printf("\nDIA: ");
    scanf("%d", &ptrPer->fechaNac.dia);
    printf("\nMES: ");
    scanf("%d", &ptrPer->fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &ptrPer->fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", ptrPer->nombre, ptrPer->dni, ptrPer->fechaNac.dia, ptrPer->fechaNac.mes, ptrPer->fechaNac.anio);


    printf("\n\nPUNTERO A ESTRUCTURA NOTACION PUNTERO:");

    printf("DNI: ");
    scanf("%ld", &(*ptrPer).dni);

    printf("\nNOMBRE: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", (*ptrPer).nombre);

    printf("FECHA NACIMIENTO\n");

    printf("\nDIA: ");
    scanf("%d", &(*ptrPer).fechaNac.dia);

    printf("\nMES: ");
    scanf("%d", &(*ptrPer).fechaNac.mes);

    printf("\nANIO: ");
    scanf("%d", &(*ptrPer).fechaNac.anio);

    printf("%s - %ld - %d/%d/%d", (*ptrPer).nombre, (*ptrPer).dni, (*ptrPer).fechaNac.dia, (*ptrPer).fechaNac.mes, (*ptrPer).fechaNac.anio);

    printf("\n\nPUNTERO A ARRAY DE ESTRUCTURA:");

    for(i=0; i<2; i++){
        printf("DNI: ");
        scanf("%ld", &(*(ptrPers+i)).dni);

        printf("\nNOMBRE: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", (*(ptrPers+i)).nombre);

        printf("FECHA NACIMIENTO\n");

        printf("\nDIA: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.dia);

        printf("\nMES: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.mes);

        printf("\nANIO: ");
        scanf("%d", &(*(ptrPers+i)).fechaNac.anio);
    }

    for(i=0; i<2; i++){
       /* printf("%s - %ld - %d/%d/%d", (*(ptrPers+i)).nombre, (*(ptrPers+i)).dni, (*(ptrPers+i)).fechaNac.dia, (*(ptrPers+i)).fechaNac.mes, (*(ptrPers+i)).fechaNac.anio); */

        printf("%s - %ld - %d/%d/%d", (ptrPers+i)->nombre, (ptrPers+i)->dni, (ptrPers+i)->fechaNac.dia, (ptrPers+i)->fechaNac.mes, (ptrPers+i)->fechaNac.anio);
    }

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
//Array de Estructura en memoria dinamica
//Constructor

int main()
{
    Person* personArray[3];
    int i;
    for(i = 0; i < 3; i++)
    {
        personArray[i] = person_new();//0,0);
    }
    for(i = 0; i < 3; i++)
    {
        person_setAge(personArray[i],i);
        person_setSomething(personArray[i],i);
    }
    for(i = 0; i < 3; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
        printf("\nSomething : %2d",person_getSomething(personArray[i]));
    }
    //Libero la memoria dinamica
    for(i = 0; i < 3; i++)
    {
        person_free(personArray[i]);
    }

   return 0;
}*/
