#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int isOk=0;
    int auxScan;
    int id;
    char nombre[128];
    int nivel,cantProductos;
    float monto;
    vendedor* empleado;

    if(pFile != NULL ){
       auxScan=fscanf(pFile,"%[^\n]\n",nombre);
        system("pause");
        do{
            auxScan=fscanf(pFile,"%d,%[^,],%d,%d,%f\n",&id,nombre,&nivel,&cantProductos,&monto);
            if(auxScan == 5){

                empleado=employee_newParametros(&id,nombre,&nivel,&cantProductos,&monto);
                ll_add(pArrayListEmployee,empleado);
                 isOk = 1;

            }
        }while(!feof(pFile));
    }
   // sueldo=ll_len(pArrayListEmployee);
    //printf("%d",sueldo);
    return isOk;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int aux;
    vendedor * empleado;

    while(pFile!=NULL){
             aux= fread(empleado,sizeof(vendedor),1,pFile);
             if(aux==1){
                    empleado=employee_newParametros(empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
                    ll_add(pArrayListEmployee,empleado);
             }else
             {
                 if(feof(pFile))
                 {
                     break;
                 }
             }
    }

    return 1;
}
*/
