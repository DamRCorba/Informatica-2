#include <stdio.h>

typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} piezas_t;

int main(int argc, char const *argv[])
{
    piezas_t pieza;
    FILE *f_data;
    long id = 1;
    char opc = 's';

    if((f_data = fopen("datos.dat", "wb")) == NULL){
        printf(" No se pudo abrir el archivo.");
        return -1;
    }

    printf("Bienvenido a la carga de Datos. \n");

    do
    {
        pieza.id = id;
        printf("\nIngrese la descripcion: ");
        gets(pieza.descripcion);
        printf("\nIngrese el tipo: ");
        scanf("%d",&pieza.tipo);
        printf("\nIngrese la marca (A o B): ");
        fflush(stdin);
        getchar();
        pieza.marca = getchar();

        fwrite(&pieza, sizeof(piezas_t),1,f_data);

        printf("\nDesea ingrear mas datos? (s/n)");
        fflush(stdin);
        getchar();
        opc=getchar();
        fflush(stdin);
        getchar();
        id++;
    } while (opc != 'n');
    fclose(f_data);
    return 0;
}
