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
    LinkedList* listaRetornada= ll_newLinkedList();

    do{
        MenuPrincipal();
        getInt(&option,"Ingrese la opcion que desea seleccionar: ","El dato es incorrecto",1,5);
        switch(option)
        {
            case 1:{
                system("cls");
                char nombre[50];
               /* printf("ingrese nombre del archivo: \n");
                scanf("%s",nombre);
                */
                int abrio;
                if(ll_isEmpty(listaEmpleados))
                {
                    isOpen=controller_loadFromText("DATA.csv",listaEmpleados);
                if(isOpen==0){
                    printf("Hubo un error al momento de abrir el archivo\n");
                }else{
                    isOpen=1;
                    printf("Se abrio el archivo correctamente\n");
                    }

                }else{

                    printf("El archivo ya fue abierto\n");


                }


                system("pause");
                break;
                }
           case 2:
               controller_ListEmployee(listaEmpleados);
               system("pause");
                break;
            case 3:
                controller_listComisiones(listaEmpleados);
                system("pause");
                break;
            case 4:
                controller_saveAsText("info.csv",listaEmpleados);
                system("pause");
                break;
            case 5:
                ll_clear(listaEmpleados);
                ll_deleteLinkedList(listaEmpleados);
                system("pause");
                break;
            case 6:
               system("cls");

                system("pause");
                break;
            case 7:
                break;
            case 8:
                system("cls");
              //  listaConSueldos=ll_map(listaEmpleados,calculaSueldo);
                system("pause");
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                system("cls");

                break;
        }

    }while(option != 5);
    return 0;
}
