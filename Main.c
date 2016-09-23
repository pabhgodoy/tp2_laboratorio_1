#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <string.h>
#include <ctype.h>

typedef struct
{
	char nombre[26];
	int edad;
	int dni;
}EPersona;


int main()
{
	EPersona persona[20];
	EPersona auxST;
    char seguir='s',opcion='s';
    char auxcad[50];
    int auxedad,auxdni;
	int index,i,j,encontro;
    
    /*inicializar(persona,20);*/
    do
    {
        switch(menu())
        {
            case 1:
            	system("cls");
            	encontro=0;
            	index=BuscarLibre(persona,20);
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
						if( persona[i].dni== auxdni )
						{
							encontro=1;
							break;
						}
					}
					if(!encontro)
					{
				     	persona[index].dni=auxdni;
					   	printf("Ingrese nombre: ");
		            	fflush(stdin);
		            	gets(auxcad);
		            	while(ValidarCadena(auxcad,25))
						{
						   	printf("ERROR,Ingrese nombre: ");
			            	fflush(stdin);
			            	gets(auxcad);
						}
		            	strcpy(persona[index].nombre,auxcad);
		            	printf("Ingrese edad: ");
		            	scanf("%d",&auxedad);
		            	while(ValidarRango(auxedad,0,100))
							{
							   	printf("ERROR,Ingrese edad: ");
		            			scanf("%d",&auxedad);			
							}
		            	persona[index].edad=auxedad;
					}
					else
					{
						printf("El dni ya se encuentra\n");
					}
				}    	
                break;
            case 2:
            	system("cls");
            	printf("Ingrese DNI:");
            	scanf("%d",&auxdni);
	            	while(ValidarRango(auxdni,10000000,99999999))
						{
							printf("ERROR,Ingrese D.N.I XX.XXX.XXX sin puntos: ");
			            	scanf("%d",&auxdni);							
						}
            	index=BuscarDNI(persona,20,auxdni);
            	if(index==-1)
				{
					printf("No se encuentra el DNI\n");
				}
				else
				{
					printf("%s\t%d\t%d",persona[index].nombre,persona[index].edad,persona[index].dni);
					printf("Desea Modificarlo? s/n \n");
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
						printf("salio sin modificar\n");
					}
					else
					{
						persona[index].dni=0;
					}	
				}
                break;
            case 3:
            	for(i=0;i<19;i++)
				{
					for(j=i+1;j<20;j++)
					{
						if( strcmp(persona[i].nombre,persona[j].nombre) >0 )
						{
							auxST=persona[i];
							persona[i]=persona[j];
							persona[j]=auxST;
						}
					}
				}
				printf("   Nombre\t   Edad\t   DNI\t   \n");
				for(i=0;i<20;i++)
				{
					printf("   %10s\t   %3d\t   %8d\t   \n",persona[i].nombre,persona[i].edad,persona[i].dni);
				}
                break;
            case 4:
            	for(i=0;i<19;i++)
				{
					for(j=i+1;j<20;j++)
					{
						if( persona[i].edad > persona[j].edad )
						{
							auxST=persona[i];
							persona[i]=persona[j];
							persona[j]=auxST;
						}
					}
				}         	
                break;
            case 5:
            	printf("Desea Salir? s/n \n");
            	fflush(stdin);
            	opcion=tolower(getche());
				while(opcion!='s' && opcion !='n')
					{
						printf("ERROR,Desea Salir? s/n \n");
						fflush(stdin);
						opcion=tolower(getche());
					}            	
            	if(opcion=='s')
				{
			       seguir = 'n';
				}
                break;
        }
    }while(seguir=='s');
    return 0;
}
