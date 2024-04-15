# Clase 02 - Estructuras y Declaración de Tipos

## Estructuras

Las estructuras son colecciones de variables relacionadas bajo un nombre. A diferencia de los arreglos, una estructura puede contener diferentes tipos de datos.

```c
struct persona {
  char nombre[20];
  int edad;
  long dni;
  bool esDonante;
  int numerosDeSuerte[10];
};
```
En el ejemplo anterior vemos como la estructura __persona__ contiene diferentes tipos de datos. Se debe aclarar que es solo una declaración, es decir, no está reservando memoria ni asignando una variable. En este caso la palabra __persona__ es una __ETIQUETA__ que me permitirá, invocandola, declarar variables que respeten a esa estructura.

```c

struct persona cliente1;
struct persona clientes[20];
```
Con esta línea de código estoy creando una variable __cliente1__ del tipo struct persona. Además, se declaró un vector, __clientes__ que también respetará a la estructura de datos.

```c
// Para el caso del vector
strcpy(clientes[0].nombre, "Cosme Fulanito");
clientes[0].edad = 21 ;
clientes[0].numerosDeSuerte[0] = 11;

// Para la variable
cliente1.dni = 38123456;
cliente1.esDonante = TRUE;
```
En el ejemplo anterior podemos ver como acceder a cada uno de los campos. Como regla general se usa el nombre de la variable seguida por el símbolo "." seguido por el subtipo, o campo, contenido en la estructura.
Cada campo se comporta según el tipo de datos propio del subgrupo. Si el campo es una cadena, entonces se deberá tratar como una cadena.

Pueden notar que una vez declarada la estructura no se volvió a llamar a __struct persona__ salvo en la declaración de las variables.

En caso de que mi estructura solo defina a una variable, puedo declararla sin su etiqueta.
```c
struct {
  int x;
  int y;
}puntos[3];

```
Así declaro un vector de tres posiciones que respeta la estructura. Notar que la etiqueta tiene un sentido práctico, aunque opcional. El ejemplo más inmediato se da con estructuras anidadas. Si ahora que tenemos a nuestra estructura persona, necesitamos también declarar a una estructura profesor, el cual también es una persona, podriamos hacer lo siguiente.

```c
struct profesor {
  char materia[40];
  struct persona datosPersona;  
}profesorAyudante;

strcpy(profesorAyudante.materia, "Informatica 2");
strcpy(profesorAyudante.datosPersonales.nombre, "Damian");

```
Se trata de una reutilización de la estructura.


## Definición de Tipos

Sabemos que en "C" existen diferentes tipos de variables.

| Tipo          | Bytes |  Valor Minimo | Valor Maximo  |
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

Muchas veces nos resulta conveniente, o incluso necesario, definir nuestros propios tipos de variables, por una cuestión de compatibilidad entre plataformas, por claridad en código, etc..

Para poder declarar nuestro propio tipo de datos usamos la palabra reservada __typedef__

```c
typedef  unsigned char uint8_t;
/*typedef <Tipo de dato> <nombre nuevo tipo de dato>*/

/* Luego podremos declarar nuestras variables enteras sin signo de 8 bits,
   utilizando nuestro nuevo tipo de datos.*/

uint8_t puertoA;
puertoA = 100;
```

#### *Se debe destacar que es una buena práctica anexar "\_t" a la etiqueta de nuestro tipo de dato, además de declarar a las estructuras como un tipo definido.*



```c
typedef struct {
  char nombre[20];
  int edad;
  long dni;
  Bool esDonante;
  int numerosDeSuerte[10];
} persona_t;

typedef struct {
  char materia[40];
  persona_t datosPersona;  
} profesor_t;

```

Con __typedef__ declaramos un tipo de datos y no una variable.

Prestar mucha atención: tanto persona_t como profesor_t __NO SON VARIABLES__, sino __*tipos de datos*__. Se sigue respetando la sintáxis <code> typedef < Tipo de dato > < nombre nuevo tipo de dato > </code>


```c
/*|typedef| Tipo de Dato | Nombre del nuevo tipo de datos | */
   typedef  unsigned char uint8_t;


/*|typedef|                       Tipo de Dato                | Nombre del nuevo tipo de datos | */
   typedef struct { char materia[40]; persona_t datosPersona; } profesor_t;

```

## Ejemplos
- [Ejemplo 1](https://github.com/DamRCorba/Informatica2_2023/tree/master/02_Estructuras/ejemplos/Ejemplo1)
> Matríz RGB - Imagen 320x240

- [Ejemplo 2](https://github.com/DamRCorba/Informatica2_2023/tree/master/02_Estructuras/ejemplos/Ejemplo2)
> Dibujo de Caracteres, display dotMatix 8x8


## Ejercicios Propuestos

> Ejercicios 1,2 y 3 pertenecen a la clase 01

__Ejercicio 4:__
  En la Clase01/Ejemplo 2, realicé una matríz de productos. En el Ejercicio 3 propuse ordenarla por columna a elección del usuario. Esto tenía un problema para ordenar los tipos de datos __string__ que representaban números.

  El ejercicio 4 es entonces: rehacer el código utilizando estructuras.

  Hacer una ~~Matriz~~ __*estructura*__ que contenga hasta 9 productos. Cada fila ~~de la matriz~~ deberá contener *Nombre*, *Cantidad*, *Precio* y *Código*. Luego Imprimir en pantalla ordenandola por columna según la elección del usuario.

  > Como referencia les dejo el ejercicio 3 resuelto con matríz y explico el problema de ordenarla de esta forma: [Video Explicación](https://youtu.be/HkA7FldDdTA) - [Video de Resolución](https://youtu.be/7KCB4mw5SWs)


  __Ejercicio 5:__
   En un sistema de telemetría, se tiene un bus de datos serial con 4 dispositivos. Cada uno de ellos tendrá una dirección conocida. Se pide diseñar una estructura de datos que contenga, *direccion*, *comando* y *dato* cada uno de ellos de 8 bits. Para simularlo el usuario ingresará los tres valores y el programa le imprimirá en pantalla la respuesta del dispositivo.
    - [Video Explicación](https://www.youtube.com/watch?v=4mHLw2v21KM)
    - [Video Resolución](https://www.youtube.com/watch?v=Ei5p7c98AbE)

__Ejercicio 6:__
  Partiendo del Ejemplo 2 (*Dibujo de Caracteres*), escribir su nombre en pantalla dibujado por un dotMatrix 8x5
