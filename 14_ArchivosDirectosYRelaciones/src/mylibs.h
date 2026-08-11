#ifndef MYLIBS_H
#define MYLIBS_H

#include <stdio.h>

typedef struct
{
    long legajo;
    long dni;
    char nombre[40];
} alumnos_t;

typedef struct
{
    long id_materia;    
    char nombre[40];

} materias_t;

typedef struct
{
    long dni; // no puede ser clave de organizacion para este ambito.
    long legajo;
    char nombre[40];
} profesores_t;

typedef struct
{
    long legajo_profesor;
    long legajo_alumno;
    long id_materia;
    char especialidad;

} inscripciones_t;

void listarTodo(void);
void listarPorAlumno(void);
void listarPorProfesor(void);


profesores_t leerInfoProfesores(long id);
alumnos_t leerInfoAlumnos(long id);
materias_t leerInfoMaterias(long id);
#endif