# Parcial 2018

1) Existe un archivo llamado "datos.dat" de tipo binario cuya organización es secuencial con la siguiente estructura:

```c
    {
        long id;
        char descripcion[90]; 
        int tipo;
        char marca; // Marca 'A': Alta  'B': Baja)
    }

```

Se pide:

1. Realizar una función que pase como parámetro el id de la pieza, si el registro esta marcado como ‘A’ deberá modificar la descripción por  "Registro Procesado", marcarlo como ‘B’ en el archivo y retornar el registro. Si esta marcado como 'B' utilizando punteros cambiar la descripción las ‘a’ y ‘o’ por ‘e’,   retornando el registro y grabándolo en el archivo "baja.dat" .
 No usar variables globales.

2) A. Explicar: que relación hay entre un puntero y un vector en lenguaje c
     B. Que es una clave primaria compuesta.
