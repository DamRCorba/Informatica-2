#include <stdio.h>
#include <string.h>

typedef struct
{
    long id;
    char descripcion[90];
    int tipo;
    char marca; // Marca 'A': Alta  'B': Baja)
} datos_t;

datos_t funcion(long id);

int main(int argc, char const *argv[])
{
    long user_id;
    datos_t fileDato;

    printf("\nIngrese el Id que desea buscar: ");
    scanf("%ld", &user_id);

    fileDato = funcion(user_id);

    if( fileDato.id == -1) {
        printf("\nError\n");
        return -1;
    } else {
        printf("\nID: %ld, Descripcion: %s, Tipo: %d, Marca: %c", fileDato.id, fileDato.descripcion, fileDato.tipo, fileDato.marca);
    }

    return 0;
}

datos_t funcion(long id){
    FILE *fp, *baja;
    datos_t registro;
    char *s;

    if ((fp = fopen("datos.dat", "rb+")) == NULL)
    {
        printf("No se pudo abrir el archivo.");
        registro.id = -1;
        return registro;
    }

    if ((baja = fopen("baja.dat", "ab")) == NULL)
    {
        printf("No se pudo abrir el archivo.");
        registro.id = -1;
        return registro;
    }

    fread(&registro, sizeof(datos_t), 1, fp);
    while (!feof(fp))
    {        
        //printf("\nID: %ld, Descripcion: %s, Tipo: %d, Marca: %c", registro.id, registro.descripcion, registro.tipo, registro.marca);
        if( registro.id == id) {
            if(registro.marca == 'A') {
                registro.marca = 'B';
                strcpy(registro.descripcion, "Registro Procesado.");
                fseek(fp, -1L*sizeof(datos_t),SEEK_CUR);
                fwrite(&registro,sizeof(datos_t),1,fp);
                fclose(fp);
                fclose(baja);
                return registro;
            }

            if (registro.marca == 'B')
            {
                s = registro.descripcion;
                while (*s)
                {
                    //if (*s == 'a' || *s == 'o' || *s == 'A' || *s == 'O') *s = 'e';
                    *s = (*s == 'a' || *s == 'o' || *s == 'A' || *s == 'O') ? 'e' : *s;
                    s++;
                }
                fwrite(&registro, sizeof(datos_t),1, baja);
                fclose(fp);
                fclose(baja);
                return registro;
            }
        }

        fread(&registro, sizeof(datos_t), 1, fp);
    }
    registro.id = -1;
    printf("No se encontro el id\n");
    fclose(fp);
    fclose(baja);
    return registro;
}
