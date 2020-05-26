#include <stdio.h>
#include <stdexcept>
#include "FuncionesCC.h"

local_t ** disenarCentroComercial( int * numPiso, int * numLocal ){
   int i, j;
   local_t ** centroComercial = malloc(sizeof( local_t* ) * ( * numPiso ) );
   for( i = 0; i < *numLocal; i++ ){
      centroComercial[ i ] = malloc(sizeof( local_t ) * ( * numLocal ) );
   }
      for( i = 0; i < * numPiso; i++ ){
	      for( j = 0; j < * numLocal; j++ ){
			local_t local;
         	local.vacio = DISPONIBLE;
			local.idLocal = rand();
			centroComercial[ i ][ j ] = local;
		}
	}
	return centroComercial;
}

void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial){
      int piso, local;
   
   do{
      printf( "Ingrese el piso del local: " ); 
      scanf( "%d", &piso );
		if( piso > numPiso || piso < 0 )
	  	throw std::logic_error( "Intente nuevamente. El numero de pisos es :%d\n", numPiso - 1 );
	}while(piso < 0 || piso >= numPiso);
		
	do{
	  printf("Ingrese la ubicación del local "); 
      scanf( "%d", &local );
		if( centroComercial[piso][local].vacio == NODISPONIBLE )
			throw std::logic_error( "Ubicación escogida no disponible\n" );
	}while( local < 0 || local >= numLocal ||centroComercial[piso][local].vacio == DISPONIBLE );
	
	centroComercial[piso][local].numPisoLocal = piso;
	centroComercial[piso][local].numLocalxPiso = local;
	centroComercial[piso][local].vacio = 0;
	printf( "Ingrese el nombre de su local: " ); 
	scanf( "%s", centroComercial[piso][local].nombreLocal );
	printf( "Tu local: <%s> ahora está disponible \n", centroComercial[piso][local].nombreLocal );
	printf("=====================================================================\n");
	return;
}

void mostrarLocales( int numPiso, int numLocal, local_t ** centroComercial){
   int i, j;
   
   for( i = 0; i < numPiso; i++ ){
  	  for( j = 0; j < numLocal; j++ ){
      if( centroComercial[ i ][ j ].vacio == 0  ){
  			
  			printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
  			printf( "id Local: %d \n", centroComercial[ i ][ j ].idLocal );
  			printf( "Piso local: %d \n", centroComercial[ i ][ j ].numPisoLocal );
  			printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
  			printf("=====================================================================\n");
		}
  	 }
  }
}

void eliminarLocal(int numPiso, int numLocal, local_t ** centroComercial){
   int piso, local;
   fflush(stdin);   
   do{
		printf("Ingrese el piso del local que desea eliminar: \n"); 
		scanf("%d", &piso);
		if(piso > numPiso || piso < 0)
			throw std::logic_error( "Verifique los datos, el max es :%d\n", numPiso - 1 );
	}while(piso < 0 || piso >= numPiso);
		
	do{
		printf( "Ingrese el número del local: "); 
		scanf("%d", &local);
		if(local > numLocal || local < 0)
			throw std::logic_error("Verifique los datos, el max es: %d\n", numLocal - 1 );
	}while(local < 0 || local >= numLocal );
	centroComercial[piso][local].vacio = DISPONIBLE;
	printf("El local que antes ocupaba: %s ahora se encuentra disponible\n",centroComercial[piso][local].nombreLocal );
	printf("=====================================================================\n");
	return;
}

void cambiarNombreLocal( int numPiso, int numLocal, local_t ** centroComercial ){
   int nPiso, nLocal;
   char nombre[35];
do{
	printf("Ingrese el piso del local que desea cambiar el nombre: "); 
	scanf("%d", &nPiso);
	if(nPiso > numPiso || nPiso < 0)
		throw std::logic_error("Verifique los datos, el max es: %d\n", numPiso-1);
	}while(nPiso < 0 || nPiso >= numPiso);
		
	do{
		printf("Numero de local: "); scanf("%d", &nLocal);
		if(nLocal > numLocal || nLocal < 0)
		throw std::logic_error("Verifique los datos, el max es: %d\n", numLocal-1);
	}while(nLocal < 0 || nLocal >= numLocal);
	
	if(centroComercial[nPiso][nLocal].vacio == DISPONIBLE){
		throw std::logic_error("Este local no ha sido ocupado aún\n");
		return;
	}
	strcmp(nombre, centroComercial[nPiso][nLocal].nombreLocal);
	printf("El nuevo nombre: "); 
	scanf("%s", centroComercial[nPiso][nLocal].nombreLocal);
	printf("El local %s ahora se llama %s\n", nombre, centroComercial[nPiso][nLocal].nombreLocal);
	printf("=====================================================================\n");

}

void verLocalesSinArrendar( int numPiso, int numLocal, local_t ** centroComercial){
   
   int i, j;
	
	for( i = 0; i < numPiso; i++ ){
	   for( j = 0; j < numLocal; j++ ){
			if( centroComercial[ i ][ j ].vacio == NODISPONIBLE ){
			
			printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
  			printf( "id Local: %d \n", centroComercial[ i ][ j ].idLocal );
  			printf( "Piso local: %d \n", centroComercial[ i ][ j ].numPisoLocal );
  			printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
			printf("=====================================================================\n");
  		}
	}
}
	return;
}

