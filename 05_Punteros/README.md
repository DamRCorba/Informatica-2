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


- __Ejercicio 9__:  Escribí un programa en C que lea una palabra desde el teclado y calcule su longitud (cantidad de caracteres) sin usar strlen ni corchetes ([]).
  > Recorrer la cadena usando punteros, avanzando carácter por carácter hasta encontrar el carácter nulo ('\0').
  
  Ejemplo:
  ```yaml
  Ingrese una palabra: programar
  La palabra tiene 9 caracteres.
  ```
- __Ejercicio 10__:  Realizar un programa en C que lea una palabra, la copie a otra variable usando punteros (sin usar strcpy ni []), y luego muestre el resultado de la copia.
  > Usá aritmética de punteros (*p = *q) y no accedas con índices.
  
   Ejemplo:
  ```yaml
  Ingrese una palabra: hola
  Copia: hola
  ```
- __Ejercicio 11__:  Realizar un programa en C que lea dos palabras (por ejemplo, nombre y apellido) y las concatene en una tercera variable, sin usar strcat ni corchetes ([]).
  >Primero copiá la primera palabra, luego agregá un espacio, y finalmente copiá la segunda palabra, todo con punteros.
  ```yaml
  Ingrese el nombre: Cosme
  Ingrese el apellido: Fulanito
  Nombre completo: Cosme Fulanito
  ```