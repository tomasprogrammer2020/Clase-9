#include <stdio.h>
#include <stdlib.h>
#include "Employers.h"
#define T 3

/*

PEDIRSUELDOBRUTO validacion, al ingresar string isdigit devuelve bucle infinito
DEBUGGER error
Hay que separar librerias? pedirdatos-modificar-etc?
MOSTRAR EMPLEADO se corre, como crear una (cuadricula)
RAND devuelve los mismos numeros en cada uso
MODIFICAR: como hacerlo generico, molde ya hecho

proxima clase:
struct sector (id sector, description)
cancel buttons
*/

int main()
{
    eEmpleado lista[T];
    int option;
    int optionMod;

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
            case 3:
                do{
                system("pause");
                system("cls");
                optionMod = optionsMenu("1.Modificar nombre\n2.Modificar sexo\n3.Modificar sueldo\n4.Mostrar empleados\n5.Atras\n");
                switch (optionMod)
                {
                    case 1:
                        modificarNombre(lista,T);
                        break;
                    case 2:
                        modificarSexo (lista,T);
                        break;
                    case 3:
                        modificarSueldo(lista, T);
                        break;
                    case 4:
                        mostrarListaEmpleados(lista,T);
                        break;
                    case 5:
                        printf("Volvera al menu anterior\n");
                        break;
                    default:
                        printf("No ingreso una opcion valida\n");
                        break;
                }

                }while (optionMod!=5);

                break;
            case 4:
                ordenarVector(lista, T);
                printf("Los empleados fueron ordenados en forma creciente.\n");
                break;
            case 5:
                mostrarListaEmpleados(lista, T);
                break;
            case 6:
                printf("El programa se cerrara.\n");
                break;
            default:
                printf("No ingreso una opcion valida.\n");
                break;
        }

        system("pause");
        system("cls");

    }while(option!=6);

    return 0;
}
