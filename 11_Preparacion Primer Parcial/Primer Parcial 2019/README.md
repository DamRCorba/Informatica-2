# Primer Parcial 2019

1) Existe un archivo Binario de organización secuencial con la siguiente estructura:

```c
{
    long id;
    char categoria[90];
    float valor;
    unsigned int estado;
}
```

Realizar una funcion que pase como parametro el id, la funcion debe ubicar al registro, si no lo encuentra retorna un 0. Una vez encontrado utilizando puntero recorre la categoria colocando en mayuscula y regrabar el registro si el bit 3 del campo estado esta en 1. En este caso retornara la cantidad de registros restantes desde que se encontro el registro. (Ejemplo: si hay 100 registros y la clave pasada es 10 retoranara 90.)

2) Teoricos

- A. Explicar: Relacion entre un vector y un puntero.
- B. Que implica un error cuando abrimos un archivo en modo "W".
