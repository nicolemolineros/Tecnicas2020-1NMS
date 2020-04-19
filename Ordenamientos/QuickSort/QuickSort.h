#include <stdio.h>

void swapArreglo( int* a, int* b );
//Esta función está encargada de hacer el intercambio de valores del arreglo cuando un valor en menor que otro.
int partirEnDos( int arr[ ], int inicioIndex, int finIndex );
/*Esta función es la que nos divide el arreglo en dos para que se pueda hacer el ordenamiento de los numeros menores 
y mayores en dos nuevos arreglos*/
void ordenarArreglo( int arr[ ], int inicioIndex, int finIndex );
//Esta función es la encargada de hacer el quick sort en el arreglo y los arreglo que se "partieron" del arreglo original
void mostrarOrden( int arr[], int tam );
//Esta función muestra el arreglo ya ordenado.