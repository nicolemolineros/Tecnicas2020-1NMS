#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

typedef struct Empleados{
	char nombre[35];
	int cc; //cc = cedula de ciudadnia
	int edad;
	int correo;
	int numContacto;
}empleado_t;


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
void guardarCentroComercial( local_t * centro, char * archivo );
int archivoExistente( local_t * centro, char * archivo );
int menu( );
#endif /* FUNCIONESCC_H_ */