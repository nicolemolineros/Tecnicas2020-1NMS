#include "FuncionesCC.h"

local_t ** disenarCentroComercial( int *numPiso, int *numLocal ){
   int i, j, numPisos, numLocales;

   printf( "Ingresa el numero de pisos para tu Centro Comercial\n" );
   scanf("%d", &numPisos);
   printf( "Ingresa el numero de locales por piso para tu Centro Comercial\n" );
   scanf("%d", &numLocales);

   local_t ** centroComercial = malloc(sizeof( local_t* ) * ( *numPiso ) );
   for( i = 0; i < *numLocal; i++ ){
      centroComercial[i] = malloc(sizeof( local_t ) * ( *numLocal ) );
   }
   
   for( i = 0; i < *numPiso; i++ ){
	  for( j = 0; j < *numLocal; j++ ){
			local_t local;
			local.idLocal = rand() % 1111 + 2020;
			centroComercial[ i ][ j ] = local;
		}
	}
	
	return centroComercial;
}

void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial ){
   int nPiso, nLocal, nNombre, i, j;
   
   printf( "Ingrese el nombre de su nuevo local: \n" );
   scanf( "%s", centroComercial[nPiso][nLocal].nombreLocal );
   printf( "Ingrese el piso del local\n" );
   scanf( "%d", &nPiso );
   printf( "Ingrese la ubicación del local\n" );
   scanf( "%d", &nLocal );

   for( i = 0; i < nPiso; i++ ){
   	  for( j = 0; j < nLocal; j++){
   		if ( centroComercial[ nPiso ][ nLocal ].vacio == -1 ){
   			
   			centroComercial[ numPiso ][ nLocal ].vacio = 0;
   			printf( "El espacio ya está ocupado por favor ingrese una nueva posicion\n" );
   		
   	}
   }
}
   centroComercial[nPiso][nLocal].numPisoLocal = nPiso;
   centroComercial[nPiso][nLocal].numLocalxPiso = nLocal;

   return;
}

void mostrarLocales(local_t ** centroComercial, int numPiso, int numLocal){
   int i, j;
   
   for( i = 0; i < numPiso; i++ ){
  	  for( j = 0; j < numLocal; j++ ){
      if( centroComercial[ i ][ j ].vacio != -1 ){
  			
  			printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
  			printf( "id Local: %d \n", centroComercial[ i ][ j ].idLocal );
  			printf( "Piso local: %d \n", centroComercial[ i ][ j ].numPisoLocal );
  			printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
  		}
  	 }
  }
}

void eliminarLocal(local_t ** centroComercial, int numPiso, int numLocal){
   char nom[35];
   int i, j;

   fflush(stdin);
   printf( "Ingrese el nombre del local que desea eliminar: \n" );
   scanf( "%s", centroComercial[ i ][ j ].nombreLocal );
   
   for( i = 0; i < numPiso; i++ ){
  	  for( j = 0; j < numLocal; j++ ){
  		if( strcmp (centroComercial[ i ][ j ].nombreLocal, nom ) == 0){
  			centroComercial[ i ][ j ].vacio = -1;
  		}
  	 }
  }
}

void cambiarNombreLocal(local_t ** centroComercial, int numPiso, int numLocal){
   int nPiso, nLocal;
   char nom[35];
   
        if( centroComercial[nPiso][nLocal].deuda == deuda ){
		printf( "Este local no puede ser modificado\n" );
   return;
	    }

   strcpy( centroComercial[nPiso][nLocal].nombreLocal, nom );
   printf( "Digite el nuevo nombre: \n" ); 
   scanf( "%s", centroComercial[nPiso][nLocal].nombreLocal );
   printf( "%s Ahora su local se llama: %s\n",centroComercial[nPiso][nLocal].nombreLocal, nom );


}

void verLocalesSinDeuda(local_t ** centroComercial, int numPiso, int numLocal){
   
   int i, j;
	
	for( i = 0; i < numPiso; i++ ){
	   for( j = 0; j < numLocal; j++ ){
			if( centroComercial[ i ][ j ].deuda == noDeuda ){
			
			printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
  			printf( "id Local: %d \n", centroComercial[ i ][ j ].idLocal );
  			printf( "Piso local: %d \n", centroComercial[ i ][ j ].numPisoLocal );
  			printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
  		}
	}
}
	return;
}

int contarLocalesDeuda(local_t ** centroComercial, int numPisos, int numLocales, int i, int j, int deudita){

   if( i == numPisos && j == numLocales ){
        return deudita;
	}

   if(i == numPisos){
		i = 0;
	}

   if( j == numLocales ){
		j = 0;
		
	}
 
   if(centroComercial[ i ][ j ].deuda == deuda){
	   deudita++;
	}
	   j++;
	   i++;
   
   contarLocalesDeuda( numPisos, numLocales, centroComercial, i, j, deudita );

}

int menu(){
   
   int opcion;
   printf( "\n ¡BIENVENIDO AL CENTRO COMERCIAL! \n" );
   printf( "============================\n" );
   printf( "1 Diseñar Centro Comercial \n " );
   printf( "2 Agregar local nuevo \n ");
   printf( "3 Mostrar locales en uso \n" );
   printf( "4 Eliminar local \n" );
   printf( "5 Salir \n" );
   printf( "Digite su opción por favor \n" );
   printf("==>"); 
   scanf( "%d", &opcion );
   return opcion;
}