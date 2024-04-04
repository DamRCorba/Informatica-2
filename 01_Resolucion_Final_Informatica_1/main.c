#include <stdio.h>
#include <string.h>

/**********************************************************************************************
 *  articulos_sucursal [| index | cantidad_sucursal_1 | cantidad_sucursal_2 | cantidad_sucursal_3 | Total |]
 *  articulos [index] [descripcion] *
 **/

// Punto 2 No la usa el codigo
typedef struct {
    char articulo[90];
    int sucursal1;
    int sucursal2;
    int sucursal3;
    int total;
}articulos_t;



int main(int argc, char const *argv[])
{
    // articulos_t articulos_sucursal[60] = {0};
    int articulos_sucursal[60][5] = {0}, sucursal, i, opc=0, articulo_index;
    char articulos[60][90]={0}, articulo[90];
    printf("Bienvenido al final de Informatica 1\n\n");
    do{
        printf("Ingrese el nombre del articulo que desea cargar: ");
        scanf("%s",&articulo);
        // for(i=0;i<60;i++){
        //     if(!strcmp(articulo,articulos[i])){
        //         articulo_index = i;
        //         break;
        //     }
        //     if(articulos[i][0]==0){
        //         strcpy(articulos[i], articulo);
        //         articulo_index=i;
        //         break;
        //     }
        // }
        i=0;
        
        while(articulos[i][0]!=0 && strcmp(articulo,articulos[i])) i++;
        articulo_index=i;
        strcpy(articulos[i], articulo);

        printf("\n%s, Indice: %d\n", articulos[articulo_index], articulo_index);

        printf("Para que sucursal va a realizar la carga?:(1,2,3) ");
        scanf("%d", &sucursal);
        // Validar que sucursal solo tome valores de 1 a 3

        // switch (sucursal)
        // {
        // case 1:
        //     printf("Ingrese la cantidad para la sucursal 1: ");
        //     scanf("%d", &articulos_sucursal[articulo_index][sucursal]);
        //     articulos_sucursal[articulo_index][4] = articulos_sucursal[articulo_index][1] + articulos_sucursal[articulo_index][2] + articulos_sucursal[articulo_index][3];
        //     break;
        // case 2:
        //     printf("Ingrese la cantidad para la sucursal 2: ");
        //     scanf("%d", &articulos_sucursal[articulo_index][sucursal]);
        //     articulos_sucursal[articulo_index][4] = articulos_sucursal[articulo_index][1] + articulos_sucursal[articulo_index][2] + articulos_sucursal[articulo_index][3];
        //     break;
            
        // case 3:
        //     printf("Ingrese la cantidad para la sucursal 3: ");
        //     scanf("%d", &articulos_sucursal[articulo_index][sucursal]);
        //     articulos_sucursal[articulo_index][4] = articulos_sucursal[articulo_index][1] + articulos_sucursal[articulo_index][2] + articulos_sucursal[articulo_index][3];            
        //     break;
        // default:
        //     printf("\n Lo siento no encontre la sucursal\n");
        //     break;
        // }
        printf("Ingrese la cantidad para la sucursal %d: ",sucursal);
        scanf("%d", &articulos_sucursal[articulo_index][sucursal]);
        articulos_sucursal[articulo_index][4] = articulos_sucursal[articulo_index][1] + articulos_sucursal[articulo_index][2] + articulos_sucursal[articulo_index][3];
        
        printf("Desea Ingresar otro articulo? 1-Si, 2-No");
        scanf("%d",&opc);

    }while(opc==1);

    i=0;
    printf("Articulo\t,Sucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < 60 && articulos[i][0]) //
    {
        printf("%s\t%18d\t%9d\t%9d\t%9d\n", articulos[i], articulos_sucursal[i][1], articulos_sucursal[i][2], articulos_sucursal[i][3],articulos_sucursal[i][4]);
        i++;
    }

    // Ordenamiento

    for(opc=1;opc<60;opc++){
        for(i=0;i<59;i++){
            if(articulos_sucursal[i][4]<articulos_sucursal[i+1][4]){
                strcpy(articulo,articulos[i]);
                strcpy(articulos[i], articulos[i+1]);
                strcpy(articulos[i+1], articulo);

                articulo_index= articulos_sucursal[i][1];
                articulos_sucursal[i][1] = articulos_sucursal[i+1][1];
                articulos_sucursal[i+1][1] = articulo_index;

                articulo_index = articulos_sucursal[i][2];
                articulos_sucursal[i][2] = articulos_sucursal[i + 1][2];
                articulos_sucursal[i + 1][2] = articulo_index;

                articulo_index = articulos_sucursal[i][3];
                articulos_sucursal[i][3] = articulos_sucursal[i + 1][3];
                articulos_sucursal[i + 1][3] = articulo_index;

                articulo_index = articulos_sucursal[i][4];
                articulos_sucursal[i][4] = articulos_sucursal[i + 1][4];
                articulos_sucursal[i + 1][4] = articulo_index;
            }
        }
    }

    printf("\n\nVERSION ORDENADA\n\n");

    i = 0;
    printf("Articulo\t,Sucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < 60 && articulos[i][0]) //
    {
        printf("%s\t%18d\t%9d\t%9d\t%9d\n", articulos[i], articulos_sucursal[i][1], articulos_sucursal[i][2], articulos_sucursal[i][3], articulos_sucursal[i][4]);
        i++;
    }

    return 0;
}
