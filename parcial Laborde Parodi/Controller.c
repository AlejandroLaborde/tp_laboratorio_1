#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "FuncionesLPA.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si no se pudo abrir archivo 1 si esta todo bien
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int aux;
    file= fopen(path,"r");
    if (file== NULL){
        aux=0;

    }else{
        aux=1;
        parser_EmployeeFromText(file,pArrayListEmployee);

        }
    return aux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* file;
    int aux;

    file= fopen(path,"rb");
    if (file== NULL){
        aux=0;
    }else{
        parser_EmployeeFromBinary(file,pArrayListEmployee);
        aux=1;
    }

    fclose(file);
    return aux;
}
*/
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *//*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int isOK=0;
    int valid;
    Employee* Eempleado;
    int id, horasTrabajadas,sueldo;
    char nombre[128];

    Eempleado = (void*)employee_new();
    if(Eempleado!=NULL)
    {
        do{
        valid=getInt(&id,"Ingrese id del empleado: \n","El id tiene que ser mayor a 0\n",0,99999999);
        }while(valid==-1);
        do{
        valid=getString(nombre,"ingrese nombre del empleado: \n","El nombre no puede superar los 128 caracteres",-1,128);
        }while(valid==-1);
        do{
        valid=getInt(&horasTrabajadas,"Ingrese  horas trabajadas empleado: \n","Las horas deben tienen que ser mayor a -1\n",-1,99999999);
        }while(valid==-1);

        do{
        valid=getInt(&sueldo,"Ingrese sueldo del empleado: \n","El sueldo tiene que ser mayor a -1\n",-1,99999999);
        }while(valid==-1);

        employee_setId(Eempleado,id);
        employee_setNombre(Eempleado,nombre);
        employee_setHorasTrabajadas(Eempleado,horasTrabajadas);
        employee_setSueldo(Eempleado,sueldo);

        ll_add(pArrayListEmployee,(void*)Eempleado);

     isOK=1;
    }
    return isOK;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
   int aux=0;
   int opcion;
   int Index;
   Employee* EmpleadoAModificar;

   if(controller_ListEmployee(pArrayListEmployee))
   {
    do{
    opcion = getInt(&Index ,"Ingrese el codigo de la persona que desee modificar:","El codigo esta fuera del rango de valores\n",1,10000);
    }while(opcion);

    for(int i=0;i<ll_len(pArrayListEmployee);i++)
    {
        EmpleadoAModificar=ll_get(pArrayListEmployee,i);
        if(Index==EmpleadoAModificar->id){

                  if( employee_editEmploye(EmpleadoAModificar))
            {
                aux=1;
            }else{
                printf("No se pudo modificar cliente ya que el codigo es incorrecto, intente nuevamente\n");
            }
            break;
        }




   }
    return aux;


}
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 *//*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
   int aux=0;
   int opcion;
   int Index;
   Employee* empleadoEliminado;

   if(controller_ListEmployee(pArrayListEmployee))
    {
        do{
            opcion = getInt(&Index,"Ingrese el codigo de la persona que desee eliminar:","El codigo esta fuera del rango de valores\n",1,10000);
        }
        while(opcion);
    }
    for(int i=0;i<ll_len(pArrayListEmployee);i++)
    {
        empleadoEliminado=ll_get(pArrayListEmployee,i);
        if(Index==empleadoEliminado->id)
        {
            printf("Desea eliminar a id: %d nombre: %s\n",empleadoEliminado->id,empleadoEliminado->nombre);
            getInt(&opcion,"Presione 1 para eliminar, o 2 para cancelar operacion","El numero ingresado no es valido",1,2);
            if(opcion==1){
                ll_remove(pArrayListEmployee,i);
                printf("El empleado se elimino correctamente");
                aux=1;
            }else{

                printf("Se cancela la baja de empleado\n");
            }
        }
    }

    return aux;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int i=0;
    int aux=0;
    vendedor * emplead;
    int id,nivel;
    char nombre[51];
    int cantProduc;
    float monto;
    printf("************LISTA EMPLEADOS******************* \n\n");
    printf("ID EMPLEADO\tNOMBRE\tHS nIvel cantProductos  monto  \n\n");
    emplead=ll_get(pArrayListEmployee,i);
    if(emplead != NULL){
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            emplead=ll_get(pArrayListEmployee,i);
            employee_getId(emplead,&id);
            employee_getNombre(emplead,nombre);
            employee_getNivel(emplead,&nivel);
            employee_getProd(emplead,&cantProduc);
            employee_getMonto(emplead,&monto);
            printf("%10d%15s%10d%7d%15f\n",id,nombre,nivel,cantProduc,monto);
            if(i==250 || i==500 || i==750)
            {
                system("pause");
            }
       }
       aux=1;
    }else{
        printf("No se encuentran datos cargados\n");
    }

    return aux;
}

