#include <stdio.h>
typedef struct
{
    long id;
    char categoria[90];
    float valor;
    unsigned int estado;
}datos_t;
long funcion (long id);
int main(int argc, char const *argv[])
{
    long user_id, respuesta;
    printf("Hola, que id queres buscar? ");
    scanf("%ld",&user_id);
    respuesta = funcion(user_id);
    if(respuesta == -1) {
        printf("\nError, No se pudo abrir el archivo.\n");
        return -1;
    }
    if(respuesta == 0) {
        printf("\nNo se encontro el registro en el archivo\n");
    } else {
        printf("\nQuedan %ld registros hasta el fin de archivo.\n", respuesta-1);
    }
    return 0;
}
long funcion(long id)
{
    datos_t fileDato;
    FILE *fp;
    long ubicacion=0, total=1;
    char *s;

    if((fp=fopen("datos.dat","rb+")) == NULL) {        
        return -1;
    }
    fread(&fileDato, sizeof(datos_t),1,fp);    
    while (!feof(fp))    {
        //printf("\nID: %d, Categoria: %s, Valor: %f, Estado: %d", fileDato.id,fileDato.categoria,fileDato.valor,fileDato.estado);
        if(fileDato.id == id) {
          //  printf(" -> ES LA CLAVE BUSCADA");
            ubicacion=total;
            if(fileDato.estado & (1<<3)){
                s = fileDato.categoria;
                while (*s)
                {
                    if(*s >='a' && *s <= 'z'){
                        *s -= ('a'-'A'); // -32
                    }
                    s++;
                }
                fseek(fp, -1L*sizeof(datos_t), SEEK_CUR);
                fwrite(&fileDato,sizeof(datos_t),1,fp);
            }
        }
        fread(&fileDato, sizeof(datos_t), 1, fp);
        total++;
    }
   fclose(fp);
   if(ubicacion == 0) return 0;
   else return total - ubicacion;
}
