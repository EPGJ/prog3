#ifndef ALUNO_H_
#define ALUNO_H_

typedef struct aluno *tStudent;

char *getNameStudent(tStudent);
float getGradeStudent(tStudent);
tStudent createStudent(char *, float);
void destroyStudent(tStudent);

#endif