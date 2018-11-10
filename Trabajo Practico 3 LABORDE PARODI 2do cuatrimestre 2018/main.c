#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "FuncionesLPA.h"


int main()
{
    int isOpen;
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        MenuPrincipal();
        getInt(&option,"Ingrese la opcion que desea seleccionar: ","El dato es incorrecto",1,10);
        switch(option)
        {
            case 1:{
                system("cls");
                isOpen=controller_loadFromText("data.cvs",listaEmpleados);
                if(isOpen==0){
                    printf("Hubo un error al momento de abrir el archivo\n");
                }else{
                    isOpen=1;
                    printf("Se abrio el archivo correctamente\n");
                    }
                system("pause");
                break;
                }
            case 2:{
                system("cls");
                isOpen=controller_loadFromBinary("data.bin",listaEmpleados);
                if(isOpen==0){
                    printf("Hubo un error al momento de abrir el archivo\n");
                }else{
                    isOpen=1;
                    printf("Se abrio el archivo correctamente\n");
                    }
                system("pause");
                break;
                }

            case 3:
                system("cls");
                    controller_addEmployee(listaEmpleados);
                system("pause");
                break;
            case 4:
                system("cls");
                    controller_editEmployee(listaEmpleados);
                system("pause");
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleados);
                system("pause");
                break;
            case 6:
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.cvs",listaEmpleados);
                system("pause");
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.bin",listaEmpleados);
                system("pause");
                break;
            case 10:
                system("cls");
                ll_clear(listaEmpleados);
                ll_deleteLinkedList(listaEmpleados);
                system("pause");
                break;
        }

    }while(option != 10);
    return 0;
}
