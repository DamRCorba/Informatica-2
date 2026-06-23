#include <stdio.h>

typedef struct {
    long id;
    char categoria[90];
    float valor;
    unsigned int estado;
} datos_t;

long funcion(long id);

int main(int argc, char const *argv[])
{
    long mi_id, respuesta;

    printf("Hola, que id queres buscar?");
    scanf("%ld",&mi_id);
    respuesta = funcion(mi_id);
    if(respuesta == -1){
        printf("\nAlgo malio sal.\n");
        return -1;
    }
    if(respuesta == 0) {
        printf("\nNo se encontro el registro\n");
        return 0;
    } else {
        printf("\nQuedan %ld registros hasta el fin de archivo.\n", respuesta-1);
    }

    return 0;
}

long funcion(long id){

    datos_t registro;
    FILE *fp;
    long ubicacion=0, total = 1;
    char *s;

    if((fp = fopen("datos.dat","rb+")) == NULL){
        return -1;
    }

    fread(&registro,sizeof(datos_t),1,fp);
    while (!feof(fp))
    {
        /* code */
        printf("\nID: %ld %ld, Categoria: %s, Valor: %f, Estado: %d", registro.id,id, registro.categoria, registro.valor, registro.estado);
        if( registro.id == id ) {
            ubicacion = total;
            if( registro.estado & (1<<3) ){
                s = registro.categoria;
                while (*s)
                {
                    *s = ( *s >= 'a' && *s <= 'z' ) ? *s-('a'-'A') : *s;
                    s++;
                }
                fseek(fp, -1L*sizeof(datos_t), SEEK_CUR);
                fwrite(&registro,sizeof(datos_t),1,fp);
            }  
        }
        fread(&registro, sizeof(datos_t), 1, fp);
        total++;
    }
    fclose(fp);
    if(ubicacion == 0) return 0;
    else return total - ubicacion;
}