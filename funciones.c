#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"

//FUNCION INIT STRUCTURA
void init(EMovie movie[CANT]){
    for (int i = 0; i < CANT; i++)
    {
        strcpy(movie[i].titulo,"");
        strcpy(movie[i].genero,"");
        movie[i].duracion = 0 ;
        strcpy(movie[i].descripcion,"");
        movie[i].puntaje = 0 ;
        strcpy(movie[i].linkImagen,"");
    }
    
}
//FIN FUNCION INIT STRUCT

//FUNCION MENU
void menu(){
    printf("******************************\n");
    printf("**                          **\n");
    printf("**    Menu principal        **\n");
    printf("**                          **\n");
    printf("** 1- Agregar pelicula      **\n");
    printf("** 2- Borrar pelicula       **\n");
    printf("** 3- Mostrar peliculas     **\n");
    printf("** 4- Generar pagina web    **\n");
    printf("** 5- Salir                 **\n");
    printf("**                          **\n");
    printf("******************************\n");
}
//FIN FUNCION MENU

//FUNCION AGREGAR PELICULA

//int agregarPelicula(EMovie movie){}

//FIN FUNCION AGREGAR

//int mostrarPeliculas(EMovie movie){}