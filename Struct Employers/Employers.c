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
    int legajos[]={10,8,1,7,2,4};
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
    printf("Legajo\t\tNombre\t\t\tSexo\t\tSueldo Bruto\t\tSueldo Neto\n");
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
        lista[i].legajo=rand() % 9999999;
        pedirNombre(lista, i);
        pedirSexo(lista, i);
        pedirSueldoBruto(lista, i);
        lista[i].estado = OCUPADO;


        mostrarEmpleado(lista[i]);

        if (verificarConformidad("Los datos ingresados son correctos?")==1)
        {
            mensajeSexo (lista, i, "dada de alta", "dado de alta");
        }
        else
        {
            printf("El empleado no sera cargado\n");
            lista[i].estado = LIBRE;
        }

    }
    else
    {
        printf("Espacio insuficiente\n");
    }
}

int verificarConformidad (char message[])
{
    int guardo=0;
    char respuesta[2];

        printf("%s\n", message);
        fflush(stdin);
        scanf("%s", respuesta);

        if (strcmp(respuesta, "si")==0)
        {
            guardo=1;
        }

        return guardo;
}
void pedirSueldoBruto (eEmpleado lista[], int i)
{
    float aux;
    do{
    printf("Ingrese sueldo bruto: ");
    scanf("%f", &aux);

    if (aux<0 /*|| isdigit(aux)==0*/)
    {
        printf("Error, el sueldo ingresado es invalido. Ingreselo nuevamente\n");
    }

    } while (aux<0 /*|| isdigit(aux)==0*/);

            lista[i].sueldoBruto=aux;
            lista[i].sueldoNeto= lista[i].sueldoBruto * 0.85;


}
void pedirSexo(eEmpleado lista[], int i)
{
    char buffer;

    do{
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &buffer);
        buffer=toupper(buffer);

        if (buffer != 'F' && buffer != 'M')
        {
            printf("Error, el sexo ingresado no existe. Ingreselo nuevamente\n");
        }

    } while(buffer != 'F' && buffer != 'M');

    lista[i].sexo=buffer;
}

void pedirNombre(eEmpleado lista[], int i)
{
    char buffer[100];

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%[^\n]",buffer);

    pasarMayusPrimeras(buffer);
    strcpy (lista[i].nombre, buffer);
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

legajo = getInt("el numero de legajo");


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

     printf("Ingrese %s: ", message);
     scanf("%d", &number);

return number;
}

void darDeBaja (eEmpleado lista[], int tam)
{
    int i;

    mostrarListaEmpleados(lista, tam);
    i = buscarLegajo(lista, tam);

    if (i!=-1)
    {
        lista[i].estado=LIBRE;
        mensajeSexo (lista, i, "dada de baja", "dado de baja");
    }
}

void mensajeSexo (eEmpleado lista[], int i, char mensajeF[], char mensajeM[])
{
         if (lista[i].sexo=='F')
         {
             printf("\nLa empleada %s fue %s con exito\n", lista[i].nombre, mensajeF);
         }
         else
         {
             printf("\nEl empleado %s fue %s con exito\n", lista[i].nombre, mensajeM);
         }
}

void pasarMayusPrimeras(char nombre[])
{
strlwr(nombre);

nombre[0] = toupper(nombre[0]);
int j=0;

while(nombre[j]!='\0')
{

    if(nombre[j]==' ')
    {
        nombre[j+1]= toupper (nombre[j+1]);

    }
    j++;
}
}

void ordenarVector(eEmpleado lista[], int tam)
{
    int i, j;
    eEmpleado aux[1];

    for (i=0; i<tam-1; i++)
    {
        for (j=i+1; j<tam; j++)
        {
            if (lista[i].legajo>lista[j].legajo)
        {
            aux[0] = lista[i];
            lista[i]= lista[j];
            lista[j]= aux[0];
        }
        }
    }
}


void modificarSexo (eEmpleado lista[], int tam)
{
    eEmpleado aux[1];
    int i;
    mostrarListaEmpleados(lista, tam);
    i=buscarLegajo(lista, tam);

    if (i!=-1)
   {
       do{
        system("cls");
        pedirSexo(aux,0);
        } while (verificarConformidad("El sexo ingresado es correcto?")!=1);
        lista[i].sexo=aux[0].sexo;
        printf("El sexo fue cambiado correctamente.\n");
}
}

void modificarNombre (eEmpleado lista[], int tam)
{
    eEmpleado aux[1];
    int i;
    mostrarListaEmpleados(lista, tam);
    i=buscarLegajo(lista, tam);

    if (i!=-1)
   {
       do{
        system("cls");
        pedirNombre(aux,0);
        } while (verificarConformidad("El nombre ingresado es correcto?")!=1);
        strcpy(lista[i].nombre,aux[0].nombre);
        printf("El nombre fue cambiado correctamente.\n");
   }
}

void modificarSueldo (eEmpleado lista[], int tam)
{
    eEmpleado aux[1];
    int i;
    mostrarListaEmpleados(lista, tam);
    i=buscarLegajo(lista, tam);

    if (i!=-1)
   {
       do{
        system("cls");
        pedirSueldoBruto(aux,0);
        } while (verificarConformidad("El sueldo bruto es correcto?")!=1);
        lista[i].sueldoBruto=aux[0].sueldoBruto;
        lista[i].sueldoNeto=lista[i].sueldoBruto*0.85;
        printf("El sueldo bruto fue cambiado correctamente.\n");
   }
}


//pedir num legajo antes y una lista
