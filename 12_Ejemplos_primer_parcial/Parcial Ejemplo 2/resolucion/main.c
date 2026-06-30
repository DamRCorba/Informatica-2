#include <stdio.h>
#include <string.h>

typedef struct
{
    long legajo;
    char materia[30];
    char nombreApellido[90]; // nombre, apellido
    int parcial;             //
    int nota;
}notas_t;

typedef struct
{
    long legajo;
    char nombreApellido[90];
    char materia[30];
    int parciales;
}materias_t;

int crearMateria(long legajo, char *materia);
int imprimirAprobadas(void);

int main(int argc, char const *argv[])
{
    if(crearMateria(35105, "Informatica 2")){
        printf("\nError al abrir algun archivo\n");
        return 1;
    }
    if (imprimirAprobadas())
    {
        printf("\nError al abrir algun archivo\n");
        return 1;
    }
    return 0;
}

int crearMateria(long legajo, char *NombreMateria){
    FILE *notas, *materias;
    notas_t nota;
    materias_t materia;

    if((notas=fopen("notas.dat","rb"))==NULL) {
        return 1;
    }
    if ((materias = fopen("materias.dat", "ab")) == NULL)
    {
        return 1;
    }

    fread(&nota,sizeof(notas_t),1,notas);
    while (!feof(notas))
    {
        if ((legajo == nota.legajo) && !strcmp(nota.materia, NombreMateria)){
            materia.legajo = nota.legajo;
            strcpy(materia.materia, nota.materia);
            strcpy(materia.nombreApellido,nota.nombreApellido);
            if(nota.nota >= 4){
                materia.parciales |= (1<<nota.parcial);
            }
        }

        fread(&nota, sizeof(notas_t), 1, notas);
    }

    if(materia.legajo == legajo){ // si hay al menos un registro para la materia para ese alumno
        fwrite(&materia,sizeof(materias_t),1,materias);
    } else {
        printf("\nNo se encontro registro para ese alumno y esa materia\n");
    }
    fclose(notas);
    fclose(materias);
    return 0;
}

int imprimirAprobadas(void){
    FILE *materias;
    materias_t materia;
    char *s1, apellidoNombre[90];

    if ((materias = fopen("materias.dat", "rb")) == NULL)
    {
        return 1;
    }

    fread(&materia, sizeof(materias_t),1,materias);
    while (!feof(materias))
    {
        // if (((materia.parciales & (1 << 0)) || (materia.parciales & (1 << 1)) || (materia.parciales & (1 << 2))) 
        //  && ((materia.parciales & (1 << 3)) || (materia.parciales & (1 << 4)) || (materia.parciales & (1 << 5)))
        //  && ((materia.parciales & (1 << 6)))){
        //  }
        if((materia.parciales&0b111) && (materia.parciales&0b111000)&& (materia.parciales&(1<<6))){
            s1 = materia.nombreApellido;
            while (*s1 != ' ' && *s1) s1++;
            *s1 = 0; // *s1='\0'; 
            strcpy(apellidoNombre,s1+1);
            strcat(apellidoNombre,", ");
            strcat(apellidoNombre,materia.nombreApellido);
            strcpy(materia.nombreApellido,apellidoNombre);
            printf("\n######################################\nLegajo: %ld, Nombre: %s\nMateria: %s - Aprobada\n######################################",materia.legajo, materia.nombreApellido, materia.materia);
                }
        fread(&materia, sizeof(materias_t), 1, materias);
    }
    fclose(materias);
    return 0;
}