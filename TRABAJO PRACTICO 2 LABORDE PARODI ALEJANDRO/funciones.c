#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//esta es para isalpha y demas
#include "funciones.h"
#include "FuncionesImput.h"

void BorrarPersona(EPersona lista[],int posicion)
{
    lista[posicion].estado=0;
}

int buscarPorDni(EPersona lista[], long dni, int cantidad)
{
    int posicion;
    for(posicion=0;posicion<cantidad;posicion++)
    {
        if(lista[posicion].dni==dni)
        {
            return  posicion;
            break;
        }
    }return -1;
}

int obtenerEspacioLibre(EPersona lista[],int cantidad)
{
    int posicion=0;
    while(posicion<cantidad)
    {
        if(lista[posicion].estado==0)
        {
            return posicion;
            break;
        }else
        {
            posicion++;
        }

    } return -1;

}

void CargaPersona(EPersona Lista[],int posicion)
{
    int valida;
    do
    {
        setbuf(stdin,NULL);
        printf("Ingrese Nombre y Apellido: ");
        scanf("%[^\n]",Lista[posicion].nombre);
        valida=validaCadenaAlpha(Lista[posicion].nombre);

    }while(valida==0);

    printf("Ingrese Edad: ");
    scanf("%d",&Lista[posicion].edad);

    while((Lista[posicion].edad>100 || Lista[posicion].edad<1) && !isdigit(Lista[posicion].edad))
    {
        printf("Ingrese Edad nuevamente: ");
        setbuf(stdin,NULL);
        scanf("%d",&Lista[posicion].edad);
    }


        Lista[posicion].dni=getValidInt("Ingrese DNI:","El DNI ingresado es incorrecto",10000000,99999999);

        Lista[posicion].estado=1;
}

int BuscaEspacioLibre(EPersona lista[],int cantidad)
{
    int posicion;

    for(posicion=0;posicion<cantidad;posicion++)
    {
        if(lista[posicion].estado==0)
        {
            return posicion;
            break;
        }
    }
    return -1;
}

void imprimeLista(EPersona lista[],int cantidad)
{
    int posicion;

    for(posicion=0;posicion<cantidad;posicion++)
    {
        if(lista[posicion].estado==1)
        {
            printf("Nombre: %s \t",lista[posicion].nombre);
            printf("Edad: %d \t",lista[posicion].edad);
            printf("DNI: %ld \n",lista[posicion].dni);
        }
    }
}

void  GraficaEdades(EPersona lista[],int cantidad)
{

    int posicion,posicion2;
    int MayoresDe35=0;
    int Mayor18menor35=0;
    int menoresDe18=0;
    char grafico [3][20];

    for(posicion=0;posicion<cantidad;posicion++)
    {
        if(lista[posicion].estado==1)
        {
            if(lista[posicion].edad>35)
            {
                MayoresDe35++;
            }
            if(lista[posicion].edad<=18)
            {
                menoresDe18++;
            }
            if(lista[posicion].edad>18 && (lista[posicion].edad<=35))
            {
                Mayor18menor35++;
            }
        }

    }

    printf("%d \t %d \t %d\n", menoresDe18,Mayor18menor35,MayoresDe35);
    for(posicion=0;posicion<3;posicion++)
    {
        for(posicion2=0;posicion2<20;posicion2++)
        {
            grafico[posicion][posicion2]=' ';
        }
    }//carga el grafico con espacios blancos


    for(posicion2=19;posicion2>(19-menoresDe18);posicion2--)
        {
            grafico[0][posicion2]='X';
        }
        printf("llego");
    for(posicion2=19;posicion2>(19-Mayor18menor35);posicion2--)
        {
            grafico[1][posicion2]='X';
        }
    for(posicion2=19;posicion2>(19-MayoresDe35);posicion2--)
        {
            grafico[2][posicion2]='X';
        }

    for(posicion2=0;posicion2<19;posicion2++)
    {
        printf("\n");
        for(posicion=0;posicion<3;posicion++)
        {
            printf("%c \t",grafico[posicion][posicion2]);
        }// muestra el grafico
    }
    printf("\n<18\t19-35\t>35\n");

}

void ordenaStruct(EPersona lista[],int cantidad)
{
    int posicion,posicion2;
    EPersona auxiliar;
    int compara;

    for(posicion=0;posicion<cantidad-1;posicion++)
    {
        for(posicion2=1;posicion2<cantidad;posicion2++)
        {
            compara=strcmp(lista[posicion].nombre,lista[posicion2].nombre);
            if( compara<0 )
            {
                auxiliar=lista[posicion];
                lista[posicion]=lista[posicion2];
                lista[posicion2]=auxiliar;
            }
        }

    }
}

void imprimeMenu()
{

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por  nombre\n");
    printf("4- Imprimir grafico de edades\n\n");
    printf("5- Salir\n");

}

void inicializaMatriz(EPersona lista[],int cantidad)
{
    int posicion;
    for(posicion=0;posicion<cantidad;posicion++)
    {
        lista[posicion].estado=0;
        lista[posicion].edad=0;
    }
}

int validaCadenaAlpha(char cadena[])
{
    int posicion;
    int retorno;
    int largo;
    int contadorDeEspacios=0;

    largo= strlen(cadena);
    for(posicion=0;posicion<largo;posicion++)
    {
        if(cadena[posicion]!=' ')
        {
            retorno= isalpha(cadena[posicion]);

            if(retorno==0)
            {
                return 0;
                break;
            }
        }else
            {
                contadorDeEspacios++;
            }
    }
    if (contadorDeEspacios>1)
    {
        return 0;
    }else{

        return 1;
        }
}



