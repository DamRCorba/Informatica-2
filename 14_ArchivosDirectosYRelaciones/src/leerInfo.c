#include "mylibs.h"

profesores_t leerInfoProfesores(long id){
    FILE *fp;
    profesores_t data = {0};

    if((fp = fopen("profesores.dat", "rb")) == NULL){
        printf("No se pudo abrir el archivo");
        return data;
    }
    fseek(fp,(long)(sizeof(profesores_t)*(id-1)),SEEK_SET);
    fread(&data,sizeof(profesores_t),1,fp);
    if( id != data.legajo) {
        printf("Archivo corrupto, verificar datos");
        fclose(fp);
        return ;
    }
    fclose(fp);
    return data;
}

alumnos_t leerInfoAlumnos(long id){
    FILE *fp;
    alumnos_t data = {0};
    if ((fp = fopen("alumnos.dat", "rb")) == NULL)
    {
        printf("No se pudo abrir el archivo");
        return data;
    }
    fseek(fp, (long)(sizeof(alumnos_t) * (id - 1)), SEEK_SET);
    fread(&data, sizeof(alumnos_t), 1, fp);
    if (id != data.legajo)
    {
        printf("Archivo corrupto, verificar datos");
        fclose(fp);
        return;
    }
    fclose(fp);
    return data;
}

materias_t leerInfoMaterias(long id){
    FILE *fp;
    materias_t data = {0};
    if ((fp = fopen("materias.dat", "rb")) == NULL)
    {
        printf("No se pudo abrir el archivo");
        return data;
    }
    fseek(fp, (long)(sizeof(materias_t) * (id - 1)), SEEK_SET);
    fread(&data, sizeof(materias_t), 1, fp);
    if (id != data.id_materia)
    {
        printf("Archivo corrupto, verificar datos");
        fclose(fp);
        return;
    }
    fclose(fp);
    return data;
}