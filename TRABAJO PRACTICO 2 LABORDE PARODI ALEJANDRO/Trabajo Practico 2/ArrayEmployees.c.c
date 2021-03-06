#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h.h"
#include <ctype.h>
#include <string.h>

int IDautoincremental(Employee * list, int len)
{

    int id=1000;
    int i;
    for(i=0 ; i<len ; i++){

        if(list[i].id>id && list[i].isEmpty==1)
        {
            id=list[i].id;
        }
    }
    return id+1;

}
void MuestraMenu(char texto[])
{
    printf("%s",texto);
}

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int numInput;
    do{
        printf("%s\n",message);
        setbuf(stdin,NULL);
    }while(!scanf("%d",&numInput));

    if( (numInput<lowLimit) ||  (numInput>hiLimit) )
    {
        printf("%s\n",eMessage);
    }


   /* do{
        printf("%s\n",message);
        setbuf(stdin,NULL);
    }while(!scanf("%d",&numInput));
    if( (numInput<lowLimit) ||  (numInput>hiLimit) ){
        printf("%s\n",eMessage);
        }
*/
        *input = numInput;
        return 0;

}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int i;
    if(len>1000 || len<1){
        return -1;
    }else{
        for(i=0;i<len;i++){
        list[i].isEmpty=0;
        }
    }
    return 0;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 **/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    list[id].id=IDautoincremental(list,len);
    list[id].isEmpty=1;
    list[id].salary=salary;
    list[id].sector=sector;
    strcpy(list[id].name,name);
    strcpy(list[id].lastName,lastName);
    printf("El empleado se cargo correctamente\n");
    system("pause");
    system("cls");

 return 0;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    for(i=0; i<len; i++){
        if(list[i].id==id)
        {
            return i;
            break;
        }
    }
    return 0;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int idEliminar;
    idEliminar=findEmployeeById(list,len,id);
    list[idEliminar].isEmpty=0;
 return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int i;
    int indice=0;
    Employee auxiliar;
    int j;
    for(i=0;i<len;i++){
        if(list[i].isEmpty==1)
         indice=1;
        break;
    }
    if(indice!=1)
    {
        printf("NO EXISTEN EMPLEADOS CARGADOS\n");
        return -1;
    }else{

      for(i=0 ; i<len-1 ; i++)
        {
            for(j=i+1; j<len ; j++)
            {
                if((list[j].sector < list[i].sector) && (list[j].isEmpty==1) && (list[i].isEmpty==1))
                {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                }else{
                    if((strcmp(list[j].name,list[i].name)<0) && (list[j].sector == list[i].sector))
                    {
                    auxiliar=list[i];
                    list[i]=list[j];
                    list[j]=auxiliar;
                    }

                }
            }printf("%d",list[i].isEmpty);
        }

        printEmployees(list,len);


    return 0;
    }
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length)
{
    int i;
    printf("   ID     NOMBRE        APELLIDO       SALARIO            SECTOR \n");
    for(i=0;i<length;i++){
        printEmploye(list[i]);
        }
 return 0;
}

int printEmploye(Employee list)
{

    if(list.isEmpty==1){
    printf("%5d %10s %15s %12.2f %16d\n",list.id,list.name,list.lastName,list.salary,list.sector);
    }


 return 0;
}


int searchFree(Employee* list,int CANT){
    int i;
    for(i=0;i<CANT;i++){
            if(list[i].isEmpty==0){
            return i;
            break;
        }
    }
    return -1;
}


int upEmployed(Employee* list,int CANT){
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int indice;
    int retorno;

    indice = searchFree(list,CANT);
    if(indice==-1)
    {
        return indice;
    }else{
        printf("Ingrese nombre: ");
        setbuf(stdin,NULL);
        gets(name);
        printf("Ingrese apellido: ");
        setbuf(stdin,NULL);
        gets(lastName);
        do{
           retorno=getFloat(&salary,"ingrese salario: ","El numero tiene que ser mayor a [ 0 ] )",0,9999999);
        }while(retorno==-1);

        printf("Ingrese sector: ");
        scanf("%d",&sector);

        id=indice;

        addEmployee(list,CANT,id,name,lastName,salary,sector);
         return 0;
    }

}
int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit){


float numInput;
    do{
        printf("%s\n",message);
        setbuf(stdin,NULL);
    }while(!scanf("%f",&numInput));

    if( (numInput<lowLimit) ||  (numInput>hiLimit) )
    {
        printf("%s\n",eMessage);
        return -1;
    }
    else{
        *input = numInput;
        return 0;
    }


   /* do{
        printf("%s\n",message);
        setbuf(stdin,NULL);
    }while(!scanf("%d",&numInput));
    if( (numInput<lowLimit) ||  (numInput>hiLimit) ){
        printf("%s\n",eMessage);
        }
*/


}

