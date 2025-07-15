# Máquinas de Estado

Las Máquinas de estado o *Finite State Machines (FSM)* son abstracciones matemáticas usadas para diseñar algoritmos.
Se las representa por medio de un *diagrama de estados y transiciones*. Cada estado es una función y las transiciones son los posible caminos que puede tomar la máquina.

En el sentido estricto una máquina de estado lee sus entradas y variables, evalua la condición en el estado que se encuentra y cambia de estado.

![./recursos/fsmgenerica.png](https://github.com/DamRCorba/Informatica-2/blob/main/13_TrabajoPractico/recursos/fsmgenerica.png)

Cada circulo representa un estado y cada flecha representa a una transición.

El primer estado que tenemos, sobre todo en sistemas embebidos, es el estado de __inicio__ donde se configuran los periféricos necesarios y se toman los valores necesarios de configuración.

Una vez inicializado pasará al primer estado, que por lo general es un estado de __espera o idle__. En cada estado se leen las entradas y/o variables que condicionan la permanencia. En el caso de la figura se  verifica la condición booleana de *A* y mientras que esta sea falsa no se moverá al siguiente estado.

En cada estado se leen las entradas para evaluar si tiene que mantenerse o cambiar. Además, cada estado ejecuta una acción específica dependiendo de la finalidad de la máquina.

Como regla general para convertir el diagrama en código basta con seguir unas reglas.

- Cada estado es una función de estado la cual debe llamarse igual que el estado del diagrama.
- Cada función de estado devuelve un estado.
- Después del inicio se tiene un bucle infinito que contiene la lógica de la máquina.
- Switch case o punteros a funciones puede ser utilizado para ejecutar a cada estado de la máquina.

## Ejemplo

- Control de Temperatura.

### Memoria descriptiva
Mi sistema representa un control de temperatura ON-OFF con temperatura y delta configurable. Se mantiene la tempertura configurada utilizando el encendido y apagado de un elemento calefactor. La tempertura es leída por un único sensor. A fines didácticos el sensor y el elemento calefactor son emulados.

Primero el sistema calienta mientras que la temperatura sea menor a la configurada *más* el delta y vuelve a calentar cuando la temperatura sea inferior a la configurada *menos* el delta.

### Máquina de estado de Control de temperatura

 ![./recursos/fsmtemperatura.png](https://github.com/DamRCorba/Informatica-2/blob/main/13_TrabajoPractico/recursos/fsmtemperatura.png)

 - __SET__: Bandera de fin de inicialización
 - __t__: temperatura leida
 - __t_set__: Temperatura configurada
 - __deltaT__: Delta de tempertura

### Código

- Archivo de cabecera __mylib.h__

```c
#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

typedef enum {
  espera = 0,
  calentar = 1
}estados_t;

typedef struct {
  char t;         // temperatura actual
  char t_set;     // temperatura seteada
  char deltaT;    // Delta de temperatura
}temperatura_t;

temperatura_t f_inicio(void); // lee el archivo de configuración y carga las variables.
estados_t f_espera(temperatura_t);
estados_t f_calentar(temperatura_t);



#endif

```

- Archivo __main.c__
> con Switch case

```c
#include "mylib.h"

int main() {
    temperatura_t config;
    estados_t estado = espera; // primer estado

    config = inicio();
    while(1){
      switch (estado) {
        case espera: estado = f_espera(config);
                     break;
        case calentar: estado = f_calentar(config);
                       break;
      }
    }
  return 0;
}

```
 > Con Punteros a funciones

 ```c
 #include "mylib.h"

 int main() {
     temperatura_t config;
     estados_t estado = espera; // primer estado
     estados_t (*fsm[])(tempertura_t) = {f_espera, f_calentar}
     config = inicio();
     while(1) estado = (*fsm[estado])(config);

   return 0;
 }

 ```
- Archivo __config.conf__

```bash
# Temperatura de trabajo
t_set 24
# Delta de temperatura
deltaT 2
```

## Trabajo Práctico

El trabajo práctico es guiado, presentandose en etapas, con fechas sugeridas para cada entrega, con el fin de concluirlo durante la cursada.
Este trabajo práctico es obligatorio para la aprobacion y promocion de la materia. Para la promocion de la materia tiene que estar aprobado antes de Diciembre.
Se debe crear un proyecto nuevo en su GitHub, las entregas se hacer por ese medio.

- Elección del sistema a modelar.
> Tema a elección del alumno.

- Diagrama de máquina de estado y memoria descriptiva: __Fecha de entrega 25 al 29 de Agosto__
> La memoria descriptiva, es la explicación textual y teórica del funcionamiento del sistema.

- Primer versión de código: __Fecha de entrega de 6 al 10 de Octubre__
> Resolución de la mecánica de la máquina de estado sin funciones especificas.

- Segunda versión de código: __Fecha de entrega de 3 al 7 de Noviembre__
> Resolución de la mecánica de la máquina de estado con funciones especificas.

- Código final: __Fecha de entrega 25 al 29 de Noviembre__
> Código Final con punteros a versiones y correcciones de Buenas Costumbres

#### Lineamientos Generales

- Iniciar el sistema configurandolo con un archivo de configuración tipo Texto.

- Archivos de librería con definiciones del sistema.

- Grupos de funciones separados en archivos fuentes.

- Uso de punteros a funciones.

- Buenas prácticas de programación en c.

- Presentación en GitHub.

#### Sistemas sugeridos

El tema es de libre elección, pero a continuación hay una lista de temas para guiarlos, que también los pueden elegir.

- Control de temperatura cámara frigorífica
> Con alarmas y avisos

- Puerta automática

- Semáforo

- Control de barrera paso a nivel

- Control de puente levadizo

- Control de acceso

- Control de estacionamiento

- Contador de personas con aviso y alarmas

- Control de iluminación

- Control de protección de sobre tensión

- Control de llenado de tanque de agua

- Cinta transportadora con clasificación


