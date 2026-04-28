# Libreria String.h

La librería string se contiene diversas funciones para el manejo de cadenas de caracteres. Entre ellas podemos contar con:

***strlen***
```c
size_t strlen(const char *str);
```
Mide la longitud de la cadena str
__Devuelve__ 
- La longitud de la cadena.


## Funciones de comparación de cadenas

Las cadenas son vectores, por lo que no se las puede comparar en forma directa. Se lo deberia hacer elemeanto por elemento o con las siguientes funciones.

- ***strcmp***
    ```c
    int strcmp(const char *str1, const char *str2);
    ```
    Compara a la cadena 1 con la cadena 2
    __Devuelve__ 
    - valor menor a 0 si str1 es menor que str2
    - valor mayor a 0 si str1 es mayor que str2
    - valor igual a 0 si str1 es igual que str2

- ***strncmp***
    ```c
    int strncmp(const char *str1, const char *str2, size_t n);
    ```
    Compara los primeros n elementos de la cadena 1 con la cadena 2 
    __Devuelve__ 
    - valor menor a 0 si str1 es menor que str2
    - valor mayor a 0 si str1 es mayor que str2
    - valor igual a 0 si str1 es igual que str2

## Funciones de copia de cadenas    

Las cadenas son vectores, por lo que copia se debe hacer elemento por elemento o por medio de las siguientes funciones.

- ***strcpy***
    ```c
    char *strcpy(const char *dest, const char *src);
    ```
    Copia la cadena src en la cadena de destino __PISANDO EN CONTENIDO__
    __Devuelve__ 
    - El puntero a la cadena resultante

- ***strncpy***
    ```c
    char *strncpy(const char *dest, const char *src, size_t n);
    ```
    Copia los primero n elementos de la cadena src en la cadena de destino __PISANDO EN CONTENIDO__
    __Devuelve__ 
    - El puntero a la cadena resultante
   

## Funciones de concatenacion de cadenas    

- ***strcat***
    ```c
    char *strcat(const char *dest, const char *src);
    ```
    Copia al final de la cadena de src a la cadena dest, alargando a la cadena de destino.
    __Devuelve__ 
    - El puntero a la cadena resultante
    
- ***strncat***
    ```c
    char *strncat(const char *dest, const char *src, size_t n);
    ```
    Copia los primero n elementos de la cadena src al final de la cadena de destino
    __Devuelve__ 
    - El puntero a la cadena resultante

## Funciones de busqueda  

- ***strchr***
    ```c
    char *strchr(const char *str, int c);
    ```
    Busca en la cadena la primer ocurrencia del caracter c.
    __Devuelve__ 
    - El puntero al elemento de la cadena o NULL si no lo encuentra

- ***strrchr***
    ```c
    char *strrchr(const char *str, int c);
    ```
    Busca en la cadena la ultima ocurrencia del caracter c.
    __Devuelve__ 
    - El puntero al elemento de la cadena o NULL si no lo encuentra 

- ***strstr***
    ```c
    char *strstr(const char *str, const char *bus);
    ```
    Busca en la cadena str la primera ocurrencia de la cadena bus en forma completa
    __Devuelve__ 
    - El puntero al elemento de la cadena o NULL si no lo encuentra 
      
