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
	int deuda;
    int stock;
}local_t;
typedef struct centroComercial{
	char nameCC[35];
	int numPisos;
	int numLocalesPisos;
	local_t locales[MAXPISOS][MAXLOCALES];
    int localesEnUso;

}centroComercial_t;

enum cuentaLocal { DEUDA, NODEUDA };
enum disponibilidad { DISPONIBLE = 0, NODISPONIBLE = 1};

local_t ** disenarCentroComercial( int *numPiso, int *numLocal );
void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial );
void mostrarLocales(local_t ** centroComercial, int numPiso, int numLocal);
/*void eliminarLocal(local_t ** centroComercial, int numPiso, int numLocal);
void cambiarNombreLocal(local_t ** centroComercial, int numPiso, int numLocal);
void verLocalesSinDeuda(local_t ** centroComercial, int numPiso, int numLocal);
int contarLocalesDeuda(local_t ** centroComercial, int numPiso, int numLocal, int i, int j, int deudita);
*/
int menu( );
#endif /* FUNCIONESCC_H_ */