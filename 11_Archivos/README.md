# Archivos

Muchas veces necesitamos que nuestro programa guarde información en forma persistente. El mecanismo más simple es utilizando archivos de datos que nuestro programa debe poder administrar. Para ello tendremos, además de nuestros archivos de código, algunos archivos adicionales, los cuales pueden ser de datos, de texto, o cualquier otro formato que necesitemos.


## Tipos de Archivos

Hay una gran variedad de tipos de archivos y cada uno tiene su particularidad. A lo largo del curso nos centraremos en dos de ellos:
- Archivos de texto
- Archivos de datos

Pero con el mismo mecanismos podemos utilizar archivos de imagen, audio, video, etc..

Lo que diferencia a los archivos, además de su extensión, es el encabezado que tienen. Los archivos comienzan con un encabezado el cual contiene información relacionada con su estructura de datos.

En el caso de los archivos de imagen, tendrá el formato, compresión, paleta de colores, tamaño, etc..

### Archivos de Texto

Los archivos de texto contienen texto en código ASCII. Si los abrimos con un editor de texto podemos ver su contenido, y leerlo.

Todo lo que leamos de estos archivos, desde nuestro programa, son cadenas de cadenas de caracteres o caracteres.

### Archivos de Datos

Los archivos de datos contienen información con una estructura definida por el programador.

 No se puede ver su contenido con un editor de texto, ya que la información no siempre es texto.
 Para poder leerlos correctamente necesitamos conocer su estructura de datos.

### Como utilizar Archivos en C?

Los archivos se guardan en diferentes directorios, los cuales son administrados por el Sistema Operativo dependiendo del sistema de archivos del medios físico.

Sobre una PC, los archivos se guardan en una posición de memoria en el medio físico. Por lo cual, se puede usar un puntero a esa posición de memoria para acceder a su información.

Los punteros de archivos se declaran con tipo FILE.
```c
FILE *punteroArchivo;
```
El __ \*punteroArchivo __ se lo carga con la función __fopen__.

```c
FILE * fopen (const char *NombreArchivo, const char *TipoDeApertura);

```
Los archivos tienen varios modos de apertura.
  - __Solo Lectura__
    >Parámetro __"r"__ Abre al archivo, si este existe, en modo Solo Lectura.
    Para archivos de texto __"rt"__. Para archivos de datos __"rb"__.

  - __Solo Escritura__
    >Parámetro __"w"__ Abre al archivo en modo Escritura, si no existe lo crea, si existe crea uno nuevo pisando al anterior.
    Para archivos de texto __"wt"__. Para archivos de datos __"wb"__.

  - __Solo Concatenación__
    >Parámetro __"a"__ Abre al archivo en modo Escritura, si no existe lo crea, si existe ubica al puntero al final del archivo para continuar insertando datos.
    Para archivos de texto __"at"__. Para archivos de datos __"ab"__.

  - __Lectura y Escritura__     
    >Parámetro __"r+"__ Abre al archivo, si este existe, en modo Lectura y Escritura.
    Para archivos de texto __"rt+"__. Para archivos de datos __"rb+"__.

  - __Escritura y Lectura__
    >Parámetro __"w+"__ Abre al archivo en modo Escritura y Lectura, si no existe lo crea, si existe crea uno nuevo pisando al anterior.
    Para archivos de texto __"wt+"__. Para archivos de datos __"wb+"__.

  - __Concatenación y Lectura__
    >Parámetro __"a+"__ Abre al archivo en modo Escritura, si no existe lo crea, si existe ubica al puntero al final de este para continuar insertando datos.
    Para archivos de texto __"at+"__. Para archivos de datos __"ab+"__.

### Ejemplo

[Ver Video de Ejemplo](https://youtu.be/eJB8sAo-tS0)

### Práctica Propuesta

__Ejercicio 18__: Usando la función *init_sensors* del ejercicio de [Telemetría con Pasaje por Referencia](https://youtu.be/Gwi7xPKqozs), crear un archivo de datos que contenga a la información de los 4 sensores guardados.

__Ejericio 19__: Guardar en un archivo la estructura creada para el ejemplo de dibujo de caracteres.

__Ejericio 20__: Leer el archivo creado en el __Ejercicio 19__ y dibujar el caracter en pantalla.

__Ejericio 21__: Guardar en el archivo del __Ejercicio 19__ todos los caracteres necesarios para imprimir el nombre "COSME" y una vez guardado usarlos para dibujarlo en pantalla.
