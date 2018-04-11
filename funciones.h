#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

    /**
    *    \brief suma dos valores
    *    \param operador01 y operador02, son los que se van a sumar
    *    \return devuelve la suma de ambos
    */

    float sumar(float operador01, float operador02)
    {
        return operador01+operador02;
    }

    /**
    *    \brief resta dos valores
    *    \param operador01 y operador02, son los que se van a restar
    *    \return devuelve la resta de ambos
    */
    float restar(float operador01, float operador02)
    {
        return operador01-operador02;
    }

    /**
    *    \brief multiplica dos valores
    *    \param operador01 y operador02, son los que se van a multiplicar
    *    \return devuelve la multiplicacion de ambos
    */

    float multiplicar(float operador01, float operador02)
    {
        return operador01*operador02;
    }
    /**
    *    \brief divide dos valores
    *    \param operador01 y operador02, son los que se van a dividir
    *    \return devuelve la division de ambos
    */

    float dividir(float operador01, float operador02)
    {
        return operador01/operador02;
    }

    /**
    *    \brief Toma un valor y calcula su factorial
    *    \param operador es el numero al cual se le aplicara el factorial
    *    \return el factorial de operador
    */
    float factorial(float operador)
    {
        float respuesta;
        if(operador==1 || operador==0)
        return 1;
        respuesta=operador* factorial(operador-1);
        return (respuesta);
    }


    /**
    *    \brief Toma un valor y lo muestra
    *    \param mensaje Es el mensaje a mostrar
    *    \param resultado Es el valor a ser mostrado
    *    \return el valor de resultado
    */

    void muestraMensaje(char mensaje[], float resultado)
    {
        printf("%s%.2f \n", mensaje,resultado);
    }

    /**
    *    \brief toma un valor
    *    \param valorA es el que va a determinar si es entero o no
    *    \return 1 si es entero, 0 si es decimal
    */
    int esEntero(float valorA)
    {
        int x_entero = (int) valorA;


        if(valorA - x_entero) // Sobra 0.24 por lo que devuelve verdadero
        {
           return 0;
        }
        else
        {
            return 1;
        }
    }


#endif // FUNCIONES_H_INCLUDED


