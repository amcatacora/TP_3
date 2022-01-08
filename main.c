#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    int opcion=0;

    do{
        system("cls");
        menu();
        listarPeliculas();
        opcion = getch();
        switch(opcion){
            case 49 : ingresarPelicula(); break;// tecla 1
            case 50 : {
                char titulo[64];
                getString("Ingrese el titulo a buscar en archivo: ", titulo);
                int indice = buscarPeliculaPorTitulo(titulo);
                if(indice >= 0){
                    printf("Se encontro: %s\r\n", titulo);
                    printf("Esta seguro que desea borrar esta pelicula?");
                }
                else {
                    printf("el titulo ingresado no esta en el archivo");
                }
                getch();
            }
            break;//tecla 2

            case 51 : printf("Mostrar Peliculas\n"); break;//tecla 3
            case 52 : printf("Generar pagina Web: \n"); break;//tecla 4
        }
    }while(opcion != 53);//salir 5
}