int modifyEmployed(Employee* list,int CANT){

    int indice;
    int i;
    for(i=0;i<CANT;i++){
        if(list[i].isEmpty==1)
         indice=1;
        break;
    }
    if(indice!=1)
    {
        printf("NO EXISTEN EMPLEADOS CARGADOS\n");
    }else{
        printEmployees(list,CANT);
        printf("Ingrese el Id del empleado que desea Modificar\n");
        scanf("%d",&indice);

        for(i=0;i<CANT;i++){
            if(list[i].id==indice){
                modifica(list,CANT,indice);
                break;
            }
        }

}
    return 0;
}

void modifica(Employee * list ,int len,int indice)
{
    system("cls");
    char nombre[50];
    int opcion;
    int id;
    float salario;
    int sector;

    id=findEmployeeById(list,len,indice);
    MuestraMenu("1- NOMBRE\n2-APELLIDO\n3-SALARIO\n4-SECTOR\n5-SALIR\n");
    getInt(&opcion,"ingrese la opcion segun el dato que desee modificar: ","La opcion ingresada es incorrecta",1,5);
    switch(opcion){
        case 1:
            printf("\nINGRESE NUEVO NOMBRE:");
            setbuf(stdin,NULL);
            scanf("%s",nombre);
            strcpy(list[id].name,nombre);
        break;
        case 2:
            printf("\nINGRESE NUEVO APELLIDO:");
            setbuf(stdin,NULL);
            scanf("%s",nombre);
            strcpy(list[id].lastName,nombre);
        break;
        case 3:
            printf("\nINGRESE NUEVO SALARIO:");
            scanf("%f",&salario);
            list[id].salary=salario;
        break;
        case 4:
            printf("\nINGRESE NUEVO sector:");
            scanf("%d",&sector);
            list[id].sector=sector;
        break;
        case 5:
        break;

    }



}

void downEmployed(Employee*list,int leng){

    int idEliminar;

    int indice;
    int i;
    for(i=0;i<leng;i++){
        if(list[i].isEmpty==1)
         indice=1;
        break;
    }
    if(indice!=1)
    {
        printf("NO EXISTEN EMPLEADOS CARGADOS\n");
    }else{
    printEmployees(list,leng);
    printf("Ingrese el numero de ID segun la persona que desee eliminar");
    scanf("%d",&idEliminar);
    removeEmployee(list,leng,idEliminar);
    }
}

void informa(Employee* list,int CANT){

    int i;
    int indice;
    float sumaSalario=0;
    int cantidadEmpleados=0;
    float promedioSalarios;
    int superaPromedio=0;

    for(i=0;i<CANT;i++){
        if(list[i].isEmpty==1)
         indice=1;
        break;
    }
    if(indice!=1)
    {
        printf("NO EXISTEN EMPLEADOS CARGADOS\n");
    }else{

    for(i=0;i<CANT;i++){
        if(list[i].isEmpty==1){
         sumaSalario+=list[i].salary;
         cantidadEmpleados++;
         }
    }
    promedioSalarios=(sumaSalario/cantidadEmpleados);

    for(i=0;i<CANT;i++){
        if(list[i].isEmpty==1 && (promedioSalarios<list[i].salary)){
         superaPromedio++;
         }
    }

    printf("La suma total de salarios es: %.2f\n",sumaSalario);
    printf("El promedio de salarios es: %.2f\n",promedioSalarios);
    printf("%d empleados superan el salario promedio\n",superaPromedio);

    }

}
