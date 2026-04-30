#include <stdio.h>
#include "./headers.h"

/*Carga la informacion de color en una matriz de estructura RGB*/
int main (){
/*Declaracion de Variables*/
  unsigned int i,j;
  dotRGB_t image[320][240];

  /*Carga de datos en la Matriz*/
  for(i=0; i < sizeof(image[0])/3; i++){
    for (j=0; j< sizeof(image)/sizeof(image[0]);j++){
        /* rand() genera un numero aleatorio entre 0 y 32767, se usa el operador modulo para limitar su valor maximo a 255 */
        image[j][i].R = rand() % 256; // informacion de Rojo
        image[j][i].G = rand() % 256; // informacion de Verde
        image[j][i].B = rand() % 256; // informacion de Azul
    }
  }
/* Lectura de datos de la matriz*/
  for(i=0; i < sizeof(image[0])/3; i++){
    for (j=0; j< sizeof(image)/sizeof(image[0]); j++){
      /* Caracter de escape SGR \033[48(Seteo de background);2(Estilo de texto, no relevante);<R>;<G>;<B>m 
      * luego se repite el caracter pero con argumento 0 para limpiar el setting de color antes de la proxima insercion */
      printf("\033[48;2;%d;%d;%dm  \033[0m", image[j][i].R,image[j][i].G,image[j][i].B  );
    }
    printf("\n");
  }

  return 0;
}
