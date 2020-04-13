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
	int deuda;
}local_t;

enum cuentaLocal { deuda, noDeuda };

local_t ** disenarCentroComercial( int numPiso, int numLocal );
void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial );
void mostrarLocales(local_t ** centroComercial, int numPiso, int numLocal);
void eliminarLocal(local_t ** centroComercial, int numPiso, int numLocal);
void cambiarNombreLocal(local_t ** centroComercial, int numPiso, int numLocal);
void verLocalesSinDeuda(local_t ** centroComercial, int numPiso, int numLocal);
int contarLocalesDeuda(local_t ** centroComercial, int numPiso, int numLocal, int i, int j, int deudita);
int menu( ); 



#endif 