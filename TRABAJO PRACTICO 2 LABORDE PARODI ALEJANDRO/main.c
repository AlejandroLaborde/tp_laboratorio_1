#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "FuncionesImput.h"

#define CANT 20

int main()
{
    char seguir='s';
    char opcion=0;
    EPersona Lista[CANT];
    int posicion;
    int dni;
    char salir;

    inicializaMatriz(Lista,CANT);

    while(seguir=='s')
    {
        imprimeMenu();
        setbuf(stdin,NULL);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case '1':
            system("cls");
            posicion=obtenerEspacioLibre(Lista,CANT);
            if(posicion!= -1)
            {
                CargaPersona(Lista,posicion);
            }
            break;
            case '2':
            system("cls");
            printf("Ingrese el DNI de la persona que desea eliminar: ");
            scanf("%d",&dni);
            posicion=buscarPorDni(Lista,dni,CANT);
            if (posicion==-1)
            {
                printf("No se encuenta el DNI \n");
            }
            else
            {
                printf("NOMBRE:%s \nDNI: %ld\n",Lista[posicion].nombre,Lista[posicion].dni);
                setbuf(stdin,NULL);
                printf("Desea eliminar? S/N \n");
                setbuf(stdin,NULL);
                scanf("%c",&salir);
                salir=tolower(salir);
                if(salir=='s')
                {
                    BorrarPersona(Lista,posicion);
                    printf("La persona con el DNI ingresado, se elimino correctamente \n");
                }
                else
                {
                    printf("La operacion se cancelo\n");
                    break;
                }
            }
                break;
            case '3':
                system("cls");
                ordenaStruct(Lista,CANT);
                imprimeLista(Lista,CANT);
                break;
            case '4':
                system("cls");
                //grafica edades
                printf("\t\t\tGRAFICO DE EDADES\t\t\n");
                GraficaEdades(Lista,CANT);
                break;
            case '5':
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("La opcion ingresada es incorrecta...\n");
                setbuf(stdin,NULL);
        }
    }
    return 0;
}

