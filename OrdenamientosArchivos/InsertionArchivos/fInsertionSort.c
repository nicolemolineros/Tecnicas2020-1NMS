#include <stdio.h> 
#include <time.h>

void ordenarArreglo( int arr[ ], int n ){ 
    int i, j, marcador; 
    
    for( i = 1; i < n; i++ ){ 
       marcador = arr[ i ]; 
       j = i - 1; 

        while( j >= 0 && arr[ j ] > marcador ){ 
            arr[ j + 1 ] = arr[ j ]; 
            j = j - 1; 
        } 
      arr[ j + 1 ] = marcador; 
    } 
} 
void mostrarOrden( int arr[ ], int n ){ 
    int i; 
    
    for( i = 0; i < n; i++ ) 
        printf( "%d ", arr[ i ] ); 
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
   int *arreglo = randomValores(999999);
   int i;
   FILE  *archivoAlmacenar;

	archivoAlmacenar = fopen("Random999999.txt", "w");

	for(i = 0; i < 999999; i++){
		fprintf(archivoAlmacenar, "%d\n", arreglo[i]);
	}
    time_t start, end;
	
	printf("El arreglo inicial es: \n");
	for(i = 0; i < n; i++){
		printf(" %d", arreglo[i]);
	}
	
	start = time(NULL);
	
	archivoAlmacenar = fopen( "fInsertionSort.txt", "a");
	fprintf(archivoAlmacenar, "   * Insertion Sort  *     \n");
	fprintf(archivoAlmacenar, "Elementos en el arreglo: %d\n", n);
	fprintf(archivoAlmacenar, "Tiempo Inicial: %.2f segundos\n", start );
	
	ordenarArreglo( arr, n ); 
    mostrarOrden( arr, n ); 
  
	
	end = time(NULL);
	fprintf(archivoAlmacenar, "Tiempo Empleado: %.2f segundos\n", difftime(end,start) );
	fclose( archivoAlmacenar );
	
	printf("\nEl arreglo ordenado resultante es: \n");
	for(i = 0; i < n; i++){
		printf(" %d", arreglo[i]);
	}
    return 0; 
} 