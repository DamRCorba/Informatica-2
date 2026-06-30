#include <stdio.h>

typedef struct{    
        long legajo;
        char materia[30];
        char nombreApellido[90]; // nombre, apellido
        int parcial;             //
        int nota;    
}datos_t;

int main(int argc, char const *argv[])
{
    datos_t data;
    FILE *fp;
    char opc ='s';
    

    if((fp=fopen("notas.dat","ab")) == NULL){
        printf("NO se pudo abrir el archivo");
        return 1;
    }
    printf("Bienvenido\n");
    do{
        printf("Ingrese el Legajo: ");
        scanf("%ld", &data.legajo);
        fflush(stdin);
        getchar();
        printf("Ingrese la Materia: ");
        gets(data.materia);
        printf("Ingrese el nombre del alumno: ");
        gets(data.nombreApellido);
        printf("Ingresar el numero de Examen: ");
        scanf("%d", &data.parcial);
        printf("Ingresar la nota: ");
        scanf("%d", &data.nota);

        fwrite(&data, sizeof(datos_t), 1, fp);

        printf("\nDesea Ingresar mas datos? s/n");
        fflush(stdin);
        getchar();
        opc = getchar();
        fflush(stdin);
        getchar();
    } while(opc!='n');
    return 0;
}
