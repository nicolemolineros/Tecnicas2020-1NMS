/* C program for implementation of selection sort 
Tomado de https://www.geeksforgeeks.org/selection-sort/ */
#include <stdio.h> 
#include<time.h>

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 
	for (i = 0; i < n-1; i++){ 

		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int *randomValores( int n ){
	int *arr;
	int i;
    arr = malloc( n * sizeof(int) );
	
   srand( time(NULL) );

	for( i = 0 ; i < n ; i++ ){
		arr[i] = rand()%1000000; 
	}
	return arr;
}
int main( ){ 
   int arr[ 1000000 ]; 
   int n = sizeof( arr ) / sizeof( arr[0] ); 
   int *arreglo = randomValores( 1000000 );
   int i;
   FILE  *archivoAlmacenar;

	archivoAlmacenar = fopen( "Random1000000.txt", "w" );

	   for(i = 0; i < 1000000; i++){
		   fprintf( archivoAlmacenar, "%d\n", arreglo[i] );
	}
    time_t start, end;
	
	printf( "El arreglo inicial es: \n" );
	   for( i = 0; i < n; i++ ){
		  printf( " %d", arreglo[i] );
	}
	
	start = time(NULL);
	
	archivoAlmacenar = fopen( "fSelectionSort.txt", "a" );
	fprintf( archivoAlmacenar, "   * Selection Sort  *    \n" );
	fprintf( archivoAlmacenar, "Elementos en el arreglo: %d\n", n );
	fprintf( archivoAlmacenar, "Tiempo Inicial: %.2f segundos\n", start );
	
   selectionSort(arr, n);
   printArray(arr, n); 
  
	
	end = time(NULL);
	fprintf( archivoAlmacenar, "Tiempo Empleado: %.2f segundos\n", difftime(end,start) );
	fclose( archivoAlmacenar );
	
	printf( "\nEl arreglo ordenado resultante es: \n" );
	for( i = 0; i < n; i++ ){
		printf( " %d", arreglo[i] );
	}
    return 0; 
} 