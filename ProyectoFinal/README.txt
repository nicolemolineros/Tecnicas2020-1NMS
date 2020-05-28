DOCUMENTACIÓN

1- disenarCentroComercial( int *numPiso, int *numLocal )
==> Esta función permite crear el tamaño del centro comercial, al digitar la cantidad de pisos y locales por piso
que el usuario desee.
Se hace uso de memoria dinámica para crear la matriz.
Recibe el tamaño del centro comercial (cada local).
El usuario digita la cantidad de pisos y locales que tendrá el centro comercial.
Retorna la matriz creada centroComercial.

2- agregarLocal( int numPiso, int numLocal, local_t ** centroComercial )
==> Esta función permite crear un nuevo local y se ubica donde el usuario desee siempre y cuando el espacio esté vacio.
El usuario digita el numero de piso y el numero de local donde desea ubicar su nuevo local.
Recibe el tamaño del centro comercial (cada local).
No retorna nada, ya que se está creando.

3- mostrarLocales( local_t ** centroComercial, int numPiso, int numLocal )
==> Esta función permite visualizar los locales ya creados por el usuario.
Se muestra en pantalla los locales creados.
Recibe el tamaño del centro comercial (cada local).
No retorna nada.
Se usan ciclos anidados

4- eliminarLocal( local_t ** centroComercial, int numPiso, int numLocal )
==> Esta función permite liberar el espacio de un local al eliminar el que ya estaba.
Recibe el tamaño del centro comercial (cada local).
Se hace uso de parámetros por referencia y valor.
Se implementa un ciclo anidado.
No retorna nada ya que se borra.

5- cambiarNombreLocal(local_t ** centroComercial, int numPiso, int numLocal)
==> Esta función permite cambiar el nombre de un local.
Recibe el tamaño del centro comecial (cada local).
Cambia el nombre de un local siempre y cuando esté en uso.

6- verLocalesDisponibles(local_t ** centroComercial, int numPiso, int numLocal)
==> Esta función permite visualizar en pantalla todos los locales que están disponibles.
Recibe el tamaño del centro comecial (cada local).
Se hace uso de parámetros por referencia y valor.
Se usan ciclos anidados.

7- definirStockAlLocal(int numPiso, int numLocal, local_t ** centroComercial )
==> Esta función permite definir que se va a vender en cada local; eligiendo entre vender ropa, zapatos o si es un restaurante.Se hace uso de parámetros por referencia y valor. 
Se usa enums.

8- marcarLocalEnDeuda(local_t ** centroComercial, int numPisos, int numLocales, int i, int j, int deudita)
==> Esta función permite contar todos los locales que presentan deuda.
Recibe el tamaño del centro comecial (cada local).
Se hace uso de recursión.
Se hace uso de enums.

NEW:
Se hace uso de algoritmos de ordenamiento. Se implementan archivos.
Se corrigen funciones que no servian en en la primera enterga.
