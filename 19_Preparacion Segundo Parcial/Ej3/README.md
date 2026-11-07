# Parcial 2018

1) Existe un archivo llamado "datos.dat" de tipo binario cuya organización es directo con la siguiente estructura:

```c
    {
        long id;
        char descripcion[90]; 
        int tipo;
        char marca; // Marca 'A': Alta  'B': Baja)
    }

```

Se pide:

1. Realizar una función que pase como parámetro el id de la pieza, si el registro esta marcado como ‘A’ deberá modificar la descripción por  "Registro Procesado", marcarlo como ‘B’ en el archivo y apilar el registro. Si esta marcado como 'B' utilizando punteros cambiar la descripción las ‘a’ y ‘o’ por ‘e’,   encolando la descripcion y el id.
 No usar variables globales.
