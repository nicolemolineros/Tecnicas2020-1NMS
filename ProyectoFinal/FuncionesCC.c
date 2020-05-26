#include <stdio.h>
#include "FuncionesCC.h"

local_t ** disenarCentroComercial( int * numPiso, int * numLocal ){
   int i, j;
   local_t ** centroComercial = malloc(sizeof( local_t* ) * ( * numPiso ) );
   for( i = 0; i < *numLocal; i++ ){
      centroComercial[ i ] = malloc(sizeof( local_t ) * ( * numLocal ) );
   }
      for( i = 0; i < * numPiso; i++ ){
	      for( j = 0; j < * numLocal; j++ ){
			local_t local;
         	local.vacio = DISPONIBLE;
			local.idLocal = 1000 + rand( )%( 10001 + 1000 );
			centroComercial[ i ][ j ] = local;
		}
	}
	return centroComercial;
}

void agregarLocal( int numPiso, int numLocal, local_t ** centroComercial ){
      int piso, local, temp, aux;
   
   do{
      printf( "Ingrese el piso del local: " ); 
      scanf( "%d", &piso );
		if( piso > numPiso || piso < 0 ){
	  	printf( "Intente nuevamente. El numero de pisos es :%d\n", numPiso );
		}
	}while(piso < 0 || piso > numPiso);
	temp = piso;
	piso--;
	do{
	  printf("Ingrese la ubicación del local "); 
      scanf( "%d", &local );
	  aux = local;
	  local--;
		if( centroComercial[piso][local].vacio == NODISPONIBLE )
			printf( "Ubicación escogida no disponible\n" );
	}while( local < 0 || local > numLocal );

	centroComercial[piso][local].numPisoLocal = temp;
	centroComercial[piso][local].numLocalxPiso = aux;
	centroComercial[piso][local].vacio = 0;
	printf( "Ingrese el nombre de su local: " ); 
	scanf( "%s", centroComercial[piso][local].nombreLocal );
	printf( "Tu local: <%s> ahora está disponible \n", centroComercial[piso][local].nombreLocal );
	printf("=====================================================================\n");
	return;
}

void mostrarLocales( int numPiso, int numLocal, local_t ** centroComercial){
   int i, j;
   
   for( i = 0; i < numPiso; i++ ){
  	  for( j = 0; j < numLocal; j++ ){
      if( centroComercial[ i ][ j ].vacio = DISPONIBLE ){
  			
  			printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
  			printf( "id Local: %d \n", centroComercial[ i ][ j ].idLocal );
  			printf( "Piso local: %d \n", centroComercial[ i ][ j ].numPisoLocal );
  			printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
  			printf("=====================================================================\n");
		}
  	 }
  }
}

void eliminarLocal(int numPiso, int numLocal, local_t ** centroComercial){
   int piso, local;
   fflush(stdin);   
   do{
		printf("Ingrese el piso del local que desea eliminar: \n"); 
		scanf("%d", &piso);
		if(piso > numPiso || piso < 0)
			printf( "Verifique los datos, el max es :%d\n", numPiso - 1 );
	}while(piso < 0 || piso > numPiso);
		piso--;
		
	do{
		printf( "Ingrese el número del local: "); 
		scanf("%d", &local);
		if(local > numLocal || local < 0)
			printf("Verifique los datos, el max es: %d\n", numLocal - 1 );
	}while(local < 0 || local > numLocal );
		local--;
	centroComercial[piso][local].vacio = DISPONIBLE;
	printf("El local que antes ocupaba: %s ahora se encuentra disponible\n",centroComercial[piso][local].nombreLocal );
	printf("=====================================================================\n");
	return;
}

void cambiarNombreLocal( int numPiso, int numLocal, local_t ** centroComercial ){
   int nPiso, nLocal;
   char nombre[35];
do{
	printf("Ingrese el piso del local que desea cambiar el nombre: "); 
	scanf("%d", &nPiso);
	if(nPiso > numPiso || nPiso < 0)
		printf("Verifique los datos, el max es: %d\n", numPiso-1);
	}while(nPiso < 0 || nPiso > numPiso);
		nPiso--;
		
	do{
		printf("Numero de local: "); scanf("%d", &nLocal);
		if(nLocal > numLocal || nLocal < 0)
		printf("Verifique los datos, el max es: %d\n", numLocal-1);
	}while(nLocal < 0 || nLocal > numLocal);
		nLocal--;
	
	if(centroComercial[nPiso][nLocal].vacio == DISPONIBLE){
		printf("Este local no ha sido ocupado aún\n");
		return;
	}
	strcmp(nombre, centroComercial[nPiso][nLocal].nombreLocal);
	printf("El nuevo nombre: "); 
	scanf("%s", centroComercial[nPiso][nLocal].nombreLocal);
	printf("El local %s ahora se llama %s\n", nombre, centroComercial[nPiso][nLocal].nombreLocal);
	printf("=====================================================================\n");

}

