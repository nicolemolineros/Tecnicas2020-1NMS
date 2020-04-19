#include "Insercion.h"

int main( ){ 
   int arr[ ] = {5,2,4,0,3,1,6}; 
   int n = sizeof( arr ) / sizeof( arr[0] ); 
   printf( "El arreglo ordenado es: \n");
   ordenarArreglo( arr, n ); 
   mostrarOrden( arr, n ); 
  
    return 0; 
} 