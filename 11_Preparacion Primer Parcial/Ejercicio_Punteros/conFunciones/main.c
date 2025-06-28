#include "lib.h"

int main(int argc, char const *argv[])
{
    char nombre[] = {"Cosme, Fulanito"}, *s, aux[30];
    s = nombre;
    printf("\nOriginal: %s", nombre);
    s = f_strchr(s,',');
    *s = 0;
    s += 2;
    printf("\nNombre: %s - Apellido: %s", nombre, s);
    f_strcpy(aux, s);
    printf("\nAUX: %s\n",aux);
    f_strcat(aux, ", ");
    printf("\n%s", aux);
    f_strcat(aux, nombre);
    printf("\n%s", aux);
    f_strcpy(nombre,aux);
    printf("\n%s", nombre);
    f_toggleCase(nombre);
    printf("\n%s\n", nombre);
    f_toLowerCase(nombre);
    printf("\n%s\n", nombre);
    f_toUpperCase(nombre);
    printf("\n%s\n", nombre);
    return 0;
}
