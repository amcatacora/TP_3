#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANT 3
#define INACTIVO 0
#define ACTIVO 1

/*
*Estructura de pelicula
*/
struct EPelicula{
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[50];
    int estado;
};

void listarPeliculas();

/*
*Funcion Menu
*/
void menu();

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int agregarPelicula(struct EPelicula* pelicula);

int ingresarPelicula();

int subirPelicula(struct EPelicula* pelicula);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(struct EPelicula* pelicula);

int mostrarPelicula(struct EPelicula* pelicula);

int buscarPeliculaPorTitulo(char* titulo);

#endif// FUNCIONES_H_INCLUDED
