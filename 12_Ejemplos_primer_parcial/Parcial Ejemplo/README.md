# Primer Parcial

1) Exite un archivo de organización secuencial, llamado temperatura.dat, con la siguiente estructura:

```c
{
    long timestamp;
    char descripcion[90];
    float temperatura;
    float temperatura_alarma;
    int tipo;     
}
```
Se sabe que cuando los bits 5 y 7 del campo tipo estan en 1 indican que el sensor es de tipo creciente, es decir que la temperatura no debe superar la temperatura de alarma. Por otro lado, si los bits 4 y 6 estan uno el sensor es decreciente, osea que la temperatura no debe ser inferior a la de alarma.

Se pide, realizar una funcion, que reciba el tipo (C o D) y el nombre del archivo de salida,recorra al archivo y se la use para crear los archivos de creciente.dat y decreciente.dat que contenga la misma estructura del archivo original agregandole el campo de alarma char estado; //A - Alarmado, N - Normal. En caso de error la funcion debera devolver 1, caso contrario 0.

NO SE PUEDEN USAR VARIABLE GLOBALES NI FUNCIONES STRING.

2) Teoricos
- A. Explicar, que son los parametros de una funcion. ¿Como funciona el pasaje por valor? ¿Como funciona el pasaje por referencia?
- B. Que implica un error cuando abrimos un archivo en modo "R".
