#include "listaExercicio.h"
#include <string.h>

tStudent setStudent(char* name, float grade){
    tStudent student;
    strcpy(student.name,name);
    student.grade = grade;
    return student;
}
char* getNameStudent(tStudent student){
    printf("%s", student.name);
}
float getGradeStudent(tStudent student);
