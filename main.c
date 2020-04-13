#include "FuncionesCC.h"
#include <stdio.h>


int main(){

int opcion, numPiso, numLocal, i, j, deudita;
local_t ** centroComercial;
   
   do{
      
      opcion = menu( );
      switch(opcion){
         
         case 1:
            disenarCentroComercial( numPiso, numLocal );
            break;
         
         case 2:
            agregarLocal( numPiso, numLocal, centroComercial);
            break;
         
         case 3:
            mostrarLocales( centroComercial, numPiso, numLocal );
            break;

         case 4:
            eliminarLocal( centroComercial, numPiso, numLocal);
            break;

         case 5:
            cambiarNombreLocal( centroComercial, numPiso, numLocal );
            break;

         case 6:
            verLocalesSinDeuda( centroComercial, numPiso, numLocal );
            break;

         case 7:
            contarLocalesDeuda( centroComercial, numPiso, numLocal, i, j, deudita );
            break;

      }

   printf( "Desea volver a ingresar al menú? SI <S> NO <NO> \n" );
   scanf( "%d", &opcion);
   
   }while(opcion!= 7);



	return 0;
}
