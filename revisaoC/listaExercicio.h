#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[100];
    float grade;    
}tStudent;
tStudent setStudent(char* name, float grade);
char* getNameStudent(tStudent student);
float getGradeStudent(tStudent student);