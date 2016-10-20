//Prototipos de las funciones.
typedef struct
{
	char nombre[26];
	int edad;
	int dni;
	int isEmpty;
}Persona;

int ValidarRango(int,int,int);
int ValidarCadena(char[],int);
int menu();

void inicializar(Persona[]);
int BuscarLibre(Persona[],int);
int BuscarDNI(Persona[],int,int);

void alta(Persona[]);
void baja(Persona[]);
void listadoPorNombre(Persona[]);
void listadoDeEdades(Persona[]);
