# Organización de Archivos

## Organización Secuencial de Archivos

Los archivos secuenciales contienen datos estructurados en forma consecutiva. Los datos cargados se  encuentran en el orden en que se los cargo.
La única forma de poder encontrar un dato dentro de ellos es recorriendolos en forma secuencial hasta encontrarlo.

Una estructura de datos secuencial es:
```c
typedef struct {
  char nombre[30];
  char ISBN[15];

} libro_t;

```
[Ver video Organización Secuencial](https://youtu.be/xnTXMSQVCzY)
## Organización Directa de Archivos

Los archivos de de Organización directa tienen un orden o *ID* que da su ubicación dentro del archivo. Estos archivos tienen la particularidad de permitir el acceso directo a un registro

Una estructura de datos directa es:
```c
typedef struct {
  long legajo;
  char nombre[30];
  int edad;

} alumno_t;

```
[Ver video Organización Directa](https://youtu.be/6lST8lXtxtk)
### Práctica Propuesta

__Ejercicio 22__: Analizar y hacer los arreglos necesarios para que el *Ejercicio 19* sea un archivo de Organización directa.

__Ejericio 23__: Existe un archivo secuencial *datos.dat* con la siguiente estructura: id (int), nombreyapellido (cadena char), nota (float) y b(char A: alta B: baja)
> Nota el nombreyapellido se escribe separado por una coma. Ejemplo: “Juan, Pérez”.

Hacer una función que reciba como parámetro una cadena conteniendo parte del nombre del registro y  retorne un entero.
La función debe buscar todos los registros del archivo que coincidan con parte del nombre, omitiendo los dado de baja, y cada registro encontrado lo guarda en un archivo *nuevo.dat*, el cual también tiene que ser creado por la función.
El nuevo registro guardado solo debe contener el *id* y el nombre, sin el apellido. La función devuelve el número de registros archivados.


__Ejericio 24__: Existe un archivo binario de organización secuencial con la siguiente estructura:
id[6] (char), descripcion[60] (char), valor (float), estado (unsigned char).
> Nota: El id Alfanumerico es por ejemplo: "A0023"

Realizar una función que reciba como parámetro id que busque al registro y si no lo encuentra devuelva -1. Una vez ubicado, utilizando punteros, recorrer la descripción cambiando la letra 'a' por la letra 'e' y regrabar el registro. En este caso devuelve la posición en la que está guardado el registro.
