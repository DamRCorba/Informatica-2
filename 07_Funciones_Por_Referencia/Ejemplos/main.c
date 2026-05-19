#include <stdio.h>
#include "mi_string.h"
#include "funciones.h"



int main(int argc, char const *argv[])
{
    int resultado, a = 4, b = 12;
    char string[]= { "cualquier cosa" }, copia[] = {"otro cosa cualquiera"};
    producto_t producto;
    resultado = suma(a,b);

    printf("En main a=%d, &a=%x, b=%d, &b=%x\n", a,&a,b,&b);
    printf("La suma es %d\n", resultado);

    printf("String: %x, %s\n", &string[0], string);
    printf("La longitud del string es: %d\n", mi_strlen(string));

    mi_strcpy(copia, string);

    printf("%s\n", copia);
    mi_strcat(copia," fea");
    printf("%s\n", copia);
    mi_toUpperCase(copia);
    printf("%s\n", copia);
    mi_toLowerCase(copia);
    printf("%s\n", copia);
    printf("%d\n", mi_strcmp("cualquier cosa fea", "cualquier cosa fea"));
    printf("%d\n", mi_strcmp("cualquier cosa fea", "cualquier cosa"));
    printf("%d\n", mi_strcmp("cualquier cosa fea", "cualquie cosa fea"));

    producto = cargarProducto();
    printf("SKU: %s, Descripcion: %s, Cantidad: %d, Precio: %f\n", producto.sku, producto.descripcion, producto.cantidad, producto.precio);
    return 0;
}

