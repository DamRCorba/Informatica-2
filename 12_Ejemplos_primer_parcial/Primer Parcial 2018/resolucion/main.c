#include <stdio.h>
#include <string.h>

typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} piezas_t; 


piezas_t funcion(long id);

int main(void)
{
    long id_user;
    piezas_t pieza;

    printf("\nIngrese el ID que desesa buscar: ");
    scanf("%ld", &id_user);

    pieza = funcion(id_user);

    if( pieza.id == -1) {
        printf("\nError al buscar el id.");
        return 1;
    } else {
        printf("\n ID: %ld, Descripcion: %s, Tipo:%d, Marca: %c\n", pieza.id, pieza.descripcion, pieza.tipo, pieza.marca);
    }
    return 0;
}

piezas_t funcion(long id){
    FILE *fdatos, *fbaja;
    piezas_t registro;
    char *s;

    if((fdatos = fopen("datos.dat","rb+")) == NULL) {
        printf("No se pudo abrir el archivo datos.dat");
        registro.id = -1;
        return registro;
    }

    if ((fbaja = fopen("baja.dat", "ab")) == NULL)
    {
        printf("No se pudo abrir el archivo baja.dat");
        registro.id = -1;
        return registro;
    }

    fread(&registro, sizeof(piezas_t),1,fdatos);
    while (!feof(fdatos))
    {
        /* code */
        if( registro.id == id) {
            if(registro.marca == 'A'){
                registro.marca = 'B';
                strcpy(registro.descripcion,"Registro Procesado");
                fseek(fdatos,-1L*sizeof(piezas_t),SEEK_CUR);
                fwrite(&registro,sizeof(piezas_t),1,fdatos);
                fclose(fdatos);
                fclose(fbaja);
                return registro;
            }
            if (registro.marca == 'B')
            {
                s = registro.descripcion;
                while (*s)
                {
                    /*if( *s == 'a' || *s == 'o' || *s == 'A' || *s == 'O') {
                        *s = 'e';
                    }*/
                    *s = (*s == 'a' || *s == 'o' || *s == 'A' || *s == 'O') ? 'e': *s;
                    s++;
                }
                fwrite(&registro, sizeof(piezas_t),1, fbaja);
                fclose(fdatos);
                fclose(fbaja);
                return registro;
                
            }
        }
        fread(&registro, sizeof(piezas_t), 1, fdatos);
    }
    registro.id = -1;
    printf("No se encontro el id\n");
    fclose(fdatos);
    fclose(fbaja);
    return registro;

}