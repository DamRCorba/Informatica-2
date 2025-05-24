#include "funciones.h"
#include <stdio.h>

int suma(int a, int b)
{
    printf("En suma a=%d, &a=%x, b=%d, &b=%x\n", a, &a, b, &b);
    return a + b;
}

producto_t cargarProducto(void){
    producto_t p;
    printf("\nIngrese el SKU: ");
    scanf("%s", p.sku);
    printf("\nIngrese la descripcion: ");
    scanf("%s", p.descripcion);
    fflush(stdin);
    //getchar();
    printf("\nIngrese la cantidad: ");
    scanf("%d", &p.cantidad);
    printf("\nIngrese el precio: ");
    scanf("%f", &p.precio);
    return p;
}