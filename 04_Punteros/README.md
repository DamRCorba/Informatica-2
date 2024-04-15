# Punteros

Los punteros son variables que apuntan a una dirección de memoria.


__*Declaración*__


A los punteros se los define con el tipo de variable a apuntar, el simbolo '\*' y el nombre de la variable.

Por ejemplo:
```C
char *pc;
int *pi;
struct datos *psd;

```

Con esto, __pc__, __pi__ y __psd__, estarán apuntando a una posición de memoria cualquiera.

##### Por qué se los define con un tipo de datos si siempre apuntan a una posición de memoria?

[Video Explicación y Ejemplo](https://www.youtube.com/watch?v=EcT7UzmZjn0)

[Ejemplo de Buffer Circular](https://www.youtube.com/watch?v=JjrnypxaTtw)

## Ejercicios Propuestos

- __Ejercicio 7__: Realizar la carga de la matríz 8x5 del __Ejercicio 6__ usando un puntero.

- __Ejercicio 8__:  Partiendo del código del __"Ejemplo de Buffer Circular"__ y usando punteros, darle a elegir al usuario si quiere mostrar la función seno, o una función triangular.
> Se deberá tomar las muestras de una señal triangular como se hizo en el ejemplo.

- __Ejercicio 9__: Una empresa pasa a buscar a sus empleados en un transporte privado. Las personas suben en distintos horarios, 8 am, 9 am y 10 am. Se piden crear las estructuras de datos para las __personas__, que contenga, nombre, dirección y hora entre otros. También se tiene que crear una estructura para el transporte la cual contiene: patente, chofer y un vector de __personas__ que viajaran en ella, entre otros.
Usando punteros realizar la lógica para que se imprima en pantalla la información según:
  - Pasajero
  - Patente
  - Horarios

  > Aclaración: Puede haber mas de una persona en un mismo horario lo cual implica, mas de una patente. Como ayuda hacer vectores con la estructura de transporte y con la de personas.
  > Hacer validaciones a criterio.
