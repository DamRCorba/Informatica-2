#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char nombre[] = {"Cosme"};
    char apellido[] = {"Fulanito"};
    char nombreApellido[50];

    strcpy(nombreApellido, nombre); // copia en nombreApellido el contenido de nombre
    printf("%s\n", nombreApellido ); // imprime
    strcat(nombreApellido, ", "); // Concatena ", "
    printf("%s\n", nombreApellido ); // Imprime
    strcat(nombreApellido, apellido); // Concatena el apellido
    printf("%s\n", nombreApellido ); // imprime

    printf("Longitud del Nombre %d, Longitud del Apellido %d, Longitud del Nombre Completo %d",strlen(nombre), strlen(apellido), strlen(nombreApellido) );

  return 0;
}
