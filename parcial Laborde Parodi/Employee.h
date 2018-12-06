#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int nivel;
    int cantidad_productos_vendidos;
    float monto_vendido;
    float comision;
}vendedor;

vendedor* employee_new();
vendedor* employee_newParametros(int* idStr,char * nombreStr,int* nivel, int * cantProductos, float * monto);
void employee_delete(vendedor * this);
int employee_sortNombre(void* empleado,void * empleado2);
int employee_sortID(void* empleado,void * empleado2);
int employee_sortHorasTrabajadas(void* empleado,void * empleado2);
int employee_sortSueldo(void* empleado,void * empleado2);
int employee_editEmploye(vendedor* empleado);


int employee_setId(vendedor* list,int id);
int employee_getId(vendedor* list,int * id);
int employee_getNombre(vendedor* list,char *nombre);
int employee_getNivel(vendedor* list,int * nivel);
int employee_getProd(vendedor* list,int * cant);
int employee_getMonto(vendedor* list,float * monto);
int employee_getComision(vendedor* list,float * comision);



int employee_setNombre(vendedor* list,char* nombre);


int employee_setHorasTrabajadas(vendedor* list,int horasTrabajadas);


int employee_setSueldo(vendedor* list,int sueldo);


int calculaComision(void* persona);
int filtra0(void* persona);
int filtra1(void* persona);
int filtra2(void* persona);

#endif // employee_H_INCLUDED
