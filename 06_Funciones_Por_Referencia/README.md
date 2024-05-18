# Funciones con Pasaje Por Referencia

## Cuando se usa?

Cuando usamos como parámetros de función a un puntero para trabajar con la variable original en la función llamada.

```c
void funcionEjemplo(char *x);

```
La función __funcionEjemplo__ estará recibiendo a un puntero __x__ el cual contiene una posición de memoria. Todo lo que hagamos sobre \*x se modifica directamente sobre la variable original.

Si lo que vamos a hacer es modificar el valor de la variable original, la función trabaja sobre el original y no necesita retornar valores ya que la modificación ya se hace sobre la original.

En caso de querer mantener al valor original inalterable, deberemos trabajar sobre una copia y devolver el resultado.

-  __Ejemplo__ - En el ejercicio de Telemetría, ahora crearé una función que inicialice a todos los sensores usando pasaje por referencia. [Ver Video con función con pasaje por referencia](https://youtu.be/Gwi7xPKqozs)

### Práctica Propuesta

- __Ejercicio 13__: Hacer una función que reciba una cadena, por ejemplo: "Fulanito, Cosme" y la modifique por "Cosme Fulanito", modificando al vector original.


- __Ejercicio 14__: Partiendo del ejercicio anterior, modificar la función para que devuelva al main la cadena modificada pero sin alterar a la original.


> __*Ayuda*__:  *Utilizar las funciones de la libreria __string.h__*
  - strcpy(destino, origen) - Copia la cadena origen en destino
    Ejemplo: strcpy(cadenaDestino,"sarasa"); -- en *cadenaDestino* quedará guardado "sarasa"
  - strcat(destino, origen) - Concatena la cadena origen en destino
    Ejemplo: strcat(cadenaDestino," ejemplo"); -- en *cadenaDestino*
    quedará "sarasa ejemplo" (suponiendo que antes tenia guardado el valor "sarasa")

- __Ejercicio 15__: Modificar al __Ejercicio 11__ (calculadora simple) pero en lugar de hacer funciones que reciban parámetros y devuelvan el resultado, hacer funciones que reciban a la posición de memoria de las variables originales y retornen el resultado.
