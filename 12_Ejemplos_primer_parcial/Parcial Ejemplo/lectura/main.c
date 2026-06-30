#include <stdio.h>
#include <string.h>
typedef struct
{
    long timestamp;
    char descripcion[90];
    float temperatura;
    float temperatura_alarma;
    int tipo;
} datos_t;

typedef struct
{
    long timestamp;
    char descripcion[90];
    float temperatura;
    float temperatura_alarma;
    int tipo;
    char estado;
} sensores_t;

int main(int argc, char const *argv[])
{
    FILE *fp;
    datos_t data;
    sensores_t data2;
    char nombreArchivo[30];

    if(argc == 1 ) strcpy(nombreArchivo, "temperatura.dat");
    else strcpy (nombreArchivo,argv[1]);


    if ((fp = fopen(nombreArchivo, "rb")) == NULL)
    {
        printf("NO se pudo abrir el archivo");
        return 1;
    }

    if (argc == 1) {
        fread(&data, sizeof(datos_t), 1, fp);
        while(!feof(fp)){
            printf("\nTime: %ld, Descripcion: %s, temp: %f, alarm: %f, tipo: %d", data.timestamp, data.descripcion,data.temperatura,data.temperatura_alarma, data.tipo);
            fread(&data, sizeof(datos_t), 1, fp);
        }
    } else {
        fread(&data2, sizeof(sensores_t), 1, fp);
        while (!feof(fp))
        {
            printf("\nTime: %ld, Descripcion: %s, temp: %f, alarm: %f, tipo: %d, Estado: %c", data2.timestamp, data2.descripcion, data2.temperatura, data2.temperatura_alarma, data2.tipo, data2.estado);
            fread(&data2, sizeof(sensores_t), 1, fp);
        }
    }

    return 0;
}
