/*La información de alumnos de los cursos activos (los del cuatrimestre) de una universidad,
donde se sabe que todos los cursos tienen un cupo máximo de 50 alumnos.
Los accesos más comunes serán por Nombre del curso, 
y para un curso por legajo de alumno (para buscar un alumno se indica nombre de curso y legajo).
*/




typedef struct courseData {
    char courseName[50];
    int enrollmentCount;
    int studentIDs[50];
} CourseData;

typedef struct universityData {
    CourseData *courses;
    int courseCount;
} UniversityData;
