#ifndef _FUNCIONES_H
#define _FUNCIONES_H 1

typedef struct {
    char sku[30];
    char descripcion[120];
    int  cantidad;
    float precio;
} producto_t;

int suma(int a, int b);

producto_t cargarProducto(void);



#endif