int contarLocalesDisponibles( int numPiso, int numLocal, int i, int j, int contador, local_t ** centroComercial ){

   if(j == numLocal){
		j = 0;
		i++;
	}
	if(i == numPiso){
		return contador;
	}
	if(centroComercial[i][j].vacio == DISPONIBLE){
		contador++;
	}
	j++;
	contarLocalesDisponibles( numPiso, numLocal, i, j, contador, centroComercial );
}
void definirStockALocal(int numPiso, int numLocal, local_t ** centroComercial ){
	int nPiso, nLocal, cantiStock, tipo, opc;
	stock_t nStock;
	do{
	printf("Ingrese el piso del local que desea definir stock: "); 
	scanf("%d", &nPiso);
	if(nPiso > numPiso || nPiso < 0)
		throw std::logic_error("Verifique los datos, el max es: %d\n", numPiso-1);
	}while(nPiso < 0 || nPiso >= numPiso);
		
	do{
		printf("Numero de local: "); 
		scanf("%d", &nLocal);
		if(nLocal > numLocal || nLocal < 0)
		throw std::logic_error("Verifique los datos, el max es: %d\n", numLocal-1);
	}while(nLocal < 0 || nLocal >= numLocal);
	
	if(centroComercial[nPiso][nLocal].vacio == NODISPONIBLE){
		printf("Este local no ha sido puesto en uso\n");
		return;
	}
	centroComercial[nPiso][nLocal].stockLocal++;
	cantiStock = centroComercial[nPiso][nLocal].stockLocal;
	do{
		printf( "Seleccione la opcion que desea agregar\n" );
		printf("[1] ROPA  / [2] CALZADO / [3] JOYAS \n"); 
		scanf( "%d", &opc );
		if( opc == 1 ){
			centroComercial[nPiso][nLocal].tipo = ROPA;
		}else if( opc == 2 ){
			centroComercial[nPiso][nLocal].tipo = ZAPATOS;
		}else if( opc == 3 ){
			centroComercial[nPiso][nLocal].tipo = JOYAS;
		}else{
			throw std::logic_error("No es valida la opción!\n");
		}
	}while( opc != 1 && opc != 2 && opc != 3 );
	
	printf("El local [%s] se definió para vender [%d] \n", centroComercial[nPiso][nLocal].nombreLocal, centroComercial[nPiso][nLocal].tipo+1 );
	printf("=====================================================================\n");
}

void marcarLocalEnDeuda(int numPiso, int numLocal, local_t ** centroComercial){
	int i, j, nPiso, nLocal;
	
	do{
	printf("Ingrese el piso del local que desea añadir deuda: "); 
	scanf("%d", &nPiso);
	if(nPiso > numPiso || nPiso < 0)
		throw std::logic_error("Verifique los datos, el max es: %d\n", numPiso-1);
	}while(nPiso < 0 || nPiso >= numPiso);
		
	do{
		printf("Numero de local: "); scanf("%d", &nLocal);
		if(nLocal > numLocal || nLocal < 0)
		throw std::logic_error("Verifique los datos, el max es: %d\n", numLocal-1);
	}while(nLocal < 0 || nLocal >= numLocal);
	
	if(centroComercial[nPiso][nLocal].vacio == DISPONIBLE){
		printf("Este local no ha sido ocupado aún\n");
		return;
	}
	centroComercial[nPiso][nLocal].deuda = DEUDA;
	printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
	printf( "Piso: %d \n", centroComercial[ i ][ j ].numPisoLocal );
	printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
	printf( "ID del local: %d \n", centroComercial[ i ][ j ].idLocal );
	printf("=====================================================================\n");
}

//ARCHIVOS
void guardarCentroComercial( local_t * centroComercial, char * archivo ){
	FILE * archivo2 = fopen( archivo2, "w" );
	fwrite( centroComercial, sizeof(*centroComercial), 1, archivo2 );
	fclose( archivo2 );
	return;
}

int archivoExistente( local_t * centroComercial, char * archivo ){
	FILE * archivo1 = fopen( archivo, "r" );
	if( archivo1 == NULL ){
		return 0;
	}
	fread( centroComercial, sizeof(*centroComercial), 1, archivo1 );
	fclose( archivo1 );
	return 1;
}

int menu(){

   int opcion;
   printf( "\n ¡BIENVENIDO AL CENTRO COMERCIAL! \n" );
   printf( "============================\n" );
   printf( "[1] Agregar local nuevo\n" );
   printf( "[2] Mostrar locales en uso\n" );
   printf( "[3] Cambiar nombre del local \n" );
   printf( "[4] Eliminar local \n" );
   printf( "[5] Locales sin arrendar \n" );
   printf( "[6] Contar locales \n" );
   printf( "[7] Agregar stock \n" );
   printf( "[7] Agregar deuda \n" );
   printf( "[8] Salir \n" );
   printf( "Digite su opción por favor \n" );
   printf("==>");
   scanf( "%d", &opcion );
   return opcion;
}
