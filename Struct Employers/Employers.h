#define LIBRE 0
#define OCUPADO 1


/*
DOXYGEN all functions
*/

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

typedef struct
{
    int idSector;
    char description[];
}eSector;

int optionsMenu(char[]);
int optionsMenu(char[]);
void hardcodearDatosEmpleados(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void cargarEmpleado(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
void mostrarEmpleado(eEmpleado);
void mostrarListaEmpleados(eEmpleado[], int);
int buscarLegajo (eEmpleado[], int );
int getInt (char[]);
void darDeBaja (eEmpleado[], int);
void mensajeSexo (eEmpleado lista[], int i, char mensajeF[], char mensajeM[]);
void pasarMayusPrimeras(char[]);
void pedirNombre(eEmpleado[], int);
void pedirSexo(eEmpleado[], int);
void pedirSueldoBruto (eEmpleado[], int);
int verificarConformidad (char[]);
void ordenarVector(eEmpleado[], int);
void modificarSueldo (eEmpleado[], int);
void modificarSexo (eEmpleado[], int);
void modificarNombre (eEmpleado[], int);
void modificarSexo (eEmpleado[], int);
