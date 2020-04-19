#include <stdio.h> 
#include "QuickSort.h"

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
  