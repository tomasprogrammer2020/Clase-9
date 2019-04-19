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
void mensajeSexoAlta (eEmpleado[], int);
void mensajeSexoBaja (eEmpleado[], int);
void pasarMayusPrimeras(eEmpleado[], int);
