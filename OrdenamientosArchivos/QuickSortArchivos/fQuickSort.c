#include <stdio.h> 
#include <time.h>

void swapArreglo( int* a, int* b ){ 
   int intercambio = *a; 
   *a = *b; 
   *b = intercambio; 
} 
  
int partirEnDos( int arr[ ], int inicioIndex, int finIndex ){ 
   int pivot = arr[ finIndex ]; 
   int i = ( inicioIndex - 1 ); 
  
   for( int j = inicioIndex; j <= finIndex- 1; j++ ){ 
      if ( arr[ j ] < pivot ){ 
        i++;
        swapArreglo( &arr[ i ], &arr[ j ] ); 
      } 
   } 
   swapArreglo( &arr[i + 1], &arr[ finIndex ] ); 
   return i + 1; 
} 
  
void ordenarArreglo( int arr[ ], int inicioIndex, int finIndex ){ 
   if( inicioIndex < finIndex ){ 
      int partir = partirEnDos( arr, inicioIndex, finIndex ); 
      ordenarArreglo( arr, inicioIndex, partir - 1 ); 
      ordenarArreglo( arr, partir + 1, finIndex ); 
    } 
} 
void mostrarOrden( int arr[], int tam ){ 
   int i; 
   
   for( i=0; i < tam; i++ ) 
      printf( "%d ", arr[i] );  
} 

int *randomValores( int n ){
	int *arr;
	int i;
   arr = malloc( n * sizeof(int) );
	
   srand( time(NULL) );

	for( i = 0 ; i < n ; i++ ){
		arr[i] = rand()%999999; 
	}
	return arr;
}
int main( ){ 
   int arr[ 999999 ]; 
   int n = sizeof( arr ) / sizeof( arr[0] ); 
   int *arreglo = randomValores( 999999 );
   int i;
   FILE  *archivoAlmacenar;

	archivoAlmacenar = fopen( "Random999999.txt", "w" );

	   for(i = 0; i < 999999; i++){
		   fprintf( archivoAlmacenar, "%d\n", arreglo[i] );
	}
    time_t start, end;
	
	printf( "El arreglo inicial es: \n" );
	   for( i = 0; i < n; i++ ){
		  printf( " %d", arreglo[i] );
	}
	
	start = time(NULL);
	
	archivoAlmacenar = fopen( "fQuickSort.txt", "a" );
	fprintf( archivoAlmacenar, "   * Quick Sort  *    \n" );
	fprintf( archivoAlmacenar, "Elementos en el arreglo: %d\n", n );
	fprintf( archivoAlmacenar, "Tiempo Inicial: %.2f segundos\n", start );
	
	ordenarArreglo( arr, n, 0 ); 
   mostrarOrden( arr, n ); 
  
	
	end = time(NULL);
	fprintf( archivoAlmacenar, "Tiempo Empleado: %.2f segundos\n", difftime(end,start) );
	fclose( archivoAlmacenar );
	
	printf( "\nEl arreglo ordenado resultante es: \n" );
	for( i = 0; i < n; i++ ){
		printf( " %d", arreglo[i] );
	}
    return 0; 
} 