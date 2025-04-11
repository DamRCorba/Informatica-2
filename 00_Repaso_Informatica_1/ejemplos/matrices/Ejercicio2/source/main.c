/*******************************************************************************************************

Ejercicio 2 - Para resolver por los alumnos
Enunciado: Hacer una Matriz que contenga hasta 9 productos.
          Cada fila de la matriz debera contener Nombre, Cantidad, precio y codigo. Imprimir en pantalla

*******************************************************************************************************/
#include <stdio.h>
#include "../header/conf.h" //libreria de configuracion

/*Armar una matriz de 9 Productos que contengan su nombre, cantidad, precio y codigo*/

int main() {
  unsigned char productos[CANTIDAD_PRODUCTOS][4][20], i;
  enum columnas j;
/*Se ingresan los 9 productos*/
  printf("Ingrese los productos\n\r\n\r");
  for(i=0;i<CANTIDAD_PRODUCTOS;i++){
    for(j=0;j<4;j++){
      switch (j) {
        case nombre:
              printf("Ingrese el Nombre: ");
              break;
        case cantidad:
        printf("Ingrese el Cantidad: ");
        break;
        case precio:
        printf("Ingrese el Precio: ");
        break;
        case codigo:
        printf("Ingrese el codigo: ");
        break;
      }
      gets(productos[i][j]);
    }
  }
  /*Se muestran en Pantalla los productos*/
    printf("\n\rNombre\tCantidad\tPrecio\tCodigo" );
  for(i=0;i<9;i++){
    printf("\n\r" );
    for(j=0;j<4;j++){
      printf("%s \t",productos[i][j]);
    }
  }
    printf("\n\r\n\r");
  return 0;
}
