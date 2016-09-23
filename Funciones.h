typedef struct
{
	char nombre;
	int edad;
	int dni;
}Persona;

int ValidarRango(int,int,int);
int ValidarCadena(char[],int);
int menu();

void inicializar(Persona[],int);
int BuscarLibre(Persona[],int);
int BuscarDNI(Persona[],int,int);
