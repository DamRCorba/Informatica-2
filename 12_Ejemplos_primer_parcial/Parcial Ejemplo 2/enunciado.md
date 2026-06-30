# Primer Parcial 
1) Existe un archivo llamado "notas.dat" de tipo binario cuya organización es secuencial con la siguiente estructura: 

```c
    {
        long legajo;        
        char materia[30];
        char nombreApellido[90]; // nombre, apellido
        int parcial; // 
        int nota;
    }
```


Se pide:
1. Realizar una función que recorra al archivo notas.dat y agregue en el archivo materias.dat, el registro correspondiente a un legajo, segun la siguiente estructura.
```c
    {
        long legajo;
        char nombreApellido[90]; 
        char materia[30]
        int parciales;        
    }

```
El campo parciales corresponde a una estructura binaria con el siguiente significado:
bit 0: Primer Parcial (1 Aprobado, 0 No Aprobado)
bit 1: Primer Parcial primer Recuperatorio (1 Aprobado, 0 No Aprobado)
bit 2: Primer Parcial segundo Recuperatorio (1 Aprobado, 0 No Aprobado)
bit 3: Segundo Parcial (1 Aprobado, 0 No Aprobado)
bit 4: Segundo Parcial primer Recuperatorio (1 Aprobado, 0 No Aprobado)
bit 5: Segundo Parcial segundo Recuperatorio (1 Aprobado, 0 No Aprobado)
bit 6: Trabajos practicos

Ademas, se pide crear una segunda funcion que recorra al archivo "materias.dat", creado por la funcion anterior, e imprima en pantalla el "Apellidos, Nombre" de los alumnos con la materias que regularizadas.

2)  A. Explicar:  
```c
if((5<<1) == 10 ) {printf("Son iguales")}else{son distintos}
```
    B. Cual es la diferencia entre una union y una estructura.
