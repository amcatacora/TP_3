#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"

void menu(){
    printf("******************************\n");
    printf("**                          **\n");
    printf("**    Menu principal        **\n");
    printf("**                          **\n");
    printf("** 1- Agregar pelicula      **\n");
    printf("** 2- Borrar pelicula       **\n");
    printf("** 3- Modificar pelicula    **\n");
    printf("** 4- Generar pagina web    **\n");
    printf("** 5- Salir                 **\n");
    printf("**                          **\n");
    printf("******************************\n");
};

void listarPeliculas(){
    FILE *bin;
    struct EPelicula pelicula;
    int cant;
    if ((bin=fopen("peliculas.dat","rb"))==NULL){
        printf("\nNo se encontraron peliculas guardadas.\n");
        //exit(1);
    } else {
        printf("\nListado de peliculas:\n\n");
        while(!feof(bin)){
            cant=fread(&pelicula,sizeof(pelicula),1,bin);

            if(cant!=1){
                if(feof(bin))
                    break;
                else{
                    printf("No leyo el ultimo registro");
                    break;
                }
            }
            if(pelicula.estado == ACTIVO) {
                printf("%s\t%d\n", pelicula.titulo, pelicula.duracion);
            }
        }
    }
    fclose(bin);
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int ingresarPelicula() {
    struct EPelicula pelicula;
    system("cls");
    printf("Ingrese los datos de la pelicula a agregar\n");
    getString("Titulo: ", pelicula.titulo);
    getString("Genero: ", pelicula.genero);
    pelicula.duracion = getInt("Duracion: ");
    getString("Descripcion: ", pelicula.descripcion);
    pelicula.puntaje = getInt("Puntaje: ");
    getString("Link Imagen: ", pelicula.linkImagen);
    pelicula.estado = ACTIVO;

    agregarPelicula(&pelicula);
    return 1;
}

int agregarPelicula(struct EPelicula* pelicula){
    FILE* fp;
    fp=fopen("peliculas.dat","ab+");
    if(fp==NULL){
        printf("Error opening file");
        return 0;
    }
    fwrite(pelicula,sizeof(struct EPelicula),1,fp);
    fclose(fp);
    return 1;
}

int buscarPeliculaPorTitulo(char* titulo){
    FILE* fp;
    fp=fopen("peliculas.dat","rb");
    if(fp==NULL){
        printf("Error opening file");
        return NULL;
    }
    int pos = ftell (fp);
    int indice = -1;
    struct EPelicula* pRet = malloc(sizeof(struct EPelicula));
    int flagFound = 0;
    while(fread(pRet,sizeof(struct EPelicula),1,fp)!=0) {
        printf("%s %d\r\n",
               pRet->titulo,
               pRet->duracion);
        pos = ftell (fp);
        //printf("Posicion %d - > ", pos/(sizeof(struct EPelicula)));

        indice = pos/(sizeof(struct EPelicula));

        if(strcmp(titulo, pRet->titulo)==0){
            flagFound=1;
            break;
        }
    }
    fclose(fp);

    if(flagFound)
        return indice;
    free(pRet);
    return NULL;
};
