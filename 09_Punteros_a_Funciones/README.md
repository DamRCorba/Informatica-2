# Punteros a Funciones

## Introducción Teórica

Un Puntero es una variable que apunta a la dirección de memoria de otra variable.
Un Puntero a función, es una "variable" que apunta a la dirección de memoria de una función.

__*Declaración*__

Para declarar un puntero a función se tiene que definir el prototipo de la función a las que apuntará, así como haciamos con el tipo de variable en los punteros convencionales.

Por ejemplo:

```c
int (*operacion_matematica) (int, int);

```
Podría apuntar a funciones con prototipo <code>int nombre(int, int);</code> pero no podría apuntar a <code>void nombre(char \*);</code>

Como regla general y limitante, un puntero a función solo podrá apuntar a una función con su mismo prototipo.

[Ver Video explicación](https://youtu.be/PiBh0aDSAP8)

- __Ejemplo__: Calculadora con punteros a funciones. [Ver Video](https://youtu.be/Ww7HoakDKcE)

### Práctica Propuesta

- __Ejercicio 16__: Reescribir el __Ejericio 12__ ([Ver video - Ley de Ohm](https://youtu.be/_EU9mQHhocw)) utilizando punteros a funciones tanto para el ingreso de los datos como para su cálculo.

- __Ejercicio 17__: Hacer un vector de punteros a Funciones que realice la interpretación del mensaje en el ejercicio de Telemetría. ([Ver Vídeo - Telemetría con Pasaje por Referencia](https://youtu.be/Gwi7xPKqozs))
