#include "QuickSort.h"

int main( ){ 
   int arr[ ] = {0,3,5,4,1,6,2}; 
   int n = sizeof( arr)/sizeof(arr[0] ); 
   ordenarArreglo(arr, 0, n-1); 
   printf( "El arreglo ordenado es: \n" ); 
   mostrarOrden( arr, n ) ; 
   return 0; 
} 

