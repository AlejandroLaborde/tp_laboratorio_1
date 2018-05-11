#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;


}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int BuscaEspacioLibre(EPersona lista[],int cantidad);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], long int dni, int cantidad);

/** \brief Imprime por pantalla una lista de array
 *
 * \param   EPersona lista que se pasa por parametro
 * \param cantidad de elementos en el array
 * \return void
 */
void imprimeLista(EPersona lista[],int cantidad);

/** \brief elimina una persona del array
 *
 * \param lista[] EPersona lista que se pasa por parametro
 * \param posicion int lugar donde se encuentra el elemento a borrar00
 * \return void
 *
 */
void BorrarPersona(EPersona lista[],int posicion);

/** \brief imprime un grafico de barras de las edades
 *
 * \param lista[] EPersona lista que se pasa por parametro
 * \param cantidad int cantidad de elementos en el array
 * \return void
 *
 */
void GraficaEdades(EPersona lista[],int cantidad);

/** \brief alta de una persona
 *
 * \param Lista[] EPersona  lista que se pasa por parametro
 * \param posicion int posicion donde va a cargar
 * \return void
 *
 */
void CargaPersona(EPersona Lista[],int posicion);

/** \brief Busca espacio libre en el array
 *
 * \param lista[] EPersona lista que se pasa por parametro
 * \param cantidad int cantidad de elementos del array
 * \return int posicion libre
 *
 */
int obtenerEspacioLibre(EPersona lista[],int cantidad);

/** \brief ordena array
 *
 * \param lista[] EPersona lista que se pasa por parametro
 * \param cantidad int cantidad de elementos del array
 * \return void
 *
 */
void ordenaStruct(EPersona lista[],int cantidad);

void imprimeMenu();

void inicializaMatriz(EPersona lista[],int canridad);

int validaCadenaAlpha(char cadena[]);

#endif // FUNCIONES_H_INCLUDED

