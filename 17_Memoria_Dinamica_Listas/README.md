### Listas

Las Listas son estructuras de datos reversibles, las cuales pueden ser recorridas de igual modo que las pilas o en sentido inverso, permitiendo así un flujo del tipo FIFO, First In First Out, primero en entrar primero en salir o LIFO, Last In Last Out, ultimo en entrar, primero en salir. Suelen estar ordenadas bajo algun criterio de orden, como el orden de ingreso, alfabetico segun algun campo, etc.

La estructura de lista es:

```c
typedef struct {
    datos_t misDatos;
    void *sig;
    void *ant;
} lista_t;
```
> Recordemos que los punteros ocupan siempre el mismo tamaño de datos, y en la práctica, no hay diferencia en el tipo de datos que se utilice para armar la estructura de cola. Una estructura de cola no usa a su puntero para operar algebraicamente por lo que el tipo de datos del puntero queda en segundo lugar. 

Los punteros "sig" y "ant" apuntan al elemento siguiente y anterior de la lista respectivamente. Esto nos permite que un elemento de la lista sepa cuales son los elementos en ambos lados. El primer elemento ingresado siempre tendrá a su puntero "ant" apuntando a null. El último elemento de la cola siempre tendrá a su puntero "sig" apuntando a null. Esto es porque si es el primero no puede haber anterior y si es el último no puede haber siguiente. 
Sabiendo esto se puede recorrer la lista de extremo a extremo desde cualquier elemento perteneciente a ella.

[Ver video de Listas doblemente enlazadas](https://youtu.be/0uMAsex0iSQ)

## Práctica Propuesta

- __EJERCICIO 39__:

    Hacer un programa que lea al archivo "contactos.dat" creado en el __Ejercicio 35 (Pilas Clase 18)__  y crear una lista, en memoria dinámica, ordenada alfabéticamente. Una vez creada la lista guardarla en un archivo de organización directa llamado "contactos_ordenados.dat" imprimiendola en pantalla.
