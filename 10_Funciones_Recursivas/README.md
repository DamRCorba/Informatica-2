
# Funciones Recursivas

Una función recursiva es una función que se llama a sí misma para resolver un problema dividiéndolo en subproblemas más pequeños. Para evitar llamadas infinitas, siempre debe existir un caso base, que es la condición que detiene la recursión y permite que las llamadas comiencen a retornar. La recursión es una técnica útil para recorrer estructuras como árboles, grafos o matrices, y para resolver problemas que pueden expresarse de forma repetitiva de manera natural.

## Practica Propuesta
Ejercicio de LeetCode

Resumen del problema "Number of Islands"

Se te proporciona una matriz bidimensional grid formada por caracteres '1' y '0', donde:

'1' representa tierra.
'0' representa agua.

Una isla está formada por una o más celdas de tierra conectadas horizontal o verticalmente (no en diagonal).

El objetivo es devolver la cantidad total de islas presentes en la matriz.

Ejemplo

Entrada:
```c
[
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]
```
Salida:
```c
3
```
Explicación:

La primera isla está formada por las cuatro celdas de la esquina superior izquierda.
La segunda isla es la celda del centro.
La tercera isla está formada por las dos celdas de la esquina inferior derecha.

En C, la función que debes implementar suele tener la siguiente firma:
```c
int numIslands(char** grid, int gridSize, int* gridColSize);
```
Si estás practicando para una entrevista o para LeetCode, también puedo mostrarte cómo llegar a la solución paso a paso, sin escribir directamente el código final.