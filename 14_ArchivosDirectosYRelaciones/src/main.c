#include "mylibs.h"
#include <string.h>

int main(int argc, char const *argv[])
{
    void (*listar[]) (void) = { listarTodo, listarPorAlumno, listarPorProfesor};
    unsigned char opcion;

    // printf ("%d", argc);

    // printf("%s", argv[0]);
    // printf("%s", argv[1]);
    if(argc == 1) { // no me pasaron parametros
        opcion = 0;
    }
    else {
        if (!strcmp(argv[1], "todo"))
            opcion = 0;
        else if (!strcmp(argv[1], "alumno"))
                opcion = 1;
        else if (!strcmp(argv[1], "profesor"))
            opcion = 2;
    }

    listar[opcion]();
    return 0;
}

