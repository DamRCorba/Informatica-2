#include <stdio.h>
#include <malloc.h>
typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} datos_t;

typedef struct {
    datos_t datos;
    void *sig;
} pila_t;

int main(int argc, char const *argv[])
{
    datos_t fileDato;    
    pila_t *pila = NULL, *aux = NULL;
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
        
        ////////////////// PILA 
        aux = malloc(sizeof(pila_t));
        aux->datos = fileDato;
        aux-> sig = pila;
        pila = aux;

        // deberia hacer algo para cargar en memoria

        printf("\nDesea Ingresar mas datos? s/n");
        fflush(stdin);
        getchar();
        opc = getchar();
        fflush(stdin);
        getchar();
        id++;

    } while (opc != 'n');

    while(aux->sig != NULL) {
        printf("\nID: %d, Descripcion: %s, Tipo: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.tipo, aux->datos.marca);
        aux = aux-> sig;
        free(pila);
        pila = aux;
    }
    printf("\nID: %d, Descripcion: %s, Tipo: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.tipo, aux->datos.marca);        
    free(aux);
    // deberia hacer algo para mostrar los datos cargados.
    return 0;
}
