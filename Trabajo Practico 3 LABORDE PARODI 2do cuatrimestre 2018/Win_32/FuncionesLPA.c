#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


void MuestraMenu(char texto[])
{
    printf("%s",texto);
}

void MenuPrincipal(){
        system("cls");
        printf("*********************** Menu Principal *************************\n\n\n");
        MuestraMenu("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        MuestraMenu("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        MuestraMenu("3. Alta de empleado\n");
        MuestraMenu("4. Modificar datos de empleado\n");
        MuestraMenu("5. Baja de empleado\n");
        MuestraMenu("6. Listar empleados\n");
        MuestraMenu("7. Ordenar empleados\n");
        MuestraMenu("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        MuestraMenu("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        MuestraMenu("10. Salir\n\n");
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
}
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    int numInput;
    do{
        printf("%s\n",message);
        setbuf(stdin,NULL);
    }while(!scanf("%d",&numInput));

    if( (numInput<lowLimit) ||  (numInput>hiLimit) )
    {
        printf("%s\n",eMessage);
        return -1;
    }
        *input = numInput;
        return 0;
}
int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit){
    int retorno = 0;
    printf("%s", message);
    setbuf(stdin, NULL);
    gets(input);
    int largo;
    largo=strlen(input);

    if (largo >= hiLimit || largo < lowLimit )
    {
        printf("%s",eMessage);
        retorno = -1;
    }
    return retorno;

}
