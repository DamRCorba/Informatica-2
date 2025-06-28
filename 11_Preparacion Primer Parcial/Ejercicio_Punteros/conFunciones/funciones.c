#include "lib.h"

char * f_strchr(char *string, char caracter){
    while (*string != caracter) string++;
    return string;
}

void f_strcpy(char *destino, char *origen){
    while (*origen)
    {
        *destino = *origen;
        origen++;
        destino++;
    }
    *destino=0;
}

void f_strcat(char *destino, char origen[20]){
    char *aux;
    aux = origen;
    while(*destino) destino++; // Busca el fin de candena

    while (*origen)
    {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino=0;    

}

void f_toLowerCase(char *string){ 
    while(*string){
        if (*string >= 'A' && *string <= 'Z')
        { // *s es una letra mayuscula
            *string = *string + ('a' - 'A');
        }
        string++;
    }
}
void f_toUpperCase(char *string){
    while(*string){
        if (*string >= 'a' && *string <= 'z') // *es una letra minuscula
        {                           // *s es una letra mayuscula
            *string = *string - ('a' - 'A');
        }
        string++;
    }
}
void f_toggleCase(char *string){
    while(*string){    
        if (*string >= 'A' && *string <= 'Z')
        { // *s es una letra mayuscula
            *string = *string + ('a' - 'A');
        }                                //(s+i)
        else if (*string >= 'a' && *string <= 'z') // *es una letra minuscula
        {                                // *s es una letra mayuscula
            *string = *string - ('a' - 'A');
        }
        string++;
    }
}