# Clase 01 - Arreglos y Cadenas

## Arreglos

Los arreglos son estructuras de datos de un mismo tipo. Los definimos como vectores, tambien llamados arrays, o matrices.

```c
int a[5];     // Define un vector de tipo entero de logitud 5
float b[7];   // Define un vector de tipo float de logitud 7
char c[20];   // Define un vector de tipo caracter de longitud 20
unsigned int m[5][5]; // Define una matriz de 5x5
long l[] = {1,23,456,7678,123124}; // Definicion de un array de 5 posiciones precargado
```

Como ven en los ejemplos la declaración de los arreglos es muy simple. Los arreglos a, b, c y m no tienen valor inicial y solo reservan el espacio en memoria. El arreglo l carga su valor inicial y reservara el espacio de memoria necesario para poder guardar su contenido. En este caso reservara 20 bytes.

> Porque 20 Bytes? Una variable long tiene una longitud de 4 Bytes x 5 posiciones = 20 Bytes
>
> Recordemos que cada tipo de de datos en C tiene un tamaño.
>
| Tipo          | Bytes |  Valor minimo | Valor Maximo  |
| :------------ | :---- |:------------- |:------------- |
| Bool          | 1     |             0 |             1 |
| char          | 1     |          -128 |           127 |
| unsigned char | 1     |             0 |           255 |
| int           | 2     |        -32768 |         32767 |
| unsigned int  | 2     |             0 |         65535 |
| long int      | 4     |   -2147483648 |    2147483647 |
| unsigned long | 4     |             0 |    4294967295 |
| Float         | 4     |   1.17579e-38 |   3.40282e+38 |
| Double        | 8     |  2.22507e-308 |  1.79769e+308 |

Para poder leer o escribir valores en el arreglo debo hacerlo en cada uno de sus componentes en forma individual.

```c
a[0] = 5; // Carga el valor 5 en la primer posicion del arreglo a.
printf("%l", l[1]); // Imprime en pantalla al segundo valor cargado en l, en este ejemplo 23.

```

No se pueden comprar dos arreglos, pero si se puede comprar a cada uno de sus elementos
```c
if (a == b) // Error No se puede comprar dos arreglos.

if(a[0] == m[3][1]) // si se puede comparar dos elementos de arreglos diferentes

```

- __Ejemplo de Vectores:__

  [Ejemplo Vectores](https://github.com/DamRCorba/Informatica2_2023/tree/master/00_Repaso_Informatica_1/ejemplos/vectores)

- __Ejemplo de Matrices:__

  [Ejemplo 1](https://github.com/DamRCorba/Informatica2_2023/tree/master/00_Repaso_Informatica_1/ejemplos/matrices/Ejercicio1)

  [Ejemplo 2](https://github.com/DamRCorba/Informatica2_2023/tree/master/00_Repaso_Informatica_1/ejemplos/matrices/Ejercicio2) - [Video-Explicación](https://youtu.be/Y1UfYJMelUU) - [Video-Resolución](https://youtu.be/xac4eQmZup8)


## Cadenas

Una cadena de caracteres es un caso particular de uso de un vector. A nivel variable no tiene diferencias, solo cambia la codificación del dato que se guarda. Las cadenas tienen la codificación ASCII, por lo que sus valores son númericos pero correspondientes a esta codificación.
El abecedario en mayusculas, en minusculas, los numeros y los caracteres especiales estan dentro del codigo ASCII contenido por una variable char (0 - 127) es por eso que normalmente se usa este tipo de variable. En realidad Char es una tipo de datos enteros, pero resulta conveniente para el manejo de texto.

Sobre ellas rigen las mismas reglas que para los arreglos. No se las puede comparar entre si, se las debe cargar elemento por elemento, etc. Por suerte, para este uso particular, tenemos la libreria __string.h__ que nos da un set de funciones para trabajar con ellas.

- __Ejemplo de Cadenas:__

[Ejemplo Cadenas](https://github.com/DamRCorba/Informatica2_2-12_2022/tree/master/00_Repaso_Informatica_1/ejemplos/cadenas)

## Ejercicios Propuestos

Ejercicio 1:

Hacer un programa que, utilizando vectores, cargue 10 números enteros ingresados por el usuario e imprima en pantalla la sumatoria de ellos.

Ejercicio 2:

Hacer un programa que, utilizando vectores, cargue 5 números inferiores a 100, ingresados por el usuario, y los imprima en forma recursiva según orden de ingreso.

Ejercicio 3:

Hacer un programa, que ordene a la matríz del Ejemplo 2 por orden ascendente y descendente según: Nombre, Código o Cantidad dependiendo de la elección del usuario. [Video-Explicación](https://youtu.be/HkA7FldDdTA) [Video-Resolución](https://youtu.be/7KCB4mw5SWs)
