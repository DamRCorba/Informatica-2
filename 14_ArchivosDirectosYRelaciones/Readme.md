# Archivos directos

## Ejemplo

Tenemos un archivo de alumnos el cual tiene la siguiente estructura:

```c
    typedef struct {
        long legajo;
        long dni;
        char nombre[40];
        char especialidad;
    } alumnos_t;
```

Tenemos otro archivo el cual tiene las materias:

```c
    typedef struct {
        long id_materia;
        long legajo;
        char nombre[40];
        char especialidad;
        char nombre_profesor[60];
    } materias_t;
```

Tenemos otro archivo el cual tiene los profesores:

```c
    typedef struct {
        long dni;
        long legajo;
        char nombre[40];
        char especialidad;
        char nombre_profesor[60];
    } profesores_t;
```

Inscripciones:

```c
    typedef struct {
        long legajo_profesor;
        long legajo_alumno;
        long id_materia;
        char especialidad;
        
    } inscripciones_t;
```

- Hacer una funcion que liste a los inscriptos de las materias con el nombre del profesor y del alumno.
- Hacer una funcion que lista para el alumno todas sus materias inscriptas con su nombre de profesor.
- Hacer una funcion que lista para el profesor todas sus materias con sus alumnos inscriptos.

El programa se ejecuta con la siguiente forma
si no paso argumento ejecuta tambien a listar todo
programa todo -> ejecuta el listar todo
programa alumno -> ejecuta el listar por alumno
programa profesor -> ejecuta el listar por profesor
