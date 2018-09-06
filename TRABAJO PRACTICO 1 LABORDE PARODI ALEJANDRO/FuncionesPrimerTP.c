#include <stdio.h>
#include <stdlib.h>
#include "FuncionesPrimerTP.h"
#include <stdbool.h>



void MuestraMenu()
{
    printf( "3- Calcular todas las operaciones\n");
    printf( "4- Informar resultados\n");
    printf( "5- Salir\n");
}

int GetInt(char texto[], char error[], int minimo, int maximo)
{
    int valida=0;
    int numero;
    while(valida ==0 )
    {
        printf("%s \n",texto);
        setbuf(stdin,NULL);
        scanf("%d",&numero);

        if((numero<=minimo) || (numero>=maximo))
        {
            printf("%s \n ",error);
            printf("El numero ingresado tiene que estar entre %d y %d\n",minimo,maximo);
        }else
            {
                valida=1;
            }
    }
    return numero;

}

float Suma(float operando1, float operando2)
{
    return operando1+operando2;
}

float Resta(float operando1, float operando2)
{
    return operando1-operando2;
}

float Multiplica(float operando1, float operando2)
{
    return operando1*operando2;
}

int Divide(float * respuesta,float operando1, float operando2)
{
    if (operando2==0)
    {
        return 0;
    }else
        {
            *respuesta=operando1/operando2;
            return 1;
        }
}

float GetOperandoValido(char msg[],char msgError[])
{
    float operando;
    printf("%s",msg);
    if(scanf("%f",&operando))
        {
            return operando;
        }else
        {
            printf("%s\n",msgError);
            return 0;
        }
}


