#include <stdio.h> 
#include "Insercion.h"

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
