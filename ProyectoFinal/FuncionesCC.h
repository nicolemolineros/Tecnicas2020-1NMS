#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Local 
typedef struct Local{
	char nombreLocal[35];
	int idLocal; // Calculado automaticamente por su programa
	int numPisoLocal;
	int numLocalxPiso;//Columnas
	int vacio; // Vacio significa disponible
	int stockLocal;
	int cantidadStock;
	int tipo;
	int empleados;
	int numEmpleados;
	int deuda;
}local_t;

typedef struct Stock{
	int cantidad;
	int stock;
}stock_t;

enum disponibilidad { DISPONIBLE = 0, NODISPONIBLE = 1};
typedef enum tipoDeStock{ROPA, ZAPATOS, JOYAS} stocks_e;
enum deuda {DEUDA, NODEUDA};

local_t ** disenarCentroComercial1( int *numPiso, int *numLocal );
void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial );
void mostrarLocales( int numPiso, int numLocal,local_t ** centroComercial );
void cambiarNombreLocal( int numPiso, int numLocal, local_t ** centroComercial );
void eliminarLocal( int numPiso, int numLocal,local_t ** centroComercial );
void verLocalesSinArrendar( int numPiso, int numLocal, local_t ** centroComercial );
int contarLocalesDisponibles( int numPiso, int numLocal, int i, int j, int contador, local_t ** centroComercial );
void definirStockALocal( int numPiso, int numLocal,local_t ** centroComercial );
void marcarLocalEnDeuda(int numPiso, int numLocal, local_t ** centroComercial);
void merge(int a[], int left_low, int left_high, int right_low, int right_high);
void mergeSort(int a[], int lenght);
void ms(int a[], int low, int high);
void qs( int lista[ ], int limite_izq, int limite_der );
void Quicksort( int arreglo[ ], int n );
void insertionSort(int arr[], int n);
int burbuja(int arreglo[], int n);
int bubbleSort(int arreglo[], int n);
void ordenarIdLocal( local_t ** centroComercial, int arreglo[], int pisoOrdenado, int numLocal );
void guardarCentroComercial( local_t ** CentroComercial, char * archivo );
int archivoExistente( local_t ** centroComercial, char * archivo );

int menu( );
#endif /* FUNCIONESCC_H_ */