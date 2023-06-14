struct node {

    char * name;

    struct node * tail;

};



typedef  struct node *  TList;



// Una materia, con su nombre y lista de alumnos

typedef struct TSubject {

   char * name;  // nombre de la materia

   TList first;   // puntero al primer alumno

}  TSubject;



struct courseCDT {

    size_t cant;        

    TSubject * subjects;   // vector de cant structs materias, cada una con sus alumnos

    int next;  // para poder iterar por los cursos

    TList nextStudent;   // para poder iterar en forma ordenada por los alumnos

};



static char * strCpy(const char * s) {

    return strcpy(malloc(strlen(s)+1), s);

}



char * toBeginForSubject(courseADT course , size_t subject){

    if ( subject < 1 || subject > course->cant) {

        return NULL;

    }

    course->nextStudent = course->subjects[subject-1].first;

    return strCpy(course->subjects[subject-1].name);

}



courseADT newCourseADT(size_t qty) {

    courseADT aux = calloc(1, sizeof(struct courseCDT));

    aux->subjects = calloc(qty, sizeof(TSubject));

    // Inicializamos las materias con nombre vacio

    for(size_t i=0; i < qty; i++) {

        aux->subjects[i].name = strCpy("");

    }

    aux->cant = qty;

    return aux;

}
