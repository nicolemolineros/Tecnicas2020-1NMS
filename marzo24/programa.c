#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persona{
    char nombre[ 15 ]; // Luisa: no estas usando en tu programa el nombre 
    int dia, mes, agnio;
}persona;



int menu(){
   int opc;
   printf( "\n PROGRAMA CLASE MARZO 24 \n" );
   printf( "============================\n" );
   printf( "1 Agregar persona\n " );
   printf( "2 Mostrar personas del mes\n" );
   printf( "3 Saber que numero es el mes\n" );
   printf( "0 Salir\n" );
   printf( "Opcion: \n" );
   scanf( "%d", &opc );
   
   return opc;
   
}

// Creo que falta el resto...
