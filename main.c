#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <stdbool.h>


int main()
{
    char seguir='s';
    int opcion;
    float valorA=0;
    float valorB=0;
    float resultado=0;



    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",valorA);
        printf("2- Ingresar 2do operando (B=%.2f)\n",valorB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones \n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        if (opcion<1 || opcion>9)
        {
            printf("El valor ingresado es incorrecto \n");
        }else
        {
            switch(opcion)
            {
                case 1:
                    system("cls");
                    printf("INGRESE VALOR \n");
                    scanf("%f",&valorA);
                    break;
                case 2:
                    system("cls");
                    printf("INGRESE VALOR \n");
                    scanf("%f",&valorB);
                    break;
                case 3:
                    system("cls");
                    resultado=sumar(valorA,valorB);
                    muestraMensaje("La suma es: ",resultado);
                    break;
                case 4:
                    system("cls");
                    resultado=restar(valorA,valorB);
                    muestraMensaje("La resta es: ",resultado);
                    break;
                case 5:
                    system("cls");
                    if(valorB==0)
                    {
                        printf("No se puede realizar la division ya que el valor del segundo numero es cero \n");
                    }else
                    {
                        resultado=dividir(valorA,valorB);
                        muestraMensaje("La division es: ",resultado);
                    }
                    break;
                case 6:
                        system("cls");
                        resultado=multiplicar(valorA,valorB);
                        muestraMensaje("La multiplicacion es: ",resultado);
                    break;
                case 7:
                    system("cls");
                    if(valorA<0 || !esEntero(valorA) )
                    {
                        printf("No se puede realizar el factorial ya que el valor es negativo o el numero contiene decimales \n");
                    }else
                    {
                        resultado=factorial(valorA);
                        muestraMensaje("el factorial es : ",resultado);
                    }

                    break;
                case 8:
                    system("cls");
                    resultado=sumar(valorA,valorB);
                    muestraMensaje("La suma es: ",resultado);// suma

                    resultado=restar(valorA,valorB);
                    muestraMensaje("La resta es: ",resultado);//resta

                    if(valorB==0)
                    {
                        printf("No se puede realizar la division ya que el valor del segundo numero es cero");
                    }else
                    {
                        resultado=dividir(valorA,valorB);
                        muestraMensaje("La division es: ",resultado);
                    }//divide

                    resultado=multiplicar(valorA,valorB);
                    muestraMensaje("La multiplicacion es: \n ",resultado);//multiplica

                    if(valorA<0)
                    {
                        printf("No se puede realizar el factorial ya que el valor es negativo \n");
                    }else
                    {
                        resultado=factorial(valorA);
                         muestraMensaje("el factorial es : ",resultado);
                    }//factorea

                    break;

                case 9:
                    system("cls");
                    seguir = 'n';
                    break;
            }
        }
     }

    return 0;
}


