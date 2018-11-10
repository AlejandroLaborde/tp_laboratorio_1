#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int * idStr,char* nombreStr,int * horasTrabajadasStr,int * sueldo);
void employee_delete(Employee * this);
int employee_sortNombre(void* empleado,void * empleado2);
int employee_sortID(void* empleado,void * empleado2);
int employee_sortHorasTrabajadas(void* empleado,void * empleado2);
int employee_sortSueldo(void* empleado,void * empleado2);
int employee_editEmploye(Employee* empleado);


int employee_setId(Employee* list,int id);
int employee_getId(Employee* list,int* id);

int employee_setNombre(Employee* list,char* nombre);
int employee_getNombre(Employee* list,char* nombre);

int employee_setHorasTrabajadas(Employee* list,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* list,int* horasTrabajadas);

int employee_setSueldo(Employee* list,int sueldo);
int employee_getSueldo(Employee* list,int* sueldo);

#endif // employee_H_INCLUDED
