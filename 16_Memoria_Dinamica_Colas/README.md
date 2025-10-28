# Asignacion Dinamica de Memoria

## Introducción Teórica
### Colas

Las colas son estructuras de datos del tipo FIFO, First In Fast Out, o en español primero en entrar primero en salir.

Una estructura de cola tiene la siguiente forma:

```c
typedef struct {
    datos_t misDatos;
    void *cola;
} cola_t;
```

En el ejemplo el puntero de cola es del tipo __void__ esto es porque al ser una definición de tipo, los compiladores no pueden utilizar un tipo de datos desconocido como el de *cola_t* que hasta ese momento no fue declarado.

> Recordemos que los punteros ocupan siempre el mismo tamaño de datos, y en la práctica no hay diferencia en el tipo de datos que se utilice para armar la estructura de pila. Una estructura de pila no usa a su puntero anterior para operar algebraicamente por lo que el tipo de datos del puntero queda en segundo lugar. 

El puntero "cola", apunta a la siguiente posición de la cola, o sea, al elemento de atras. El ultimo elemento ingresado apunta a null, y el primero apunta al segundo.

Entonces las colas solo pueden recorrerse en un sentido para la carga y en sentido inverso para la lectura.

[Ver video de Colas](https://www.youtube.com/watch?v=HXF2VXBWzd0)


## Práctica Propuesta


- __EJERCICIO 37__:
  Hacer una cola con los valores muestreados de un cuarto de ciclo de una señal sinusoidal, en 8 bits, para luego recorrerla y recomponer la señal completa. Las muetras deberán ir de 127 a -127 utilizando el bit más significativo en 1 para los valores negativos y en 0 para los valores positivos. Imprimir en pantalla los valores.

- __EJERCICIO 38__: 
    Hacer un programa que tome los datos de contacto de una persona (Nombre, Apellido, edad, teléfono, mail) y los cargue, en forma directa, en una cola de memoria dinámica. Imprimir en pantalla y cargar en un archivo llamado "contactos.dat", de organización secuencial, los registros ingresados por el usuario si la persona tiene una edad mayor a 21 años.
    > Es el ejercicio 35 pero con una cola en lugar de una pila.