void verLocalesSinArrendar( int numPiso, int numLocal, local_t ** centroComercial){
   
   int i, j;
	
	for( i = 0; i < numPiso; i++ ){
	   for( j = 0; j < numLocal; j++ ){
			if( centroComercial[ i ][ j ].vacio == NODISPONIBLE ){
			
			printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
  			printf( "id Local: %d \n", centroComercial[ i ][ j ].idLocal );
  			printf( "Piso local: %d \n", centroComercial[ i ][ j ].numPisoLocal );
  			printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
			printf("=====================================================================\n");
  		}
	}
}
	return;
}

int contarLocalesDisponibles( int numPiso, int numLocal, int i, int j, int contador, local_t ** centroComercial ){

   if(j == numLocal){
		j = 0;
		i++;
	}
	if(i == numPiso){
		return contador;
	}
	if(centroComercial[i][j].vacio == DISPONIBLE){
		contador++;
	}
	j++;
    contarLocalesDisponibles( numPiso, numLocal, i, j, contador, centroComercial );
}
void definirStockALocal(int numPiso, int numLocal, local_t ** centroComercial ){
	int nPiso, nLocal, cantiStock, tipo, opc;
	stock_t nStock;
	do{
	printf("Ingrese el piso del local que desea definir stock: "); 
	scanf("%d", &nPiso);
	if(nPiso > numPiso || nPiso < 0)
		printf("Verifique los datos, el max es: %d\n", numPiso-1);
	}while(nPiso < 0 || nPiso >= numPiso);
		nPiso--;
	do{
		printf("Numero de local: "); 
		scanf("%d", &nLocal);
		if(nLocal > numLocal || nLocal < 0)
		printf("Verifique los datos, el max es: %d\n", numLocal-1);
	}while(nLocal < 0 || nLocal >= numLocal);
		nLocal--;
	if(centroComercial[nPiso][nLocal].vacio == NODISPONIBLE){
		printf("Este local no ha sido puesto en uso\n");
		return;
	}
	centroComercial[nPiso][nLocal].stockLocal++;
	cantiStock = centroComercial[nPiso][nLocal].stockLocal;
	do{
		printf( "Seleccione la opcion que desea agregar\n" );
		printf("[1] ROPA  / [2] CALZADO / [3] JOYAS \n"); 
		scanf( "%d", &opc );
		if( opc == 1 ){
			centroComercial[nPiso][nLocal].tipo = ROPA;
		}else if( opc == 2 ){
			centroComercial[nPiso][nLocal].tipo = ZAPATOS;
		}else if( opc == 3 ){
			centroComercial[nPiso][nLocal].tipo = JOYAS;
		}else{
			printf("No es valida la opción!\n");
		}
	}while( opc != 1 && opc != 2 && opc != 3 );
	
	printf("El local [%s] se definió para vender [%d] \n", centroComercial[nPiso][nLocal].nombreLocal, centroComercial[nPiso][nLocal].tipo+1 );
	printf("=====================================================================\n");
}

void marcarLocalEnDeuda(int numPiso, int numLocal, local_t ** centroComercial){
	int i, j, nPiso, nLocal;
	
	do{
	printf("Ingrese el piso del local que desea añadir deuda: "); 
	scanf("%d", &nPiso);
	if(nPiso > numPiso || nPiso < 0)
		printf("Verifique los datos, el max es: %d\n", numPiso-1);
	}while(nPiso < 0 || nPiso >= numPiso);
		nPiso--;
	do{
		printf("Numero de local: "); scanf("%d", &nLocal);
		if(nLocal > numLocal || nLocal < 0)
		printf("Verifique los datos, el max es: %d\n", numLocal-1);
	}while(nLocal < 0 || nLocal >= numLocal);
		nLocal--;
	if(centroComercial[nPiso][nLocal].vacio == DISPONIBLE){
		printf("Este local no ha sido ocupado aún\n");
		return;
	}
	centroComercial[nPiso][nLocal].deuda = DEUDA;
	printf( "Nombre Local: %s \n", centroComercial[ i ][ j ].nombreLocal );
	printf( "Piso: %d \n", centroComercial[ i ][ j ].numPisoLocal );
	printf( "Local: %d \n", centroComercial[ i ][ j ].numLocalxPiso );
	printf( "ID del local: %d \n", centroComercial[ i ][ j ].idLocal );
	printf("=====================================================================\n");
}
//MergeSort
void merge(int a[], int left_low, int left_high, int right_low, int right_high){
	int lenght = right_high-left_low + 1;
	int temp[lenght];

	int left = left_low;
	int right = right_low, i;

	for(i=0;i<lenght;++i){
		if(left>left_high){
			temp[i] = a[right++];
		}else if(right>right_high){
			temp[i] = a[left++];
		}else if(a[left]<= a[right]){
			temp[i] = a[left++];
		}else{
			temp[i] = a[right++];
		}
	}
	for(i=0;i<lenght;++i){
		a[left_low++] = temp[i];
	}	

}

