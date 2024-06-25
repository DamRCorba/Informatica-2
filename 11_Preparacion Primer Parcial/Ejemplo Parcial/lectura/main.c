#include <stdio.h>

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
    datos_t data;
    sensores_t data2;
    FILE *fp;


    printf("Args: %d", argc);
    if(argc == 1) {
        if((fp = fopen("temperatura.dat", "rb"))==NULL) {
            printf("No se pudo abrir el archivo.");
            return 1;
        }

        fread(&data,sizeof(datos_t),1,fp);
        while (!feof(fp))
        {
            if ((data.tipo & (1 << 7)) && (data.tipo & (1 << 5))) printf("\nTime: %ld, Descripcion: %s, Temp: %f, alarm: %f, tipo: Creciente", data.timestamp, data.descripcion, data.temperatura, data.temperatura_alarma);
            else if ((data.tipo & (1 << 6)) && (data.tipo & (1 << 4)))
                printf("\nTime: %ld, Descripcion: %s, Temp: %f, alarm: %f, tipo: Decreciente", data.timestamp, data.descripcion, data.temperatura, data.temperatura_alarma);
            else
                printf("\nTime: %ld, Descripcion: %s, Temp: %f, alarm: %f, tipo: Desconocido", data.timestamp, data.descripcion, data.temperatura, data.temperatura_alarma);
            fread(&data, sizeof(datos_t), 1, fp);
        }
    } else {
        if((fp=fopen(argv[1],"rb")) == NULL){
            printf("No se pudo abrir el archivo. %s", argv[1]);
            return 1;
        }
        fread(&data2, sizeof(sensores_t), 1, fp);
        while (!feof(fp))
        {
            if ((data2.tipo & (1 << 7)) && (data2.tipo & (1 << 5)))
                printf("\nTime: %ld, Descripcion: %s, Temp: %f, alarm: %f, tipo: Creciente, Alarmado: %c", data2.timestamp, data2.descripcion, data2.temperatura, data2.temperatura_alarma, data2.estado);
            else if ((data2.tipo & (1 << 6)) && (data2.tipo & (1 << 4)))
                printf("\nTime: %ld, Descripcion: %s, Temp: %f, alarm: %f, tipo: Decreciente, Alarmado: %c", data2.timestamp, data2.descripcion, data2.temperatura, data2.temperatura_alarma, data2.estado);

            fread(&data2, sizeof(sensores_t), 1, fp);
        }
        
    }
    fclose(fp);
    return 0;
}
