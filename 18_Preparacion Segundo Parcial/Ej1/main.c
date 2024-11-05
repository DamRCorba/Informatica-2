#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    long id;
    char descripcion[120];
    double medida;
    unsigned estado;
    int baja;
} datos_t;

typedef struct pila
{
    datos_t datos;
    struct pila *lazo;
} pila_t;


pila_t * funcion (long id, pila_t *pila);

int main(int argc, char const *argv[])
{
    pila_t *pila=NULL, *aux2;
    int i;
    long id;

    for (i=0;i<10;i++){
        printf("Ingrese el ID: ");
        scanf("%ld",&id);
        pila = funcion(id, pila);
    }
    
    while (pila->lazo != NULL)
    {
        printf("\nID: %ld, descripcion: %s, medida: %f, estado: %d, baja: %d",
               pila->datos.id, pila->datos.descripcion, pila->datos.medida, pila->datos.estado, pila->datos.baja);
        aux2 = pila;
        pila = pila ->lazo;
        free(aux2);
        
    }
    printf("\nID: %ld, descripcion: %s, medida: %f, estado: %d, baja: %d",
           pila->datos.id, pila->datos.descripcion, pila->datos.medida, pila->datos.estado, pila->datos.baja);
    free(pila);

    return 0;
}

pila_t *funcion(long id, pila_t *pila){
    FILE *fp;
    datos_t dat;
    pila_t *aux;


    if((fp=fopen("medidas.dat","ab+")) == NULL){
        printf("Error al abrir el archivo medidas.dat");
        return NULL;
    }
// Una alternativa
    // fread(&dat,sizeof(datos_t),1,fp);
    // if(dat.id < id){
    //     printf("Registro no encontrado");
    //     return pila;
    // }
// Mejor
    // si nuestro archiv arranca con id = 0 o con id =1
    fseek(fp, (id-1)*sizeof(datos_t),SEEK_SET); // estoy en el registro
    fread(&dat, sizeof(datos_t), 1, fp);
    if(dat.id != id) {
        printf("Registro no encontrado");
        return pila;
    } 
    // se que es el id que me paso el usuario.
    if(dat.baja == 0  && (
        dat.estado & (1<<0) &&// bit 0 en 1
        dat.estado & (1<<1) &&// bit 1 en 1
        dat.estado & (1<<2) &&// bit 2 en 1
        dat.estado & (1<<3) ) && // bit 3 en 1 
    (!strncmp(dat.descripcion, "ESP",3))){
        aux = malloc(sizeof(pila_t));
        if(aux==NULL) {
            printf("Error al reservar memoria dinamica");
            fclose(fp);
            return NULL;
        }
        aux->datos = dat;

        if(pila == NULL){
            pila = aux;
            aux->lazo = NULL;
        } else {
            aux -> lazo = pila;
            pila = aux;
        }

        dat.baja = 1;
        fseek(fp, -1L*sizeof(datos_t),SEEK_CUR);
        fwrite(&dat, sizeof(datos_t), 1, fp);
    }
    fclose(fp);
    return pila;




}
