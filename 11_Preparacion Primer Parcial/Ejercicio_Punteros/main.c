#include <stdio.h>

int main(int argc, char const *argv[])
{
    char nombre[] = {"Cosme, Fulanito"}, *s, aux[30], *p_aux;

    s = nombre;

    printf("\nOriginal: %s", nombre);
    
    while(*s != ',') s++; // strchr
    *s = 0;
    s+=2;
    
    printf("\nNombre: %s - Apellido: %s", nombre, s);
    // strcpy
    p_aux = aux;    
    while (*s) {
        *p_aux = *s;
        s++;
        p_aux++;
    }
    //strcat
    *p_aux = ',';
    p_aux++;
    *p_aux = ' ';
    p_aux++;
    *p_aux = 0;

    printf("\n%s", aux);
    s = nombre;
    //strcat
    while (*s)
    {
        *p_aux=*s;
        s++;
        p_aux++;
    }
    *p_aux = 0;
    printf("\n%s", aux);
    
    
    //// STRCPY - Inicia
    p_aux = aux;
    s = nombre;
    while (*p_aux)
    {
        *s = *p_aux;
        p_aux++;
        s++;
    }
    *s = 0;
    printf("\n%s", nombre);
    //// STRCPY - FIN

    s = nombre;
    while(*s){
        if(*s >= 'A' && *s <= 'Z') { // *s es una letra mayuscula
            *s = *s + ('a' - 'A');
        } //(s+i)
        else if (*s >= 'a' && *s <= 'z') // *es una letra minuscula
        { // *s es una letra mayuscula
            *s = *s - ('a' - 'A');
        }
        s++;
    }
    printf("\n%s\n", nombre);

    return 0;
}
