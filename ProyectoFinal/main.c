#include "FuncionesCC.h"
#include <stdio.h>

int main( ){
   srand( time( NULL ) );
   int opcion, numPisos, numLocales, i, j, contador, archivoCargado, pisoOrdenado;
   char archivo[35];
   char nombreCentroComercial[35];
   local_t ** centroComercial;
   
   do{
		printf( "[1] Crear Centro Comercial\n" );
		printf( "[2] Centro Comercial existente\n" );
		printf( "==> "); 
      scanf( "%d", &opcion );
	}while( opcion != 1 && opcion != 2 );
	
	if( opcion == 2 ){
		do{
			printf( "Ingrese el nombre del archivo existente: " ); 
         scanf( "%s", archivo );
			archivoCargado = archivoExistente( centroComercial, archivo );
			if( archivoCargado == 0 ){
				printf( "El archivo no existe\n" );
				printf( "Ingrese la opción 1 o 2\n" );
				printf( "==>" ); 
            scanf("%d", &opcion );
				if( opcion == 1 ){
					goto CREAR;
				}
			}
		}while( archivoCargado == 0 );
	}else{
	CREAR:
   printf( "Nombre del centro comercial: " ); 
   scanf( "%s", nombreCentroComercial );
   printf( "Ingresa el numero de pisos para tu Centro Comercial\n" );
   scanf( "%d", &numPisos );
   printf( "Ingresa el numero de locales por piso para tu Centro Comercial\n" );
   scanf( "%d", &numLocales );
   centroComercial = disenarCentroComercial( &numPisos, &numLocales );
   printf( "Has diseñado tu centro comercial con exito! En el menú podrás administrar tu centro comercial\n" );
   printf( "Archivo del centro comercial: %s\n", archivo );
   strcpy( archivo, nombreCentroComercial );
	strcat( archivo, ".txt" );
   printf("===================================================================================\n");
   }
   int arreglo[numLocales];
   do{
      
      opcion = menu( );
      switch(opcion){
         
         case 1:
            agregarLocal( numPisos, numLocales, &centroComercial);
            break;
         
         case 2:
            mostrarLocales( numPisos, numLocales, &centroComercial );
            break;

         case 3:
            cambiarNombreLocal( numPisos, numLocales, &centroComercial );
            break;

         case 4:
            eliminarLocal( numPisos, numLocales, &centroComercial );
            break;

         case 5:
            verLocalesSinArrendar( numPisos, numLocales, &centroComercial );
            break;

         case 6:
            contarLocalesDisponibles( numPisos, numLocales, i, j, contador, centroComercial );
            break;

         case 7:
            definirStockALocal( numPisos, numLocales, centroComercial );
            break;

         case 8:
            marcarLocalEnDeuda( numPisos, numLocales, centroComercial);
            break;

         case 9: 
           ordenarIdLocal( centroComercial, arreglo, pisoOrdenado, numLocales);
           break;
         
         case 10:
            mergeSort( arreglo, numLocales);
            break;

         case 11:
            Quicksort( arreglo, numLocales);
            break;
         
         case 12:
            insertionSort( arreglo, numLocales);
            break;
         
         case 13:
            bubbleSort( arreglo, numLocales);
            break;
      }
   
   }while(opcion!= 0 );
   guardarCentroComercial( centroComercial, archivo );
	return 0;
}
