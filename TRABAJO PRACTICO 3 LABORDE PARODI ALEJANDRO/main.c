#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTP3.h"
#define ARCHIVOBINARIO ".\\PeliculasBinario.dat"
#define ARCHIVOTEXTO ".\\PeliculasTexto.html"


int main()
{
    char seguir='s';
    int opcion=0;


    FILE*archivoBin;
    EMovie pelicula;

    if ((archivoBin=fopen(ARCHIVOBINARIO,"rb+"))==NULL)
    {
        if ((archivoBin=fopen(ARCHIVOBINARIO,"wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }

    while(seguir=='s')
    {
        imprimeMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                agregarPelicula(pelicula, archivoBin);
                break;

            case 2:
                borrarPelicula(archivoBin, pelicula);
                break;
            case 3:
                modificaPelicula(archivoBin, pelicula);
               break;
            case 4:
                generarPagina(archivoBin,pelicula);
                break;
            case 5:
                seguir = 'n';
                break;
            case 9:
                harcodeaPeliculas(pelicula,archivoBin);
                break;

        }
    }



    fclose(archivoBin);

    return 0;
}
