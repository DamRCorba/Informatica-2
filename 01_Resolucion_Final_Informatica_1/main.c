#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CANT_ARTICULOS 60

#define SUCURSAL_1 1
#define SUCURSAL_2 2
#define SUCURSAL_3 3
#define TOTAL 4

typedef struct {
    char descripcion[90];
    int cantidad_sucursal_1;
    int cantidad_sucursal_2;
    int cantidad_sucursal_3;
    int total;
}articulos_t;

/**
 * articulos_sucursal [ index, cantidad_sucursal_1, cantidad_sucursal_2, cantidad_sucursal_3, total]
 * articulos [index, descripcion]
 */

int main(void)
{
    int  articulos_sucursal[CANT_ARTICULOS][5] = {0}, opc=0, i, articulo_index, sucursal;
    char articulos[CANT_ARTICULOS][90] = {0}, articulo[90];

    printf("Bienvendio al final de Info 1\n\n");

    /*CARGA de las fichas*/

    do
    {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s",articulo);

        // for (i = 0; i < CANT_ARTICULOS; i++)
        // {
        //     if(!strcmp(articulo,articulos[i])){ // si son iguales
        //         articulo_index = i;
        //         break;
        //     }

        //     if(articulos[i][0] == 0){ //'\b' Null
        //         strcpy(articulos[i], articulo);
        //         articulo_index = i;
        //         break;
        //     }
        // }
    
        i=0;
        while (articulos[i][0] && strcmp(articulo, articulos[i])) i++;
        articulo_index = i;
        strcpy(articulos[i], articulo);

        printf("\n%s, Indice: %d", articulos[articulo_index], articulo_index);

        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);

        // switch (sucursal)
        // {
        // case SUCURSAL_1:
        //     printf("Ingrese la cantidad del articulo para la sucursal 1: ");
        //     scanf("%d",&articulos_sucursal[articulo_index][sucursal]);
        //     articulos_sucursal[articulo_index][TOTAL] = articulos_sucursal[articulo_index][SUCURSAL_1] + articulos_sucursal[articulo_index][SUCURSAL_2] + articulos_sucursal[articulo_index][SUCURSAL_3]; 
        //     break;
        // case SUCURSAL_2:
        //     printf("Ingrese la cantidad del articulo para la sucursal 2: ");
        //     scanf("%d",&articulos_sucursal[articulo_index][sucursal]);
        //     articulos_sucursal[articulo_index][TOTAL] = articulos_sucursal[articulo_index][SUCURSAL_1] + articulos_sucursal[articulo_index][SUCURSAL_2] + articulos_sucursal[articulo_index][SUCURSAL_3]; 
        //     break;
        // case SUCURSAL_3:
        //     printf("Ingrese la cantidad del articulo para la sucursal 3: ");
        //     scanf("%d",&articulos_sucursal[articulo_index][sucursal]);
        //     articulos_sucursal[articulo_index][TOTAL] = articulos_sucursal[articulo_index][SUCURSAL_1] + articulos_sucursal[articulo_index][SUCURSAL_2] + articulos_sucursal[articulo_index][SUCURSAL_3]; 
        //     break;
        // default:
        //     printf("\nLo siento no encontre la sucursal");
        //     break;
        // }

        printf("Ingrese la cantidad del articulo para la sucursal %d: ",sucursal);
        scanf("%d", &articulos_sucursal[articulo_index][sucursal]);
        articulos_sucursal[articulo_index][TOTAL] = articulos_sucursal[articulo_index][SUCURSAL_1] + articulos_sucursal[articulo_index][SUCURSAL_2] + articulos_sucursal[articulo_index][SUCURSAL_3];

        printf("Desea ingresar otro articulo? 1-Si, 2-No");
        scanf("%d",&opc);
    } while (opc==1);
    /* Impresion de fichas cargadas*/
    i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i][0]){
        printf("%s\t%d\t%d\t%d\t%d\n", articulos[i], articulos_sucursal[i][SUCURSAL_1], articulos_sucursal[i][SUCURSAL_2], articulos_sucursal[i][SUCURSAL_3],articulos_sucursal[i][TOTAL]);
        i++;
    }
    /* Ordenamiento */

    for ( opc = 1; opc < CANT_ARTICULOS; opc++)
    {
        for ( i = 0; i < CANT_ARTICULOS-1; i++)
        {
            if(articulos_sucursal[i][TOTAL]<articulos_sucursal[i+1][TOTAL]){
                strcpy (articulo,articulos[i]);
                strcpy(articulos[i],articulos[i+1]);
                strcpy(articulos[i+1], articulo);

                articulo_index = articulos_sucursal[i][SUCURSAL_1];
                articulos_sucursal[i][SUCURSAL_1] = articulos_sucursal[i+1][SUCURSAL_1];
                articulos_sucursal[i+1][SUCURSAL_1] = articulo_index;

                articulo_index = articulos_sucursal[i][SUCURSAL_2];
                articulos_sucursal[i][SUCURSAL_2] = articulos_sucursal[i + 1][SUCURSAL_2];
                articulos_sucursal[i + 1][SUCURSAL_2] = articulo_index;

                articulo_index = articulos_sucursal[i][SUCURSAL_3];
                articulos_sucursal[i][SUCURSAL_3] = articulos_sucursal[i + 1][SUCURSAL_3];
                articulos_sucursal[i + 1][SUCURSAL_3] = articulo_index;

                articulo_index = articulos_sucursal[i][TOTAL];
                articulos_sucursal[i][TOTAL] = articulos_sucursal[i + 1][TOTAL];
                articulos_sucursal[i + 1][TOTAL] = articulo_index;
            }
            
        }
        
    }

    printf("\n\n###################################");
    printf("\n##############ORDENADO################");
    printf("\n###################################");

    i = 0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < CANT_ARTICULOS && articulos[i][0])
    {
        printf("%s\t%9d\t%4d\t%3d\t%8d\n", articulos[i], articulos_sucursal[i][SUCURSAL_1], articulos_sucursal[i][SUCURSAL_2], articulos_sucursal[i][SUCURSAL_3], articulos_sucursal[i][TOTAL]);
        i++;
    }

    return 0;
}