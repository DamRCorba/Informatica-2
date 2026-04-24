/******************************************************************************************************

Ejercicio 1 - Para el Pizarron
Enunciado: Calcular el Determinante de una Matriz Cuadrada mxm. Imprimir en pantalla la matriz y su determinante.


******************************************************************************************************/
#include <stdio.h>
#include "../header/conf.h"
/*Calculo de Determinate*/


int main(){
  int matriz[M][M];
  char i,j;
  int determinante;
  printf("Calculo de Determinantes\n\r\n\rIngrese la matriz 3x3\n\r");
  /*Se ingresa la matriz*/
  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      printf("Ingrese el valor para (%d,%d): ",i+1,j+1);
      scanf("%d",&matriz[i][j] );
    }
  }
  /*Se imprime en pantalla de matriz cargada*/
  for(i=0;i<M;i++){
    printf("\n\r( ");
    for(j=0;j<M;j++){
      printf("%d ",matriz[i][j]);
    }
    printf(")");
  }

  /*calculo de determinante para M = 3*/
  /* ( a00 a01 a02 )
     ( a10 a11 a12 )
     ( a20 a21 a22 )
     ( a00 a01 a02 )
     ( a10 a11 a12 )
    (a00*a11*a22 + a10*a21*a02 + a20*a01*a12)-(a02*a11*a20 + a12*a21*a00 + a22*a01*a10)
    i hace 0,1,2 - 1,2,0 - 2,0,1
    j hace 0,1,2 | 2,1,0
  */
    determinante = 0;
    for(i=0; i<M ; i++){
      determinante += matriz[i][0]*matriz[((i+1)<M)?i+1:0+(M-i-1)][1]*matriz[((i+2)<M)?i+2:(0+(M-i-2)>=0)?0+(M-i-2):(0+(M-i-2)*(-1))][2];

      }
    for(i=0; i<M ; i++){
      determinante -= matriz[i][2]*matriz[((i+1)<M)?i+1:0+(M-i-1)][1]*matriz[((i+2)<M)?i+2:(0+(M-i-2)>=0)?0+(M-i-2):(0+(M-i-2)*(-1))][0];
      }
    printf("\n\r\n\rEl determinante es: %d\n",determinante );

  return 0;
}
