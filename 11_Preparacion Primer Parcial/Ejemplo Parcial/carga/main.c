#include <stdio.h>

typedef struct 
{    
    long timestamp;
    char descripcion[90];
    float temperatura;
    float temperatura_alarma;
    int tipo;
} datos_t;


int main(int argc, char const *argv[])
{
    datos_t data;
    FILE *fp;
    char opc = 's';
    long timestamp = 1000000;

    if((fp=fopen("temperatura.dat", "wb")) == NULL){
        printf("No se pudo abrir el archivo.");
        return 1;
    }

    printf("Bienvenido\n");
    do {
        printf("Ingrese la Descripcion: ");
        gets(data.descripcion);
        printf("Ingrese la Temperatura: ");
        scanf("%f",&data.temperatura);
        printf("Ingrese la Temperatura de Alarma: ");
        scanf("%f",&data.temperatura_alarma);
        data.timestamp = timestamp;
        printf("Ingrese el Tipo: ");  // 160 Creciente, 80 Decreciente, 
        scanf("%d", &data.tipo);

        fwrite(&data, sizeof(datos_t), 1, fp);
        printf("\nDesea Ingresar mas datos? s/n");
        fflush(stdin);
        getchar();
        opc=getchar();
        fflush(stdin);
        getchar();
        timestamp++;

    } while ( opc != 'n');

    fclose(fp);
    return 0;
}

 