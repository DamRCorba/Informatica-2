#include <stdio.h>
#include "../Headers/Mytypes.h"

/*Carga la informacion de color en una matriz de estructura RGB*/
int main (){
/*Declaracion de Variables*/
  unsigned int i,j;
  dotRGB_t image[320][240];
  unsigned char randomr=0, randomg=10, randomb=20;

  /*Carga de datos en la Matriz*/
  for(i=0; i < sizeof(image[0])/3; i++){
    for (j=0; j< sizeof(image)/sizeof(image[0]);j++){
        image[j][i].R = randomr++; // informacion de Rojo
        image[j][i].G = randomg++; // informacion de Verde
        image[j][i].B = randomb++; // informacion de Azul
    }
  }
/* Lectura de datos de la matriz*/
  for(i=0; i < sizeof(image[0])/3; i++){
    for (j=0; j< sizeof(image)/sizeof(image[0]); j++){
      printf("R: %d,G: %d, B:%d\n\r", image[j][i].R,image[j][i].G,image[j][i].B );
    }
  }

  return 0;
}
