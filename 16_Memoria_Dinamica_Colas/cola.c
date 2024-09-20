#include <stdio.h>
#include <malloc.h>
typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} datos_t;

typedef struct
{
    datos_t datos;
    void *ant;
} cola_t;

int main(int argc, char const *argv[])
{
    datos_t fileDato;
    cola_t *cola = NULL, *aux = NULL, *primero = NULL;
    char opc = 's';
    long id = 1;

    printf("Bienvenido a la carga de datos\n");

    do
    {
        printf("Ingrese la Descripcion: ");
        gets(fileDato.descripcion);
        printf("Ingresar el Tipo: ");
        scanf("%d", &fileDato.tipo);
        fileDato.id = id;
        printf("Ingrese la marca (A ó B): ");
        fflush(stdin);
        getchar();
        fileDato.marca = getchar();

        // deberia hacer algo para cargar en memoria
        aux = malloc(sizeof(cola_t));
        aux->datos = fileDato;
        if(cola==NULL) {
            primero = aux;
        } else {
            cola->ant = aux;        
        }
        aux->ant = NULL;
        cola = aux;
        //aux->ant = cola;
        


        printf("\nDesea Ingresar mas datos? s/n");
        fflush(stdin);
        getchar();
        opc = getchar();
        fflush(stdin);
        getchar();
        id++;

    } while (opc != 'n');

    while(primero->ant != NULL){
        aux = primero;
        printf("\nID: %d, Descripcion: %s, Tipo: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.tipo, aux->datos.marca);
        primero=primero-> ant;
        free(aux);
    }
    aux = primero;
    printf("\nID: %d, Descripcion: %s, Tipo: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.tipo, aux->datos.marca);
    free(aux);

    // while (aux->ant != NULL)
    // {
    //     printf("\nID: %d, Descripcion: %s, Tipo: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.tipo, aux->datos.marca);
    //     aux = aux->sig;
    //     free(pila);
    //     pila = aux;
    // }
    // printf("\nID: %d, Descripcion: %s, Tipo: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.tipo, aux->datos.marca);
    // free(aux);
    // deberia hacer algo para mostrar los datos cargados.
    return 0;
}
