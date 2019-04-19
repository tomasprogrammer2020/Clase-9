#include "Employers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int optionsMenu(char message[])
{
    int option;
    printf("Elija la opcion correspondiente:\n");
    printf("%s", message);
    scanf("%d", &option);

    return option;
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]={1,8,9,7,2,4};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char sexo[]={'F','M','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000,6000};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;

    }
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    printf("\nLegajo\t\tNombre\t\t\tSexo\t\tSueldo Bruto\t\tSueldo Neto\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarEmpleado(lista[i]);
        }

    }
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("\n%d\t\t%s\t\t\t%c\t\t$%.2f\t\t$%.2f\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto);

}


void cargarEmpleado(eEmpleado lista[], int tam)
{
    int i;
    i = buscarLibre(lista, tam);

    if(i!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f", &lista[i].sueldoBruto);
        lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;
        lista[i].estado = OCUPADO;

        lista[i].sexo=toupper(lista[i].sexo);
        pasarMayusPrimeras(lista, i);
        mensajeSexoAlta (lista, i);

    }
    else
    {
        printf("Espacio insuficiente\n");
    }
}

void mensajeSexoAlta (eEmpleado lista[], int i)
{
         if (lista[i].sexo=='F')
         {
             printf("\nLa empleada %s fue cargada con exito\n", lista[i].nombre);
         }
         else
         {
             printf("\nEl empleado %s fue cargado con exito\n", lista[i].nombre);
         }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}


int buscarLegajo (eEmpleado lista[], int tam)
{
int posLegajo=-1;
int flag=0;
int legajo;
int i;

legajo = getInt("numero de legajo");


    for (i=0; i<tam;i++)
     {
       if (lista[i].legajo==legajo)
         {
          posLegajo=i;
          flag=1;
          break;
          }
     }

      if (flag==0)
      {
        printf("\nEl legajo no fue encontrado\n");
       }

return posLegajo;
}

int getInt (char message[])
{
    int number;

     printf("\nIngrese %s: ", message);
     scanf("%d", &number);

return number;
}

void darDeBaja (eEmpleado lista[], int tam)
{
    int i;

    i = buscarLegajo(lista, tam);

    if (i!=-1)
    {
        lista[i].estado=LIBRE;
        mensajeSexoBaja (lista, i);
    }
}

void mensajeSexoBaja (eEmpleado lista[], int i)
{
         if (lista[i].sexo=='F')
         {
             printf("\nLa empleada %s fue dada de baja con exito\n", lista[i].nombre);
         }
         else
         {
             printf("\nEl empleado %s fue dado de baja con exito\n", lista[i].nombre);
         }
}

void pasarMayusPrimeras(eEmpleado lista[], int i)
{
strlwr(lista[i].nombre);

lista[i].nombre[0] = toupper(lista[i].nombre[0]);
int j=0;

while(lista[i].nombre[j]!='\0')
{

    if(lista[i].nombre[j]==' ')
    {
        lista[i].nombre[j+1]= toupper (lista[i].nombre[j+1]);

    }
    j++;
}
}

/*
void modificar(eEmpleado lista[], int tam, int legajo)
{
    int flag=0;

        for (i=0; i<tam;i++)
        {
            if (lista[i].legajo==legajo)
            {
                printf("Ingrese nuevo sueldo bruto: ");
                scanf("%d", &nuevoDato);
                lista[i].sueldoBruto = nuevoDato;
                lista[i].sueldoNeto = nuevoDato * 0.85;
                printf("El sueldo bruto fue cambiado con exito\n");
                flag=1;
                break;
            }
        }

        if (flag==0;
        {
            printf("El legajo no fue encontrado\n");
        }


}
*/
