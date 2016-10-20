#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"
typedef struct
{
	char nombre[26];
	int edad;
	int dni;
	int isEmpty;
}EPersona;
int main()
{
	EPersona persona[20];
    char seguir='s',opcion='s';
	 
    inicializar(persona);
    
    do
    {
        switch(menu())
        {
            case 1:
            	system("cls");
            	printf("ALTA\n");
 				alta(persona);
                break;
            case 2:
            	system("cls");
            	printf("BAJA\n");
            	baja(persona);
                break;
            case 3:
            	system("cls");
            	printf("Listado Por Nombre\n");
            	listadoPorNombre(persona);
                break;
            case 4:
            	system("cls");
            	printf("Listado de edades\n");
            	listadoDeEdades(persona);        	
                break;
            case 5:
            	printf("Desea Salir? s/n \n");
            	fflush(stdin);
            	opcion=tolower(getche());
				while(opcion!='s' && opcion !='n')
					{
						printf("ERROR\nDesea Salir? s/n \n");
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
    printf("\n\n");
    system("pause");
    return 0;
}
