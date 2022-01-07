#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    EMovie movie[CANT];
    init(movie);
    //struct Emovie p;
    //FUNCIONES PARA EL WHILE
    //char seguir='s';
    int opcion=0;

   do{
        system("cls");
        menu();
        opcion = getch();
        switch(opcion){
            case 49 : printf("Ingresar Peliculas: \n"); break;// tecla 1
            case 50 : printf("Borrar Peliculas: \n"); break;//tecla 2
            case 51 : printf("Mostrar Peliculas\n"); break;//tecla 3
            case 52 : printf("Generar pagina Web: \n"); break;//tecla 4
            /*case 53 : ;break;//tecla 5
            case 54 : ;break;//tecla 6
            case 55 : ;break;//tecla 7*/
        }

    }while(opcion != 53);//salir 8
}
