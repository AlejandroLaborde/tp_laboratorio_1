#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void MuestraMenu();

int GetInt(char texto[], char error[], int minimo, int maximo);

float Suma(float operando1, float operando2);

float Resta(float operando1, float operando2);

float Multiplica(float operando1, float operando2);

int Divide(float * respuesta, float operando1, float operando2);

float GetOperandoValido(char msg[],char msgError[]);

float factorial(float operador);


#endif // FUNCIONES_H_INCLUDED
