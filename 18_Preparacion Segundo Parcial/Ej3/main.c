#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} datos_t;

typedef struct {
    datos_t data;
    void *lazo;
} pila_t;

typedef struct {
    long id;
    char descripcion[90];
    void *lazo;
}cola_t;

typedef struct {
    pila_t *pila;
    cola_t *cola;
} resolve_t;

resolve_t funcion(long id, resolve_t resolve);

int main(int argc, char const *argv[])
{
    long user_id;
    datos_t fileDato;
    resolve_t din;

    printf("\nIngrese el Id que desea buscar: ");
    scanf("%ld", &user_id);

    din = funcion(user_id, din);

    if (fileDato.id == -1)
    {
        printf("\nError\n");
        return -1;
    }
    else
    {
        printf("\nID: %ld, Descripcion: %s, Tipo: %d, Marca: %c", fileDato.id, fileDato.descripcion, fileDato.tipo, fileDato.marca);
    }

    return 0;
}

resolve_t funcion(long id, resolve_t resolve)
{
    FILE *fp;
    datos_t registro;
    pila_t *aux;
    cola_t *aux_queue, *queue; 
    char *s;

    if ((fp = fopen("datos.dat", "rb+")) == NULL)
    {
        printf("No se pudo abrir el archivo.");
        registro.id = -1;
        return resolve;
    }

    fseek(fp, sizeof(datos_t)*(id-1), SEEK_SET);
    fread(&registro, sizeof(datos_t), 1, fp);
    if (registro.id != id) {
        printf("No se encontro el ID");
        fclose(fp);
        return resolve;
    }


    if (registro.marca == 'A')
    {
        registro.marca = 'B';
        strcpy(registro.descripcion, "Registro Procesado.");
        fseek(fp, -1L * sizeof(datos_t), SEEK_CUR);
        fwrite(&registro, sizeof(datos_t), 1, fp);

        //APILAR
        aux = malloc(sizeof(pila_t));
        aux->data = registro;
        
        if( resolve.pila == NULL ){
            aux->lazo = NULL;
            resolve.pila = aux;            
        } else {
            aux->lazo = resolve.pila;
            resolve.pila = aux;
        }

        fclose(fp);
        return resolve;
    }

    if (registro.marca == 'B')
    {
        s = registro.descripcion;
        while (*s)
        {
            // if (*s == 'a' || *s == 'o' || *s == 'A' || *s == 'O') *s = 'e';
            *s = (*s == 'a' || *s == 'o' || *s == 'A' || *s == 'O') ? 'e' : *s;
            s++;
        }

        // ENCOLAR
        aux_queue = malloc(sizeof(cola_t));
        aux_queue->id = id;
        strcpy(aux_queue->descripcion, registro.descripcion);
        aux_queue->lazo = NULL;
        if( resolve.cola == NULL ) {
            resolve.cola = aux_queue;
            
        } else {
            queue = resolve.cola;
            while (queue->lazo != NULL) {
                queue = queue->lazo;
            } 
            //ultimo de la cola;
            queue->lazo = aux_queue;
        }

        fclose(fp);
        return resolve;
    }

    fclose(fp);
    return resolve;
}
