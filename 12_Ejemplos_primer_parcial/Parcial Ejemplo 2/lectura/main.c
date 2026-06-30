#include <stdio.h>

typedef struct
{
    long legajo;
    char materia[30];
    char nombreApellido[90]; // nombre, apellido
    int parcial;             //
    int nota;
} datos_t;

int main(int argc, char const *argv[])
{
    datos_t data;
    FILE *fp;
    char opc = 's';

    if ((fp = fopen("notas.dat", "rb")) == NULL)
    {
        printf("NO se pudo abrir el archivo");
        return 1;
    }
    fread(&data,sizeof(datos_t),1,fp);
    while (!feof(fp))
    {
        printf("\n############################\nLegajo: %ld, Nombre: %s, \nMateria: %s\nExamen:%d, Nota: %d\n####################", data.legajo, data.nombreApellido, data.materia, data.parcial, data.nota);
        fread(&data, sizeof(datos_t), 1, fp);
    }
    
}