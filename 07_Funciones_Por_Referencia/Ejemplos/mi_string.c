#include "mi_string.h"


int mi_strlen(char *s)
{
    printf("%x", s);
    int longitud = 0;
    while (*s)
    {
        longitud++;
        s++;
    }
    return longitud + 1;
}

void mi_strcpy(char *destino, char *origen){
    while (*origen)
    {
        *destino = *origen;
        origen++;
        destino++;
    }
    *destino = 0;
    return;
}

void mi_strcat(char *destino, char *origen)
{
    while (*destino) destino++;
    // while (*origen)
    // {
    //     *destino = *origen;
    //     destino++;
    //     origen++;
    // }
    // *destino = 0;
    mi_strcpy(destino, origen);
    return;
}

void mi_toUpperCase(char *s){
    while (*s)
    {
        if(*s>='a'&& *s<='z' ) {
            *s = *s - ('a'-'A');
        }
        s++;
    }
    return;
}

void mi_toLowerCase(char *s){
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z')
        {
            *s = *s + ('a' - 'A');
        }
        s++;
    }
    return;
}


int mi_strcmp(char *str1, char *str2){
    while (*str1 && *str2 && !(*str1 - *str2))
    {        
        str1++;
        str2++;
    }
    //if(!*str1 && !*str2) return 0;
    return (*str1 - *str2);
}