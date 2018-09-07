#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void MuestraMenu();

/** \brief Obtiene un entero
 *
 * \param texto[] char mensaje a mostrar
 * \param error[] char mensaje de error
 * \param minimo int
 * \param maximo int
 * \return int devuelve el numero obtenido
 *
 */
int GetInt(char texto[], char error[], int minimo, int maximo);

/** \brief suma dos numeros
 *
 * \param operando1 float
 * \param operando2 float
 * \return float la suma de los numeros
 *
 */
float Suma(float operando1, float operando2);
/** \brief resta dos numeros
 *
 * \param
 * \param
 * \return devuelve la resta
 *
 */

float Resta(float operando1, float operando2);

/** \brief multiplica 2 numeros
 *
 * \param operando1 float
 * \param operando2 float
 * \return float devuelve la multiplicacion
 *
 */
float Multiplica(float operando1, float operando2);
/** \brief  realiza la division de dos numeros
 *
 * \param  respuesta, aca guarda el valor
 * \param
 * \return 0 si el seg numero es un 0, 1 si esta bien la operacion
 *
 */

int Divide(float * respuesta, float operando1, float operando2);

float GetOperandoValido(char msg[],char msgError[]);

float factorial(float operador);


#endif // FUNCIONES_H_INCLUDED
