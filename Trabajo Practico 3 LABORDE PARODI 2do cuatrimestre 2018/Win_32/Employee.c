#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "FuncionesLPA.h"

Employee* employee_new(){

    Employee * auxEmployee;
    auxEmployee=(Employee*)malloc(sizeof(Employee));

    if( auxEmployee!= NULL )
    {
        auxEmployee->id=0;
        auxEmployee->horasTrabajadas=0;
        strcpy(auxEmployee->nombre,"");
        auxEmployee->sueldo=0;
    }

    return auxEmployee;

}

Employee* employee_newParametros(int* idStr,char * nombreStr,int* horasTrabajadasStr, int * sueldo){
    Employee * auxEmployee;
    auxEmployee=employee_new();

    if( auxEmployee!= NULL )
    {
        auxEmployee->id = *idStr;
        auxEmployee->horasTrabajadas = *horasTrabajadasStr;
        strcpy(auxEmployee->nombre,nombreStr);
        auxEmployee->sueldo = *sueldo;
    }

    return auxEmployee;

}

void employee_delete(Employee * this){

    if( this!= NULL )
    {
        this->id=0;
        this->horasTrabajadas=0;
        strcpy(this->nombre,"");
        this->sueldo=0;
    }
    free(this);

}

int employee_setId(Employee* list,int id){

    int isOk=0;
    if( id > 0 && list!=NULL ){
        list->id=id;
        isOk=1;
    }
    return isOk;
}

int employee_getId(Employee* list,int* id){

    int isOk=0;
    if(list!=NULL ){
        *id=list->id;
        isOk=1;
    }
    return isOk;
}

int employee_setNombre(Employee* list,char* nombre){

    int isOk=0;
    if(list!=NULL ){
        strcpy(list->nombre,nombre);
        isOk=1;
    }
    return isOk;

}

int employee_getNombre(Employee* list,char* nombre){

    int isOk=0;
        if(list!=NULL ){
            strcpy(nombre,list->nombre);
            isOk=1;
        }
        return isOk;
}

int employee_setHorasTrabajadas(Employee* list,int horasTrabajadas){

    int isOk=0;
    if(horasTrabajadas >0 && list!=NULL ){
        list->horasTrabajadas=horasTrabajadas;
        isOk=1;
    }
    return isOk;

}

int employee_getHorasTrabajadas(Employee* list,int* horasTrabajadas){

     int isOk=0;
    if(list!=NULL ){
        *horasTrabajadas=list->horasTrabajadas;
        isOk=1;
    }
    return isOk;

}

int employee_setSueldo(Employee* list,int sueldo){

    int isOk=0;
        if( sueldo > 0 && list!=NULL ){
            list->sueldo=sueldo;
            isOk=1;
        }
        return isOk;
}

int employee_getSueldo(Employee* list,int* sueldo){

     int isOk=0;
    if( list!=NULL ){
        *sueldo=list->sueldo;
        isOk=1;
    }
    return isOk;

}

int employee_sortID(void* empleado,void * empleado2)
{
    int auxID=0;
    Employee * empA;
    Employee * empB;

    if(empleado!= NULL && empleado2!=NULL){
        empA=(Employee*) empleado;
        empB=(Employee*) empleado2;
        if(empA->id > empB->id)
        {
            auxID=-1;
        }else{
             if(empA->id < empB->id){
                auxID=1;
             }
        }
    }
    return auxID;
}



int employee_sortNombre(void* empleado,void * empleado2)
{
    int auxNombre;
    Employee * empA;
    Employee * empB;
    empA=(Employee*) empleado;
    empB=(Employee*) empleado2;

    if(empleado!= NULL && empleado2!=NULL){

        auxNombre = strcmp(empA->nombre,empB->nombre);
    }
    return auxNombre;
}


int employee_sortHorasTrabajadas(void* empleado,void * empleado2)
{
    int auxHoras=0;
    Employee * empA;
    Employee * empB;

    if(empleado!= NULL && empleado2!=NULL){
        empA=(Employee*) empleado;
        empB=(Employee*) empleado2;
        if(empA->horasTrabajadas > empB->horasTrabajadas)
        {
            auxHoras=-1;
        }else{
             if(empA->id < empB->id){
                auxHoras=1;
             }
        }
    }
    return auxHoras;
}
int employee_sortSueldo(void* empleado,void * empleado2)
{
    int auxsueldo=0;
    Employee * empA;
    Employee * empB;

    if(empleado!= NULL && empleado2!=NULL){
        empA=(Employee*) empleado;
        empB=(Employee*) empleado2;
        if(empA->sueldo > empB->sueldo)
        {
            auxsueldo=-1;
        }else{
             if(empA->id < empB->id){
                auxsueldo=1;
             }
        }
    }
    return auxsueldo;
}

int employee_editEmploye(Employee* empleado){

    int isOk=0;
    int opcion=-1;
    int valida;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;


    if (empleado!=NULL){

        while(opcion!=4){
            system("cls");
             MuestraMenu("********************* EDITA EMPLEADO *******************\n\n");
            MuestraMenu("1- Nombre\n2- Horas trabajadas\n3- Sueldo\n4-Salir\n");
            do
            {
                valida = getInt(&opcion,"Ingrese una opcion :","La opcion esta fuera del rango de valores\n",1,4);
            }
            while(valida);

            switch(opcion){
            case 1:// edit nombre
                system("cls");

                    do
                    {
                        valida = getString(auxNombre,"Ingrese nuevo Nombre :","El nombre ingresado es incorrecto.\n",1,128);
                    }
                    while(valida);
                    strcpy(empleado->nombre,auxNombre);

                system("pause");
                break;
            case 2://edit horas
                 system("cls");
                    do
                    {
                        valida = getInt(&auxHoras,"Ingrese nuevas Horas :","Las horas ingresadas son incorrectas.\n",1,360);
                    }
                    while(valida);
                    empleado->horasTrabajadas=auxHoras;
                system("pause");
                break;
            case 3://edit sueldo
                 system("cls");
                do
                    {
                        valida = getInt(&auxSueldo,"Ingrese nuevo Sueldo :","El sueldo ingresado es incorrecto.\n",1,9999999);
                    }
                    while(valida);
                    empleado->sueldo=auxSueldo;
                system("pause");
                break;

            }
        }

        isOk=1;
    }


    return isOk;
}
