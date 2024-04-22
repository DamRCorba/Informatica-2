# Funciones y Macros

Las *funciones* y las *macros* son conjuntos de instrucciones que realizan un tarea concreta y específica.


__Función Suma__

```c
int suma(int a, int b) {
  return a+b;
}

```
__Macro Suma__

```c
#define SUMA(a,b) a+b

```

## Qué los diferencia??

La función *suma* será llamada por el programa y estará alojada en una posición de memoria distinta del __main__.

La macro *SUMA* es analizada en tiempo de compilación y reemplazada por su valor en cada línea en la cual se la llama. Es mas bien como una plantilla de código que se pega en el llamado.

[Video explicación Funciones y Macros](https://youtu.be/0u-XpNgEWjU)

Como ejemplo de uso, les dejo una simple calculadora de suma y resta.

[Suma y Resta con Funciones y Macros](https://youtu.be/qpnC9uL4oqg)
[Suma y Resta con Funciones y Macros - Código](https://youtu.be/xhRpXDljQZ0)

## Ejercicios Propuestos.

- __Ejercicio 10__: Reescribir el __Ejercicio 5__ (*sistema de telemetría*) con funciones con pasaje por valor.
 > La función de inicializar los sensores no podrá hacerse en forma completa usando pasaje por valor.

- __Ejercicio 11__: Tomando el código del ejemplo de suma y resta, completar las operaciones matemáticas básicas.

- __Ejercicio 12__: Hacer una calculadora de *Ley de Ohm*. El usuario deberá poder cargar el par *Corriente-Tensión* o *Corriente-Resistencia* o *Tensión-Resistencia* y el programa deberá imprimir en pantalla *Corriente, Tensión, Resistencia y Potencia*.
[Video explicación](https://youtu.be/so-w99ZVPOg)
[Video Resolución](https://youtu.be/_EU9mQHhocw)
