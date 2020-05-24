#include "FuncionesCC.h"
#include <stdio.h>


int main( ){
   int opcion, numPisos, numLocales, i, j, contador;
   local_t ** centroComercial;
   printf( "Ingresa el numero de pisos para tu Centro Comercial\n" );
   scanf("%d", &numPisos);
   printf( "Ingresa el numero de locales por piso para tu Centro Comercial\n" );
   scanf("%d", &numLocales);
   centroComercial = disenarCentroComercial(&numPisos, &numLocales);
   printf("Has diseñado tu centro comercial con exito! En el menú podrás administrar tu centro comercial\n");
   
   
   do{
      
      opcion = menu( );
      switch(opcion){
         
         case 1:
            agregarLocal( numPisos, numLocales, centroComercial);
            break;
         
         case 2:
            mostrarLocales( numPisos, numLocales, centroComercial );
            break;

         case 3:
            eliminarLocal( numPisos, numLocales,centroComercial );
            break;

         case 4:
            cambiarNombreLocal( centroComercial, numPisos, numLocales );
            break;

         case 5:
            verLocalesSinArrendar( centroComercial, numPisos, numLocales );
            break;

         case 6:
            contarLocalesDisponibles( numPisos, numLocales, i, j, contador, centroComercial );
            break;

      }
   
   }while(opcion!= 7);

	return 0;
}
