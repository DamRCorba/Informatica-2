#include <stdio.h>

typedef struct
{
    long id;
    char categoria[90];
    float valor;
    unsigned int estado;
} datos_t;

int main(int argc, char const *argv[])
{
    datos_t registro;
    FILE *archivo;

    if((archivo=fopen("../carga/datos.dat", "rb")) == NULL){
        printf("No se pudo abrir el archivo");
        return 1;
    }

    printf("Bienvenido a la lectura de datos.\n");

    fread(&registro, sizeof(datos_t),1,archivo);
    while(!feof(archivo)){
        //aca va su codigo
        printf("\nID: %ld, Categoria: %s, Valor: %f, Estado: %d", registro.id, registro.categoria, registro.valor, registro.estado);
        fread(&registro, sizeof(datos_t), 1, archivo);
    }
    fclose(archivo);
    return 0;
}
