#include "aluno.h"
#include <stdlib.h>

struct aluno
{
    char name[100];
    float grade;
};

char *getNameStudent(tStudent student)
{
    return student->name;
}
float getGradeStudent(tStudent student)
{
    return student->grade;
}
tStudent createStudent(char *name, float grade)
{
    tStudent student = (tStudent)malloc(sizeof(struct aluno));
    strcpy(student->name, name);
    student->grade = grade;
    return student;
}
void destroyStudent(tStudent student){
    free(student);
}