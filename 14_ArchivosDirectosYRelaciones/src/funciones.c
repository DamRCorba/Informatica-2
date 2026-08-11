#include "mylibs.h"

void listarTodo(void) { 
    
    inscripciones_t inscript;
    profesores_t profe;
    alumnos_t alumn;
    materias_t materia;
    FILE *fRelaciones;

    if((fRelaciones = fopen("inscriptos.dat","rb")) == NULL) {
        printf("Error al abrir el archivo;");
        return 1;
    }

    fread(&inscript, sizeof(inscripciones_t),1,fRelaciones);
    while (!feof(fRelaciones))
    {
        materia = leerInfoMaterias(inscript.id_materia);
        profe = leerInfoProfesores(inscript.legajo_profesor);
        alumn = leerInfoAlumnos(inscript.legajo_alumno);
        printf("Especialidad: %c, Profesor: %s, Alumno: %s, Legajo: %s, NombreMateria: %s", inscript.especialidad, profe.nombre,alumn.nombre, alumn.legajo, materia.nombre);
        fread(&inscript, sizeof(inscripciones_t), 1, fRelaciones);
    }
    fclose(fRelaciones);
    return;
    
}

void listarPorAlumno(void) { printf("Pide listar alumno\n"); }

void listarPorProfesor(void) { printf("Pide listar profesor\n"); }

