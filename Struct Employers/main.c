#include <stdio.h>
#include <stdlib.h>
#include "Employers.h"
#define T 3

/*
random legajo
aestethic
submenu still disappear when pressing wrong button
validate case 1 (all)
verify conformity
employers list in case 2

modifications

separate librarys

struct sector (id sector, description)
*/

int main()
{
    eEmpleado lista[T];
    int option;
    char loadMenu='y';

    inicializarEmpleados(lista, T);
    hardcodearDatosEmpleados(lista, T);

    do
    {
        option = optionsMenu("1.Dar de alta\n2.Dar de baja\n3.Modificar empleado\n4.Ordenar empleados por legajo\n5.Mostrar lista de empleados\n6.Salir\n");
        switch(option)
        {
            case 1:
                cargarEmpleado(lista, T);
                break;
            case 2:
                darDeBaja(lista, T);
                break;
            case 5:
                mostrarListaEmpleados(lista, T);
                break;
            case 6:
                printf("El programa se cerrara.\n");
                loadMenu='n';
                break;
            default:
                printf("No ingreso una opcion valida.\n");
                break;
        }

        system("pause");
        system("cls");

    }while(loadMenu=='y');

    return 0;
}
