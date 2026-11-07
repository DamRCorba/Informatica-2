#include <stdio.h>
#include <malloc.h>
typedef struct
{
    long id;
    char descripcion[90];
    int peso;
    char marca; // Marca 'A': Alta  'B': Baja)
} datos_t;

struct list
{
    datos_t datos;
    struct list *ant, *sig;
} ;

typedef struct list lista_t;


int main(int argc, char const *argv[])
{
    datos_t fileDato;
    lista_t *lista = NULL, *aux = NULL, *local = NULL;
    char opc = 's';
    long id = 1;

    printf("Bienvenido a la carga de datos\n");

    do
    {
        printf("Ingrese la Descripcion: ");
        gets(fileDato.descripcion);
        printf("Ingresar el Peso: ");
        scanf("%d", &fileDato.peso);
        fileDato.id = id;
        printf("Ingrese la marca (A ó B): ");
        fflush(stdin);
        getchar();
        fileDato.marca = getchar();

        // deberia hacer algo para cargar en memoria
        aux = malloc(sizeof(lista_t));
        aux->datos = fileDato;
        if(lista == NULL) {
            lista = aux;
            lista -> ant = NULL;
            lista -> sig = NULL;
        } else {
            local = lista;
            while((local-> datos.peso <= aux->datos.peso) && (local->sig != NULL)){
                local = local->sig;                
            }
            printf("\n-------------------COMPARARA");
            printf("\nAUX ID: %d, Descripcion: %s, Peso: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.peso, aux->datos.marca);
            printf("\nLOCAL ID: %d, Descripcion: %s, Peso: %d, Marca: %c", local->datos.id, local->datos.descripcion, local->datos.peso, local->datos.marca);
            if(local->datos.peso > aux->datos.peso){
                printf("\nPeso Local mayor que nuevo");
                if (local->ant != NULL){
                     local->ant->sig = aux;
                     printf("\nLocal tiene anterior");
                }
                else{
                    lista = aux;
                    printf("\nlocal No tiene anterior, Aux es el nuevo Primero");
                } 
                aux->ant = local->ant;
                local->ant=aux;
                aux->sig= local;
            } else {
                printf("\n agrega al final");
                local -> sig = aux;
                aux->ant = local;
                aux->sig = NULL;
            }
            
        }
        

        printf("\nDesea Ingresar mas datos? s/n");
        fflush(stdin);
        getchar();
        opc = getchar();
        fflush(stdin);
        getchar();
        id++;

    } while (opc != 'n');

    while (lista->sig != NULL)
    {
        aux = lista;
        printf("\nID: %d, Descripcion: %s, Peso: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.peso, aux->datos.marca);
        lista = lista->sig;
        free(aux);
    }
    aux = lista;
    printf("\nID: %d, Descripcion: %s, Peso: %d, Marca: %c", aux->datos.id, aux->datos.descripcion, aux->datos.peso, aux->datos.marca);
    free(aux);


    return 0;
}
