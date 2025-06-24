#include <stdio.h>

typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} datos_t;

int main(int argc, char const *argv[])
{
    datos_t fileDato;
    FILE *fp;

    if ((fp = fopen("baja.dat", "rb")) == NULL)
    {
        printf("No se pudo abrir el archivo.");
        return -1;
    }

    fread(&fileDato, sizeof(datos_t), 1, fp);
    while (!feof(fp))
    {

        // nuestro codigo
        printf("\nID: %ld, Descripcion: %s, Tipo: %d, Marca: %c", fileDato.id, fileDato.descripcion, fileDato.tipo, fileDato.marca);
        fread(&fileDato, sizeof(datos_t), 1, fp);
    }
    
    fclose(fp);
    return 0;
}