#include <stdio.h>
#include "../Header/Mytypes.h"

/*Cargar datos de Caracteres en una estructura con matrices.*/
int main (void){
  /*Declaracion de Variables*/
unsigned char opc = 0, i = 0,j; // Opc - Preguntara si se quiere seguir cargado caracteres, i y j se usan para iterar.
unsigned char x,y; // Recorreran la Matriz de puntos
caracter_t caracteres[23] = {0}; // Tipo Caracter
/*Ejecucion*/
printf("Bienvenido al programa de dibujo de caracters\n\r");
do{
  /*Se ingresan los datos*/
  printf("Ingrese identificador de Caracter\n\r");
  scanf("%c", &caracteres[i].caracter);

  for(x=0;x<8;x++){
    for(y=0;y<8;y++){
      printf("\n\rIngrese valor de (%d,%d)",x,y);
      fflush( stdin );
      scanf("%d",&caracteres[i].dotmatrix[x][y]);
      fflush( stdin );
    }
  }
  printf("Desea Cargar otro Caracter?\n\r");
  printf("1-No\n\r2- Si\n\r");
  fflush( stdin );
  scanf("%d",&opc);
  fflush( stdin );
  i++;
}while(opc != 1 && i < 23);
/*Impresion de datos*/
printf("\n\rSe cargaron %d Caracteres\n\r",i );
for(j=0;j<i;j++){
  printf("\n\rCaracter: %c\n\r",caracteres[j].caracter);
  for(x=0;x<8;x++){
    printf("\n\r( ");
    for(y=0;y<8;y++){
      printf("%d ",caracteres[j].dotmatrix[x][y]);
    }
    printf(")");
  }
}

return 0;
}
