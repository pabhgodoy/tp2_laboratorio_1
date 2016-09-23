#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <string.h>
int menu()
{
	int opcion=0;
	
    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");
    scanf("%d",&opcion);
    
	while(ValidarRango(opcion,1,5))
	{
		printf("ERROR,ingrese una opcion de 1 a 5\n");
		scanf("%d",&opcion);
	}	
	
	return opcion;
}
int ValidarRango(int x,int min,int max)
{
	if(x<min || x>max)
		return 1;
	return 0;
}
int ValidarCadena(char cad[],int TAM)
{
	if(strlen(cad)>TAM)
		return 1;
	return 0;
}
//************************************************//
int BuscarLibre(Persona per[],int TAM)
{
	int i,indice=-1;
	for(i=0;i<TAM;i++)
	{
		if(per[i].dni==0)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
/*void inicializar(Persona per[],int TAM)
{
	int i;
	for(i=0;i<TAM;i++)
	{
		per[i].dni=0;
	}
}*/
int BuscarDNI(Persona per[],int TAM,int DNI)
{
	int i,indice=-1;
	for(i=0;i<TAM;i++)
	{
		if(per[i].dni==DNI)
		{
			indice=i;
			break;
		}
	}
	return indice;	
}
