#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "FuncionesLPA.h"

vendedor* employee_new(){

    vendedor * auxEmployee;
    auxEmployee=(vendedor*)malloc(sizeof(vendedor));

    if( auxEmployee!= NULL )
    {
        auxEmployee->id=0;
        auxEmployee->nivel=0;
        auxEmployee->cantidad_productos_vendidos=0;
        auxEmployee->monto_vendido=0;
        strcpy(auxEmployee->nombre,"");

    }
    return auxEmployee;

}

vendedor* employee_newParametros(int* idStr,char * nombreStr,int* nivel, int * cantProductos, float * monto){
    vendedor * auxEmployee;
    auxEmployee=employee_new();

    if( auxEmployee!= NULL )
    {
        employee_setId(auxEmployee,*idStr);
        employee_setNombre(auxEmployee,nombreStr);
        auxEmployee->nivel=*nivel;
        auxEmployee->cantidad_productos_vendidos=*cantProductos;
        auxEmployee->monto_vendido=*monto;


    }

    return auxEmployee;

}
/*
void employee_delete(vendedor * this){

    if( this!= NULL )
    {
        this->id=0;
        this->horasTrabajadas=0;
        strcpy(this->nombre,"");
        this->sueldo=0;
    }
    free(this);

}
*/
int employee_setId(vendedor* list,int id){

    int isOk=0;
    if( id > 0 && list!=NULL ){
        list->id=id;
        isOk=1;
    }
    return isOk;
}

int employee_getId(vendedor* list,int* id){

    int isOk=0;
    if(list!=NULL ){
        *id=list->id;
        isOk=1;
    }
    return isOk;
}

int employee_getNivel(vendedor* list,int * nivel){

    int isOk=0;
    if(list!=NULL ){
        *nivel=list->nivel;
        isOk=1;
    }
    return isOk;
}

int employee_getProd(vendedor* list,int * cant){

    int isOk=0;
    if(list!=NULL ){
        *cant=list->cantidad_productos_vendidos;
        isOk=1;
    }
    return isOk;
}

int employee_getMonto(vendedor* list,float * monto){

    int isOk=0;
    if(list!=NULL ){
        *monto=list->monto_vendido;
        isOk=1;
    }
    return isOk;
}

int employee_getComision(vendedor* list,float * comision){

    int isOk=0;
    if(list!=NULL ){
        *comision=list->comision;
        isOk=1;
    }
    return isOk;
}

int employee_setNombre(vendedor* list,char* nombre){

    int isOk=0;
    if(list!=NULL ){
        strcpy(list->nombre,nombre);
        isOk=1;
    }
    return isOk;

}

int employee_getNombre(vendedor* list,char* nombre){

    int isOk=0;
        if(list!=NULL ){
            strcpy(nombre,list->nombre);
            isOk=1;
        }
        return isOk;
}
/*
int employee_setHorasTrabajadas(vendedor* list,int horasTrabajadas){

    int isOk=0;
    if(horasTrabajadas >0 && list!=NULL ){
        list->horasTrabajadas=horasTrabajadas;
        isOk=1;
    }
    return isOk;

}
*/
/*
int employee_getHorasTrabajadas(vendedor* list,int* horasTrabajadas){

     int isOk=0;
    if(list!=NULL ){
        *horasTrabajadas=list->horasTrabajadas;
        isOk=1;
    }
    return isOk;

}

int employee_setSueldo(vendedor* list,int sueldo){

    int isOk=0;
        if( sueldo > 0 && list!=NULL ){
            list->sueldo=sueldo;
            isOk=1;
        }
        return isOk;
}
*//*
int employee_getSueldo(vendedor* list,int* sueldo){

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
    vendedor * empA;
    vendedor * empB;

    if(empleado!= NULL && empleado2!=NULL){
        empA=(vendedor*) empleado;
        empB=(vendedor*) empleado2;
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
    vendedor * empA;
    vendedor * empB;
    empA=(vendedor*) empleado;
    empB=(vendedor*) empleado2;

    if(empleado!= NULL && empleado2!=NULL){

        auxNombre = strcmp(empA->nombre,empB->nombre);
    }
    return auxNombre;
}


int employee_sortHorasTrabajadas(void* empleado,void * empleado2)
{
    int auxHoras=0;
    vendedor * empA;
    vendedor * empB;

    if(empleado!= NULL && empleado2!=NULL){
        empA=(vendedor*) empleado;
        empB=(vendedor*) empleado2;
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
    vendedor * empA;
    vendedor * empB;

    if(empleado!= NULL && empleado2!=NULL){
        empA=(vendedor*) empleado;
        empB=(vendedor*) empleado2;
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

int employee_editEmploye(vendedor* empleado){

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

int calculaSueldo(void* persona){

    int calculado = 0;
    int retorno=0;
    int horas;
    vendedor * personaAux;
    personaAux=(vendedor*)persona;
    if( personaAux!= NULL)
    {
        horas= personaAux->horasTrabajadas ;
        if(horas>0 && horas<177)
        {
            calculado=horas * 180;
        }
        if(horas>176 && horas<209)
        {
            calculado=176 * 180 +((horas-176)*270);
        }
        if(horas>208)
        {
            calculado=176 * 180 + (32*270) + ((horas-208) * 360);
        }

        employee_setSueldo(personaAux,calculado);
        retorno=1;

    }
    return retorno;

}
*/

int calculaComision(void* persona){

    int retorno=0;
    vendedor * personaAux;
    personaAux=(vendedor*)persona;
    if( personaAux!= NULL)
    {

        if(personaAux->nivel==0)
        {
            personaAux->comision=(personaAux->monto_vendido* 2 )/100;
        }else{
            if(personaAux->cantidad_productos_vendidos>100)
            {
                personaAux->comision=personaAux->monto_vendido* 3.5 /100;
            }else{
                personaAux->comision=personaAux->monto_vendido* 5 /100;
            }
        }

       // employee_setSueldo(personaAux,calculado);
        retorno=1;

    }
    return retorno;

}

int filtra1(void* persona)
{
    int ok = 0;
    vendedor * personaAux;
    if( persona!= NULL)
    {
        personaAux=(vendedor*)persona;
        if(personaAux->nivel==1) ok=1;
    }
    return ok;
}
int filtra2(void* persona)
{
    int ok = 0;
    vendedor * personaAux;
    if( persona!= NULL)
    {
        personaAux=(vendedor*)persona;
        if(personaAux->nivel==2) ok=1;
    }
    return ok;
}
int filtra0(void* persona)
{
    int ok = 0;
    vendedor * personaAux;
    if( persona!= NULL)
    {
        personaAux=(vendedor*)persona;
        if(personaAux->nivel==0) ok=1;
    }
    return ok;
}


