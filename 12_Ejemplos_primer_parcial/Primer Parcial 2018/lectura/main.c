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
    FILE *f_dato;

    if((f_dato= fopen("../carga/datos.dat", "rb")) == NULL){
        printf("NO se encontro el archivo");
        return -1;
    }

    fread(&pieza, sizeof(piezas_t),1, f_dato);
    while (!feof(f_dato))
    {
        printf("\nID:%ld, Descripcion: %s, Tipo: %d, marcar: %c", pieza.id, pieza.descripcion, pieza.tipo, pieza.marca);
        fread(&pieza, sizeof(piezas_t), 1, f_dato);
    }
    
    fclose(f_dato);
    return 0;
}
