#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL 4

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3]; // sucursal 1 2 3    
    int total;
}articulos_t;

/**
 * articulos [ index, cantidad_sucursal[SUCURSAL_1], cantidad_sucursal[SUCURSAL_2], cantidad_sucursal[SUCURSAL_3], total]
 * articulos [index, descripcion]
 */

int main(void)
{
    int  opc=0, i, articulo_index, sucursal;
    char articulo[90];
    articulos_t articulos[CANT_ARTICULOS] = {0};
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
        while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;
        articulo_index = i;
        strcpy(articulos[i].descripcion, articulo);

        printf("\n%s, Indice: %d\n", articulos[articulo_index].descripcion, articulo_index);

        printf("Para que sucursal va a realizar la carga? (1,2,3)");
        scanf("%d", &sucursal);

        // switch (sucursal)
        // {
        // case SUCURSAL_1:
        //     printf("Ingrese la cantidad del articulo para la sucursal 1: ");
        //     scanf("%d",&articulos[articulo_index].cantidad_sucursal[SUCURSAL_1]);
        //     break;
        // case SUCURSAL_2:
        //     printf("Ingrese la cantidad del articulo para la sucursal 2: ");
        //     scanf("%d",&articulos[articulo_index].cantidad_sucursal[SUCURSAL_2]);
        //     break;
        // case SUCURSAL_3:
        //     printf("Ingrese la cantidad del articulo para la sucursal 3: ");
        //     scanf("%d",&articulos[articulo_index].cantidad_sucursal[SUCURSAL_3]);
        //     break;
        // default:
        //     printf("\nLo siento no encontre la sucursal");
        //     break;
        // }
        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &articulos[articulo_index].cantidad_sucursal[sucursal-1]);
        for(i=0;i<3;i++) articulos[articulo_index].total += articulos[articulo_index].cantidad_sucursal[i];        

        printf("Desea ingresar otro articulo? 1-Si, 2-No");
        scanf("%d",&opc);
    } while (opc==1);
    /* Impresion de fichas cargadas*/
    i=0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
        printf("%s\t%d\t%d\t%d\t%d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal[SUCURSAL_1], articulos[i].cantidad_sucursal[SUCURSAL_2], articulos[i].cantidad_sucursal[SUCURSAL_3],articulos[i].total);
        i++;
    }
    /* Ordenamiento */

    for ( opc = 1; opc < CANT_ARTICULOS; opc++)
    {
        for ( i = 0; i < CANT_ARTICULOS-1; i++)
        {
            if(articulos[i].total<articulos[i+1].total){
                strcpy (articulo,articulos[i].descripcion);
                strcpy(articulos[i].descripcion,articulos[i+1].descripcion);
                strcpy(articulos[i+1].descripcion, articulo);

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_1];
                articulos[i].cantidad_sucursal[SUCURSAL_1] = articulos[i+1].cantidad_sucursal[SUCURSAL_1];
                articulos[i+1].cantidad_sucursal[SUCURSAL_1] = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_2];
                articulos[i].cantidad_sucursal[SUCURSAL_2] = articulos[i + 1].cantidad_sucursal[SUCURSAL_2];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_2] = articulo_index;

                articulo_index = articulos[i].cantidad_sucursal[SUCURSAL_3];
                articulos[i].cantidad_sucursal[SUCURSAL_3] = articulos[i + 1].cantidad_sucursal[SUCURSAL_3];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_3] = articulo_index;

                articulo_index = articulos[i].total;
                articulos[i].total = articulos[i + 1].total;
                articulos[i + 1].total = articulo_index;
            }
            
        }
        
    }

    printf("\n\n###################################");
    printf("\n##############ORDENADO################");
    printf("\n################################### \n");

    i = 0;
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < CANT_ARTICULOS && articulos[i].descripcion[0])
    {
        printf("%s\t%9d\t%4d\t%3d\t%8d\n", articulos[i].descripcion, articulos[i].cantidad_sucursal[SUCURSAL_1], articulos[i].cantidad_sucursal[SUCURSAL_2], articulos[i].cantidad_sucursal[SUCURSAL_3], articulos[i].total);
        i++;
    }

    return 0;
}
