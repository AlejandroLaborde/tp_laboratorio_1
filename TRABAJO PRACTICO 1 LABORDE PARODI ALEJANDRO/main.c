#include <stdio.h>
#include <stdlib.h>
#include "FuncionesPrimerTP.h"
#include <stdbool.h>


float factorial(float operador);
int main()
{
    int opcion,division;
    float operando1=0;
    float operando2=0;
    float suma,resta,multiplicacion,resultadoDivision;
    float factorialR,factorialR2;



    do
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",operando1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",operando2);
        MuestraMenu();

        opcion=GetInt("Ingrese una Opcion:", "La opcion ingresada es incorrecta.",0,6);

        switch(opcion)
            {
                case 1:
                    system("cls");
                    operando1=GetOperandoValido("Ingrese el primer operando: ","El numero ingresado es incorrecto ");
                    break;
                case 2:
                    system("cls");
                    operando2=GetOperandoValido("Ingrese el segundo operando: ","El numero ingresado es incorrecto ");
                    break;
                case 3:
                    system("cls");
                    suma=Suma(operando1,operando2);
                    resta=Resta(operando1,operando2);
                    multiplicacion=Multiplica(operando1,operando2);
                    division=Divide(&resultadoDivision,operando1,operando2);
                    factorialR=factorial(operando1);
                    factorialR2=factorial(operando2);
                    printf("Se realizaron todas las operaciones \n");

                    break;
                case 4:
                    system("cls");
                    printf("El resultado de A+B es: %.2f \n",suma);
                    printf("El resultado de A-B es: %.2f\n",resta);
                    if(division==1)
                        {
                            printf("El resultado de A/B es: %.2f\n",resultadoDivision);
                        }else
                        {
                            printf("No se puede devidir por 0\n");
                        }

                    printf("El resultado de A*B es: %.2f\n",multiplicacion);
                    printf("El factorial de A es: %.2f y El factorial de B es: %.2f” \n",factorialR,factorialR2);
                    system("pause");
                    system("cls");

                    break;
                case 5:
                    system("pause");

                    break;

            }

    }while(opcion != 5);

  return 0;

 }


float factorial(float operador)
    {
        float respuesta;
        if(operador==1 || operador==0)
        return 1;
        respuesta=operador* factorial(operador-1);
        return respuesta;
    }

