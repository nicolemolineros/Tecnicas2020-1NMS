#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXPISOS 5
#define MAXLOCALES 15

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
}local_t;

typedef struct Stock{
	int cantidad;
	int stock;
}stock_t;

enum disponibilidad { DISPONIBLE = 0, NODISPONIBLE = 1};
typedef enum tipoDeStock{ROPA, ZAPATOS, JOYAS} stocks_e;

local_t ** disenarCentroComercial( int *numPiso, int *numLocal );
void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial );
void mostrarLocales( int numPiso, int numLocal,local_t ** centroComercial );
void eliminarLocal( int numPiso, int numLocal,local_t ** centroComercial );
void cambiarNombreLocal( local_t ** centroComercial, int numPiso, int numLocal );
void verLocalesSinArrendar( local_t ** centroComercial, int numPiso, int numLocal );
int contarLocalesDisponibles( int numPiso, int numLocal, int i, int j, int contador,local_t ** centroComercial );
void agregarStockALocal( int numPiso, int numLocal,local_t ** centroComercial );
int menu( );
#endif /* FUNCIONESCC_H_ */