#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void modifica(Employee * list ,int len,int indice);
int printEmploye(Employee list);
void informa(Employee* list,int CANT);
void downEmployed(Employee*list,int leng);
int initEmployees(Employee* list, int len);
int modifyEmployed(Employee* list,int CANT);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeById(Employee* list, int len,int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int searchFree(Employee* list,int CANT);
int upEmployed(Employee* list,int CANT);
void MuestraMenu();
void initializeStruct(Employee empleados[],int CANT);
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage[], int lowLimit, int hiLimit);
void ordena(Employee* list,int CANT);


#endif // FUNCIONES_H_INCLUDED
