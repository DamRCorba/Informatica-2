# Asignacion Dinamica de Memoria

## Introducción Teórica
### Pilas

Las pilas son estructuras de datos del tipo FILO, First In Last Out, o en español primero en entrar último en salir.

Una estructura de pila tiene la siguiente forma:

```c
typedef struct {
    datos_t misDatos;
    void *pila;
} pila_t;
```

En el ejemplo el puntero de pila es del tipo __void__ esto es porque al ser una definición de tipo, los compiladores no pueden utilizar un tipo de datos desconocido como el de *pila_t* que hasta ese momento no fue declarado.

> Recordemos que los punteros ocupan siempre el mismo tamaño de datos, y en la práctica no hay diferencia en el tipo de datos que se utilice para armar la estructura de pila. Una estructura de pila no usa a su puntero anterior para operar algebraicamente por lo que el tipo de datos del puntero queda en segundo lugar. 

El puntero "pila", apunta a la siguiente posición de la pila, o sea, al elemento de abajo. El primer elemento ingresado apunta a null.
En nuestro código tenemos un puntero que apunta siempre al último elemento, el más "nuevo", y este tiene en sus datos la información del elemento de abajo de él.

Entonces las pilas solo pueden recorrerse en un sentido para la carga y en sentido inverso para la lectura.

[Ver video de Pilas](https://youtu.be/N5KYT6z9WYo)

## TRABAJO PRÁCTICO

- __EJERCICIO 35__: 

    Hacer un programa que tome los datos de contacto de una persona (Nombre, Apellido, edad, teléfono, mail) y los cargue, en forma directa, en una pila de memoria dinámica. Imprimir en pantalla y cargar en un archivo llamado "contactos.dat", de organización secuencial, los registros ingresados por el usuario si la persona tiene una edad mayor a 21 años.


- __EJERCICIO 36__: 
    Existe un archivo llamado "datos.dat", de tipo binario, cuya organización es secuencial. Los datos están organizados según la siguiente estructura:   
                                                                                 
    ```c
    struct d{                                                                                            
    long clave; //Clave o Id del registro
    
    char d[30]; // Descripcion                                                                                          
    unsigned char tipo; //Tipo de datos como entero sin signo                                                                                                                                            
    char b; //'A':Alta 'B':Baja                                                                                                                                                                          
    }
    ```
                            
    Se Pide:
    Realizar una función que pase como parámetro la clave, entre otros parámetros, y apile dos valores, la Clave y su posición física respecto 
    al archivo (registro 1, 2, etc), si es que el campo tipo tiene el bit 4 con valor 1. En caso de no encontrarlo mostrar por pantalla "Registro no encontrado".
    La función debe devolver el puntero de pila.
    Realizar el main con varias llamadas a dicha función y proceder a mostrar las descripciones del archivo, mediante la pila como acceso directo, __NO USAR VARIABLES GLOBALES__.             
