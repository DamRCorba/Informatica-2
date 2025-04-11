/*
Ejercicio 1: Cargar en un vector las componentes de una funcion seno e imprimir en patalla.

*/


#include <stdio.h> // libreria general
#include <stdlib.h>
#include <math.h>  // Libreria donde se encuentra la funcion sin para calcular el seno


int main(int argc, char const *argv[]) {
  int seno[8]; // donde guardaremos los valores de la funcion seno
  int angulos[] = {0, 45, 90, 135, 180, 225, 270, 315}; // angulos de calculo
  char i = 0;


  // Carga del vector seno
  for( i = 0; i < 8; i++)
  {
    seno[i] = sin(angulos[i]); // Calcula el seno del angulo
  }

  // Impresion en pantalla
  for (i = 0; i < 8; i ++) {
    printf("Angulo %d, seno = %d\n\r",angulos[i], seno[i] );
  }

  return 0;
}
