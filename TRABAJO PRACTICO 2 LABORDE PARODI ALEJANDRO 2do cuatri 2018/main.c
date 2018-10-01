#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h.h"
#include <ctype.h>
#define CANT 10

int main()
{
    printf("\t\tTRABAJO PRACTICO PROGRAMACION-LPA\n");
    int option;
    Employee empleados[CANT];//={{1001,"pamela","laborde",123,1,1},{1003,"gustavo","laborde",123,2,1},{1004,"daniel","laborde",123,2,1},{1002,"alejandro","lab",123,1,1}};
    initEmployees(empleados,CANT);
    while(option!=5){

        MuestraMenu("1-Alta empleado\n2-Modificar empleado.\n3-Baja empleado.\n4-Informar\n5-Para salir\n");
        getInt(&option,"\ningrese el numero correspondiente a la accion que desea realizar[1-5]: ","El dato ingresado es incorrecto\n",1,5);
        switch(option){

            case 1:
                system("cls");
                upEmployed(empleados,CANT);
                break;
            case 2:
                system("cls");
                modifyEmployed(empleados,CANT);
                system("pause");
                break;
            case 3:
                system("cls");
                downEmployed(empleados,CANT);
                system("pause");
                break;
            case 4:
                system("cls");
                sortEmployees(empleados,CANT,1);
                informa(empleados,CANT);
                system("pause");
                break;
            case 5:
                system("cls");
                printf("\n\n\nSegundo trabajo practico UTNFRA Laborde Parodi Alejandro.\n\n\n");
                break;
        }
    }


    return 0;
}
