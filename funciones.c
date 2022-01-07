#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"

//FUNCION INIT STRUCTURA
void init(EMovie movie[CANT]){
    for (int i = 0; i < CANT; i++){

        strcpy(movie[i].titulo,"");
        strcpy(movie[i].genero,"");
        movie[i].duracion = 0 ;
        strcpy(movie[i].descripcion,"");
        movie[i].puntaje = 0 ;
        strcpy(movie[i].linkImagen,"");
    }
}

//FUNCION LEER/CREAR PELICULAS.DAT
void leer (){
    FILE *bin;
    struct Emovie pelis;
    int cant;
    if ((bin=fopen("Peliculas.dat","rb"))==NULL){
        printf("No se puede abrir el archivo");
        exit(1);
    }

    while (!feof(bin)){
        cant=fread(&pelis,sizeof(pelis),1,bin);

        if (cant!=1){

            if (feof(bin)){
                break;
            }
            else{
                printf("No se leyo el registro o el ultimo registro");
            }
        }
        printf("Titulo: %s \nGenero: %s \nDuracion: %d \nDescripcion: %s \nPuntaje: %d \n",
        pelis.titulo,
        pelis.genero,
        pelis.duracion,
        pelis.descripcion,
        pelis.puntaje);
    }

};



//FIN DE LA FUNCION LEER/CREAR

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
};
//FIN FUNCION MENU

//FUNCION AGREGAR PELICULA

int agregarPelicula (struct Emovie* p){
    char loop ='s';
    while (loop=="s"){

        system("cls");
        leer();

        ingresarPelicula(&p);
        agregarPelicula(&p);

        loop= printf("Ingresar otra pelicula? s/n: ");
    }
};

int ingresarPelicula(struct Emovie* p){
    printf("Ingrese el nombre de la pelicula: \n", p->titulo);
    printf("Ingrese el genero de la pelicula:  \n", p->genero);
    p->duracion = printf("Ingrese la duracion: \n");
    printf("Ingrese descripcion: \n",p->descripcion);
    p->puntaje = printf("Ingrese el puntaje: \n");
};

int subirPelicula(struct Emovie* p){
    FILE* fp;
    fp=fopen("Peliculas.dat","ab+");
    if (fp == NULL){
        printf("Error al abrir el archivo :(");
        return 0;
    }
    fwrite(p,sizeof(struct Emovie),1,fp);
    fclose(fp);
    return 1;
};
//FIN FUNCION AGREGAR

//FUNCIONES GETS
/*
void getString(char mensaje[],char input[]){
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getInt(char* mensaje){
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char* mensaje){
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

*/
//int mostrarPeliculas(EMovie movie){}
