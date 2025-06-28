#include <stdio.h>

typedef struct
{
    long id;
    char categoria[90];
    float valor;
    unsigned int estado;
}datos_t;

int main(int argc, char const *argv[])
{
    datos_t fileDato;
    FILE *fp;

    if((fp=fopen("datos.dat","rb")) == NULL) {
        printf("Error al abrir el archivo");
        return -1;
    }
    printf("Bienvenido a la lectura de datos\n");

    fread(&fileDato, sizeof(datos_t),1,fp);    
    while (!feof(fp))
    {
        printf("\nID: %d, Categoria: %s, Valor: %f, Estado: %d", fileDato.id,fileDato.categoria,fileDato.valor,fileDato.estado);
        fread(&fileDato, sizeof(datos_t), 1, fp);
    }
   
    fclose(fp);

    return 0;
}
