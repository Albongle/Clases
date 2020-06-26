/*
 ============================================================================
 Name        : ID_Autoincremento.c
 Author      : Alejandro Bongioanni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
static int generarId(void);

int main(void) {
	int ingreso;
	int id;
	system("COLOR E");
	setbuf(stdout, NULL);
	do
	{
		id=generarId();
		printf("el id es %d\n",id);
		printf("Desea seguir autoincrementando?\n");
		scanf("%d",&ingreso);
	}while(ingreso!=0);

}


static int generarId(void)
{
    static int id=0;
    return id++;
}
