/*
 ============================================================================
 Name        : Binario.c
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
#define VALOR 8
int iniArrayInt(int pArray[][4],int size,int valor);

int main(void)
{
setbuf(stdout, NULL);
int c;
int f=0;
int resto;
int num=0;
int resultado;
int binario[8][4];
int suma=0;

iniArrayInt(binario,VALOR,0);


for(f=0; f<8 ;f++)
{
num=f;
c=3;
resultado=num/2;
resto=num%2;
binario[f][c]=resto;

	while(resultado>0 && c>0)
	{
		c--;
		resto=resultado%2;
		resultado=resultado/2;
		binario[f][c]=resto;
	}

}


for(f=0; f<8; f++)

	{
	suma=0;
		for (c=0; c<4; c++)
		{
		suma=binario[f][c]+suma;
		}

		if(suma==1)
		{
			printf("\nLa posicion %d",f);
		}

	}





	/*for(f=0; f<8; f++)

	{
		for (c=0; c<4; c++)
		{
		printf("\nla posicion [%d][%d] tiene el valor %d", f,c,binario[f][c]);
		}

	}*/


	return 0;
}


int iniArrayInt(int pArray[][4],int size,int valor)
{
	int i;
	int j;
	int ret=0;

	if(pArray!=NULL && size>0)
	{
		for(i = 0; i <size; i++)
		{
			for (j=0; j<4; j++)
			{
			pArray[i][j]=valor;
			}
		}
	ret=1;
	}
return ret;

system("PAUSE()");
}
