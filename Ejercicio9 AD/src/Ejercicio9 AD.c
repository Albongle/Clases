/*
 ============================================================================
 Name        : Ejercicio9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int checkVocal(char car);


int main() {
system("CLS()");
setbuf(stdout, NULL);
int res;
int i;
char voc[5];
int qVoc[5];
char ingreso[20];






printf("Ingrese una palabra de hasta 20 caracteres");
scanf("%c", ingreso);


int cont=0;
while (ingreso[cont]!='\0')
{

	res=checkVocal(ingreso[cont]);

	if(res==1 && cont==0)
	{

	voc[cont]=ingreso[cont];
	qVoc[cont]=qVoc[cont]+res;

	}
	else if (res==1)
	{
		for(i=0; i<cont; i++)
		{
			if(ingreso[cont]==voc[i])
			{
					voc[i]=ingreso[i];
					qVoc[i]=qVoc[i]+res;

			}
		}

	}
	cont++;
}

system("PAUSE()");
}




int checkVocal(char car)
{
	int resultado=0;
	int i;



	for(i=97; i<118;i=i+4)
	{
		if(i>=105)
		{
			if(tolower(car)==i)
			{
				resultado++;
				i=i+2;
			}
		}
		else if (tolower(car)==i)
			{

				resultado++;
			}


	}


return resultado;
}


//printf("\ningreso %d letras 'A'", contA);



