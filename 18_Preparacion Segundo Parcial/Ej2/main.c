#include <stdio.h>
#include <malloc.h>

typedef struct 
{
    int clave;
    char descripcion[30];
    unsigned tipo;
    int baja;
}datos_t;

typedef struct cola
{
    int clave;
    long pos;
    struct cola *lazo;
}cola_t;

cola_t * funcion (int key, cola_t *primero);
cola_t * muestra (cola_t*primero);

int main(int argc, char const *argv[])
{
    /* code */
    cola_t *pri = NULL, *aux;
    int clave, opc=0;
    //pri = funcion(112,pri);
    do
    {
        
        printf("Ingrese la clave");
        scanf("%d",&clave);
        pri = funcion (clave, pri);
        printf("Desdea ingresar mas claves? 1-Si 2-No");
        scanf("%d",&opc);
    } while (opc!=2);

    while(pri) {
        pri = muestra(pri);
    }
    // while (pri->lazo !=NULL)
    // {
    //     printf("Clave: %d, Pos: %d", pri->clave, pri->pos);
    //     aux = pri;
    //     pri = pri->lazo;
    //     free(aux);
    // }
    // printf("Clave: %d, Pos: %d", pri->clave, pri->pos);
    // free(pri);
    //return 0;

    return 0;
}

cola_t *funcion(int key, cola_t *primero){
    FILE *fp;
    datos_t contenido;
    cola_t *aux, *cola;
    long pos = 0;

    cola = primero;
    if((fp=fopen("datos.dat","rb+"))==NULL){
        printf("No se pudo abrir el archivo");
        return NULL;
    }

    fread(&contenido, sizeof(datos_t),1,fp);
    while (!feof(fp))
    {

        if(contenido.clave == key){
            if(contenido.tipo & (1<<0)){
                // encolando
                aux = malloc(sizeof(cola_t));// validacion de asignacion de recursos
                aux->clave = contenido.clave; // aux->clave = key;
                aux->pos = pos;
                aux->lazo = NULL;
                if(primero == NULL) {
                    primero = aux;
                    //primero -> lazo = NULL;
                    fclose(fp);
                    return primero;
                } else
                {
                    while (cola->lazo != NULL)
                    {
                        cola = cola->lazo;
                    }
                    cola->lazo = aux;
                    fclose(fp);
                    return primero;
                    
                }
                

            } else {
                // no hago nada
            }
        }
        pos++;
        fread(&contenido, sizeof(datos_t), 1, fp);
    }
    // No se encontro debo agregar el registro
    contenido.clave = key;
    contenido.baja = 'A';
    printf("Registro no encontrado, ingrese los datos:");
    printf("Ingrese la descripcion");
    gets(contenido.descripcion);
    printf("Ingrese el tipo");
    scanf("%d",contenido.tipo);
    fwrite(&contenido, sizeof(datos_t),1,fp);
    fclose(fp);
    return primero;
}

cola_t *muestra(cola_t *primero){
    FILE *fp;
    datos_t contenido;
    cola_t *aux;    

    
    if ((fp = fopen("datos.dat", "rb+")) == NULL)
    {
        printf("No se pudo abrir el archivo");
        return NULL;
    }

    fseek(fp, (long)(primero->pos * sizeof(datos_t)), SEEK_SET);
    fread(&contenido, sizeof(datos_t), 1, fp);
    printf("Clave: %d, Desc: %s, Tipo: %d, Baja: %d", contenido.clave
    , contenido.descripcion, contenido.tipo, contenido.baja);
    aux = primero->lazo;
    free(primero);
    fclose(fp);
    return aux;

}
