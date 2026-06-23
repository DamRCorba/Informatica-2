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
    FILE *fp;
    char opc='s';
    long id=1;

    if((fp = fopen("datos.dat", "wb")) == NULL){
        printf("No se pudo abrir el archivo datos.dat");
        return 1;
    }

    printf("Bienvenido a la carga de datos\n");

    do
    {
        printf("Ingrese la categoria: ");
        gets(registro.categoria);
        printf("Ingrese el valor: ");
        scanf("%f",&registro.valor);
        registro.id = id;
        printf("Ingrese el estado: ");
        scanf("%d",&registro.estado);

        fwrite(&registro,sizeof(datos_t),1,fp);

        printf("\nDesea ingresar mas datos? (s/n)");
        fflush(stdin);
        getchar();
        opc= getchar();
        fflush(stdin);
        getchar();
        id++;

    } while (opc != 'n');
    
    fclose(fp);
    return 0;
}

