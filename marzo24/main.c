#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum mesAn{Ene = 1, Feb, Mar, Abr, May, Jun, Jul,  
          Ago, Sep, Oct, Nov, Dec};

typedef struct persona{
    char nombre[ 10 ];
    int dia, mes, agnio;
}persona;


int menu( ){
   int opc;
   printf( "\n PROGRAMA CLASE MARZO 24 \n" );
   printf( "============================\n" );
   printf( "1 Agregar persona\n " );
   printf( "2 Mostrar personas del mes\n" );
   printf( "3 opcion 1 recursion\n" );
   printf( "3 opcion 2 recursion, enums, ciclo\n" );
   printf( "0 Salir\n" );
   printf( "Opcion: \n" );
   scanf( "%d", &opc );
   
   return opc;
   
}


int main( ){
   int agnio, mes, dia, i, j, opc;
   char nombre[ 15 ];
   int n = 0;
   persona h[12][5];

   do{
       opc = menu( );
       switch ( opc ){


       
       case 1: fflush( stdin );
               printf( "Nombre: \n");
               scanf( "%s", nombre);
               printf( "Mes de nacimiento: \n" );
               scanf( "%d", &mes);
               printf( "Dia de nacimiento: \n" );
               scanf( "%d", &dia);
               printf( "Año de nacimiento: \n" );
               scanf( "%d", &agnio );

               for( j = 0; j < 5; j++){
               	if( h[mes-1] [j].mes == -1 ){
               		n = 1;
               		strcpy(h[mes-1][j].nombre, nombre);
               		h[ mes-1 ] [j].mes = mes;
               		h[ mes-1 ] [j].dia = dia;
               		h[ mes-1 ] [j].agnio = agnio;
               		break;
               	}
               }
               if( n == 0 ){
               	printf( "No hay espacio suficiente para su mes, sorry" );
               }
               break;

       case 2: printf( "Ingrese el numero de mes que desea consultar" );
               scanf( "%d", &mes);

               for( j = 0; j < 5; j++ ){
               	if( h[mes-1] [j].mes > 0){
               		printf( "El cumpleañero es: \n" );
               		printf( "Nombre: %s", h[mes-1][j].nombre );
               		printf( "Fecha de nacimiento: %d %d %d", h[ mes-1 ] [j].mes, h[ mes-1 ] [j].dia, h[ mes-1 ] [j].agnio );
               	}
               }
       case 3: printf( "Ingrese el mes: \n");
               for ( i=Ene; i <= Dec; i++ )      
                  printf( "%d ", i ); 
}
   }while( opc != 0 );




    return 0;
}