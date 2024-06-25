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


int funcion(char *nombreArchivo, char tipo); //C o D

int main(int argc, char const *argv[])
{
    char nombreArchivoCreciente[30], nombreArchivoDecreciente[30];
    printf("%d",argc);
    strcpy(nombreArchivoCreciente, argv[1]);
    strcpy(nombreArchivoDecreciente, argv[2]);

    if (funcion(nombreArchivoCreciente,'C')) return 1;
    if (funcion(nombreArchivoDecreciente, 'D')) return 1;

    return 0;
}

int funcion(char *nombreArchivo, char tipo) {
    FILE *fp, *salida;
    datos_t data;
    sensores_t sensor;
    char *s1,*s2;

    if((fp=fopen("temperatura.dat", "rb")) == NULL){
        printf("Error al abrir Temperatura.dat");
        return 1;
    }

    if((salida = fopen(nombreArchivo, "wb")) == NULL){
        printf("No se pudo crear el archivo %s", nombreArchivo);
        return 1;
    }

    fread(&data, sizeof(datos_t), 1,fp);
    while (!feof(fp))
    {
        if( tipo == 'C') {
            if ((data.tipo & (1 << 7)) && (data.tipo & (1 << 5))){
                if(data.temperatura >= data.temperatura_alarma) sensor.estado = 'A';
                else sensor.estado = 'N';
                sensor.temperatura = data.temperatura;
                sensor.temperatura_alarma = data.temperatura_alarma;
                sensor.tipo = data.tipo;
                sensor.timestamp = data.timestamp;
                strcpy(sensor.descripcion,data.descripcion);
                fwrite(&sensor, sizeof(sensores_t),1,salida);
            }
        }
        if (tipo == 'D') {
            if ((data.tipo & (1 << 6)) && (data.tipo & (1 << 4))){
                sensor.estado = (data.temperatura <= data.temperatura_alarma) ? 'A' : 'N';
                sensor.temperatura = data.temperatura;
                sensor.temperatura_alarma = data.temperatura_alarma;
                sensor.tipo = data.tipo;
                sensor.timestamp = data.timestamp;
                s1 = data.descripcion;
                s2 = sensor.descripcion;
                while(*s1){
                    *s2=*s1;
                    s2++;
                    s1++;
                }
                fwrite(&sensor, sizeof(sensores_t), 1, salida);
            }
        }

        fread(&data, sizeof(datos_t), 1, fp);
    }
    fclose(fp);
    fclose(salida);
    return 0;

}