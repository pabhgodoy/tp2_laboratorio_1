#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"
//menu de opciones para elegir los "case" del main.
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
//valida el rango del numero ingresado conparandolo con un minimo y un maximo tambien ingresados por el usuario. 
int ValidarRango(int x,int min,int max)
{
	if(x<min || x>max)
		return 1;
	return 0;
}
//valida el largo de una cadena.
int ValidarCadena(char cad[],int TAM)
{
	if(strlen(cad)>TAM)
		return 1;
	return 0;
}
//busca un lugar libre en memoria.
int BuscarLibre(Persona per[],int TAM)
{
	int i,indice=-1;
	for(i=0;i<TAM;i++)
	{
		if(per[i].isEmpty==0)
		{
			indice=i;
			break;
		}
	}
	return indice;
}
//inicializa los parametros de la estructura.
void inicializar(Persona per[])
{
	int i;
	for(i=0;i<20;i++)
	{
		per[i].isEmpty=0;
		per[i].dni=0;
		per[i].edad=0;
		per[i].nombre[0]='\0';
	}
}
//compara un dni ingresado con los que haya en la structura y devuelve el indice de ello.
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
//-------------------------------------------
//Da el alta de una persona ingresando sus datos siendo llamada desde el main.
void alta(Persona per[])
{
    char auxcad[50];
    int auxedad,auxdni;
	int index,i,encontro;	
	
       	encontro=0;
        index=BuscarLibre(per,20);
       	if(index==-1)
		{
			printf("No se encontro lugar\n");
		}
		else
		{
			printf("Ingrese D.N.I XX.XXX.XXX sin puntos: ");
	      	scanf("%d",&auxdni);
	       	while(ValidarRango(auxdni,10000000,99999999))
				{
					printf("ERROR,Ingrese D.N.I XX.XXX.XXX sin puntos: ");
		        	scanf("%d",&auxdni);							
				}
	           	for(i=0;i<20;i++)
				{
					if( per[i].dni== auxdni )
					{
						encontro=1;
						break;
					}
				}
				if(!encontro)
				{
				   	per[index].dni=auxdni;
				   	printf("Ingrese nombre: ");
		           	fflush(stdin);
		           	gets(auxcad);
		           	while(ValidarCadena(auxcad,25))
					{
					   	printf("ERROR,Ingrese nombre: ");
			           	fflush(stdin);
			           	gets(auxcad);
					}
		           	strcpy(per[index].nombre,auxcad);
		           	printf("Ingrese edad: ");
		           	scanf("%d",&auxedad);
		           	while(ValidarRango(auxedad,0,100))
						{
						   	printf("ERROR,Ingrese edad: ");
		           			scanf("%d",&auxedad);			
						}
		           	per[index].edad=auxedad;
		           	per[index].isEmpty=1;
				}
				else
				{
					printf("El dni ya se encuentra\n");
				}
		}   	
}
//Da de baja a una persona ingresando su dni y comprovando que se encuentre,siendo llamada desde el main.
void baja(Persona per[])
{
	char opcion='s';
    char auxcad[50];
    int auxedad,auxdni;
	int index;
       	printf("Ingrese DNI:");
       	scanf("%d",&auxdni);
	   	while(ValidarRango(auxdni,10000000,99999999))
			{
				printf("ERROR,Ingrese D.N.I XX.XXX.XXX sin puntos: ");
			   	scanf("%d",&auxdni);							
			}
       	index=BuscarDNI(per,20,auxdni);
       	if(index==-1)
		{
			printf("No se encuentra el DNI\n");
		}
		else
		{
			printf("\n%s\t%d\t%d\n",per[index].nombre,per[index].edad,per[index].dni);
			printf("\nDesea Borrarlo? s/n \n");
			fflush(stdin);
			opcion=tolower(getche());
			while(opcion!='s' && opcion !='n')
			{
				printf("ERROR,Desea Borrarlo? s/n \n");
				fflush(stdin);
				opcion=tolower(getche());
			}
			if(opcion=='n')
			{
				printf("Salio sin Eliminar\n");
			}
			else
			{
				per[index].dni=0;
				per[index].nombre[0]='\0';
				per[index].edad=0;
			}	
		}	
}
//Lista por orden alfavetico de a a la z los nombres de la structura.
void listadoPorNombre(Persona per[])
{
	int i,j;
	Persona auxST;
   	for(i=0;i<19;i++)
	{
		for(j=i+1;j<20;j++)
		{
			if( strcmp(per[i].nombre,per[j].nombre) >0 )
			{
				auxST=per[i];
				per[i]=per[j];
				per[j]=auxST;
			}
		}
	}
	printf("   Nombre\t   Edad\t  	  DNI\t   \n");
	for(i=0;i<20;i++)
	{
		if(per[i].isEmpty!=0)
		{
			printf("   %10s\t   %3d\t   %8d\t   \n",per[i].nombre,per[i].edad,per[i].dni);
		}
	}	
}
//Muestra una lista y cuenta cuantas personas de determina edad hay en diferentes columnas.
void listadoDeEdades(Persona per[])
{
    int hasta18=0,de19a35=0,mayorDe35=0;
    int mayor,flag=0,i;
    
	for(i=0; i<20; i++)
    {
  		if(per[i].dni != 0 && per[i].edad < 19)
		{
			hasta18++;
		}
    	if(per[i].dni != 0 && per[i].edad > 18 && per[i].edad < 36)
		{
			de19a35++;
		}
        if(per[i].dni != 0 && per[i].edad > 35)
		{
			mayorDe35++;
		}                     
    }
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
   		 mayor = hasta18;
    }
	else
	{
		if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
		{
			mayor = de19a35;
		}
		else
		{
			if(mayorDe35 >= de19a35 && mayorDe35 >= de19a35)
			{
				mayor = mayorDe35;
			}
		}
	}

	for(i=mayor; i>0; i--)
	{
		if(i<= hasta18)
		{
		printf("*");
		}
		if(i<= de19a35)
		{
		flag=1;
		printf("\t*");
		}
		if(i<= mayorDe35)
		{
			if(flag==0)
			{
				printf("\t\t*");
			}
			if(flag==1)
			{
				printf("\t*");				
			}
		}
		printf("\n");
	}
	printf("-----------------");
	printf("\n<18\t19-35\t>35\n");
	printf("\n   %d\t%d\t%d\n\n",hasta18,de19a35,mayorDe35);
}