int listaComisiones(LinkedList* pArrayListEmployee)
{

    int i=0;
    int aux=0;
    vendedor * emplead;
    printf("************LISTA EMPLEADOS******************* \n\n");
    printf("ID EMPLEADO\tNOMBRE\tHS nIvel cantProductos  monto  \n\n");
    emplead=ll_get(pArrayListEmployee,i);
    if(emplead != NULL){
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            emplead=ll_get(pArrayListEmployee,i);
            printf("%10d %15f\n",emplead->id,emplead->comision);
       }
       aux=1;
    }else{
        printf("No se encuentran datos cargados\n");
    }

    return aux;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    int aux=0;
    int opcion;
    printf("******** ORDENA LISTA ************\n");
    if(!ll_isEmpty(pArrayListEmployee)){

            while(aux!=5){

                    MuestraMenu("Ingrese por que campo desea ordenar la lista: \n1- ID\n2- Nombre\n3- Horas Trabajadas\n4- Sueldo\n5- Salir\n");
            do{
             opcion=getInt(&aux,"\n","El numero ingresado es invalido",1,5);
            }while(opcion!=0);
            switch(aux){

                case 1:
                    printf("Espere por favor mientras se realiza el ordenamiento...\n");
                        ll_sort(pArrayListEmployee,employee_sortID,0);
                    printf("Gracias por esperar. Se realizo el ordenamiento correctamente\n");
                    aux=5;
                    break;
                case 2:
                    printf("Espere por favor mientras se realiza el ordenamiento...\n");
                        ll_sort(pArrayListEmployee,employee_sortNombre,1);
                    printf("Gracias por esperar. Se realizo el ordenamiento correctamente\n");
                        aux=5;
                    break;
                case 3:
                    printf("Espere por favor mientras se realiza el ordenamiento...\n");
                        ll_sort(pArrayListEmployee,employee_sortHorasTrabajadas,0);
                    printf("Gracias por esperar. Se realizo el ordenamiento correctamente\n");
                    aux=5;
                    break;
                case 4:
                    printf("Espere por favor mientras se realiza el ordenamiento...\n");
                        ll_sort(pArrayListEmployee,employee_sortSueldo,0);
                    printf("Gracias por esperar. Se realizo el ordenamiento correctamente\n");
                    aux=5;
                    break;
                }
            }
        retorno=1;
    }else{

        printf("No se encuentran datos cargados\n");
        retorno=0;
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int i=0;
    int aux;
    int cantElementos;
    LinkedList* listaFiltrada;
    FILE* file;
    vendedor * emplead;
    int entrada;
    int id,nivel;
    char nombre[51];
    int cantProduc;
    float monto,comision;

    file=fopen(path,"w");
    if(file != NULL && (ll_len(pArrayListEmployee)!=0) ){

        getInt(&entrada," ingrese por que nivel desea filtrar: \n 0- junior\n 1- Estandard\n 2- Experto\n","dato incorrecto",0,2);

        if(entrada==0)
        {
            listaFiltrada=ll_filter(pArrayListEmployee,filtra0);
        }
        if(entrada==1)
        {
            listaFiltrada=ll_filter(pArrayListEmployee,filtra1);
        }
        if(entrada==2)
        {
            listaFiltrada=ll_filter(pArrayListEmployee,filtra2);
        }

        cantElementos=ll_len(listaFiltrada);
        fprintf(file,"ID,nombre,nivel,cantidad_productos,monto_vendido,comision\n");
        for(i=0;i<cantElementos;i++){
            emplead=ll_get(listaFiltrada,i);
            employee_getId(emplead,&id);
            employee_getNombre(emplead,nombre);
            employee_getNivel(emplead,&nivel);
            employee_getProd(emplead,&cantProduc);
            employee_getMonto(emplead,&monto);
            employee_getComision(emplead,&comision);
            aux=fprintf(file,"%d,%s,%d,%d,%f,%f\n",id,nombre,nivel,cantProduc,monto,comision);
       }
        printf("El archivo se salvo correctamente\n");
        ll_clear(listaFiltrada);
        ll_deleteLinkedList(listaFiltrada);
    }else{
        printf("No se encuentran datos cargados, o surgio un problema al guardar el archivo\n\n");
    }
    fclose(file);


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i=0;
    int aux;
    int cantElementos;
    FILE* file;
    vendedor * emplead;
    file=fopen(path,"wb");

    if(file != NULL && (ll_len(pArrayListEmployee)!=0) )
    {
        cantElementos=ll_len(pArrayListEmployee);
        for(i=0; i<cantElementos; i++)
        {
            emplead=ll_get(pArrayListEmployee,i);
            aux=fwrite(emplead,sizeof(vendedor),1,file);
        }
        printf("El archivo se salvo correctamente\n");
    }
    else
    {
        printf("No se encuentran datos cargados, o surgio un problema al guardar el archivo\n\n");
    }
    fclose(file);
    return 1;
}

int controller_listComisiones(LinkedList* lista)
{

    ll_map(lista,calculaComision);
    system("pause");
    listaComisiones(lista);
    return 0;
}