void ms(int a[], int low, int high){
	if(low>=high){
		return;
	}else{
		int mid = (low + high)/2;
		ms(a, low, mid);
		ms(a, mid+1, high );
		merge(a, low, mid, mid + 1, high);
	}
}

void mergeSort(int a[], int lenght){
	ms(a, 0, lenght - 1);
	
	for (i = 0; i <= lenght; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
}
void ordenarIdLocal(local_t ** centroComercial, int arreglo[], int pisoOrdenado, int numLocal ){
	int i, aux = 0;
	
	printf("Que piso quiere ordenar? \n ");
	scanf("%d", &pisoOrdenado);
	for( i = 0; i < numLocal; i++){
		arreglo[ aux ] = centroComercial[ pisoOrdenado ][ i ].idLocal;
		printf(".");
	}
	aux++;
	for (i = 0; i <= numLocal; i++) 
        printf("%d ", arreglo[i]); 
    printf("\n"); 
}

//QuickSort
void qs( int lista[ ], int limite_izq, int limite_der ){
	int izq, der, temp, mitad;

	izq = limite_izq;	
	der = limite_der;
	mitad = lista[ ( izq + der ) / 2 ];

	do{
		while( lista[ izq ] < mitad && izq < limite_der )izq++;
			while( mitad < lista[ der ] && der > limite_izq )der--;	
				if( izq <= der ){
					temp = lista[ izq ];
					lista[ izq ] = lista[ der ];
					lista[ der ] = temp;
					izq++;
					der--;
				}
	}while( izq <= der );
		if( limite_izq < der ){
			qs( lista, limite_izq, der);
		}
		if( limite_der > izq ){
			qs( lista, izq, limite_der );
		}
}

void Quicksort( int arreglo[ ], int n ){

	qs( arreglo, 0, n - 1 );
}

//Insertion
void insertionSort(int arr[], int n){ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 

} 

//Burbuja
int burbuja(int arreglo[], int n){
	int i, j, aux = 0;

	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(arreglo[j]>arreglo[j+1]){
                        	aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
			}
		}
	}
	for (i = 0; i < n; i++) 
        printf("%d ", arreglo[i]); 
    printf("\n"); 

}

int bubbleSort(int arreglo[], int n){
	int i, j, aux = 0; 

	for(i=1;i<=n;i++){
		for(j=n;j>=i;j--){
			if(arreglo[j-1]>arreglo[j]){
				aux = arreglo[j-1];
				arreglo[j-1]=arreglo[j];
				arreglo[j]=aux;
		}
	}
} 

	for (i = 0; i < n; i++) 
        printf("%d ", arreglo[i]); 
    printf("\n"); 

}

//ARCHIVOS
void guardarCentroComercial( local_t ** centroComercial, char * archivo ){
	FILE * archivo2 = fopen( archivo, "w" );
	fwrite( archivo2, centroComercial, sizeof(*centroComercial), 1 );
	fclose( archivo2 );
	return;
}

int archivoExistente( local_t ** centroComercial, char * archivo ){
	FILE * archivo1 = fopen( archivo, "r" );
	if( archivo1 == NULL ){
		return 0;
	}
	fread( archivo1, centroComercial, sizeof(*centroComercial), 1 );
	fclose( archivo1 );
	return 1;
}

int menu(){

   int opcion;
   printf( "\n ¡BIENVENIDO AL CENTRO COMERCIAL! \n" );
   printf( "============================\n" );
   printf( "[1] Agregar local nuevo\n" );
   printf( "[2] Mostrar locales en uso\n" );
   printf( "[3] Cambiar nombre del local \n" );
   printf( "[4] Eliminar local \n" );
   printf( "[5] Locales sin arrendar \n" );
   printf( "[6] Contar locales \n" );
   printf( "[7] Agregar stock \n" );
   printf( "[8] Agregar deuda \n" );
   printf( "[9] Ordenar ID Local");
   printf( "[10] Merge Sort \n" );
   printf( "[11] Quick Sort \n" ); 
   printf( "[12] Insertion Sort \n" );
   printf( "[13] Burbuja \n");
   printf( "[0] Salir \n" );
   printf( "Digite su opción por favor \n" );
   printf("==>");
   scanf( "%d", &opcion );
   return opcion;
}
