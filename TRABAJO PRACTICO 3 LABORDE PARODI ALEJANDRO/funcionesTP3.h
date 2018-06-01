#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
    int estado;
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie pelicula, FILE * archivoBin);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(FILE*archivoBin,EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(FILE * archivoBin,EMovie pelicula);

void imprimeCabezeraTXT(FILE *archivoTexto);
void imprimeCuerpoTXT(FILE *archivoTexto,EMovie pelicula);
void imprimeFinalTXT(FILE *archivoTexto);
void imprimeLista(FILE*archivoBin,EMovie pelicula);

int  modificaPelicula(FILE *archivoTexto,EMovie pelicula);

void harcodeaPeliculas(EMovie pelicula, FILE *archivoBinario);

void imprimeMenu();
void imprimeMenuModificar();

void imprime(char texto[1000]);
#endif // FUNCIONES_H_INCLUDED
