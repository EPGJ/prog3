/*
 * tAluno.c
 *
 *  Created on: Aug 5, 2015
 *      Author: vitor
 */

#include <stdlib.h>
#include <string.h>
#include "tAluno.h"

// Define a estrutura declarada no arquivo cabeçalho.
struct TAluno {
	char nome[50];
	float nota;
};

// Operação de criação de um aluno.
tAluno criarAluno(char *nome, float nota) {
	tAluno aluno = (tAluno)malloc(sizeof(struct TAluno));
	strcpy(aluno->nome, nome);
	aluno->nota = nota;
	return aluno;
}

// Operação de obtenção do nome de um aluno.
char* obterNomeAluno(tAluno aluno) {
	return aluno->nome;
}

// Operação de obtenção da nota de um aluno.
float obterNotaAluno(tAluno aluno) {
	return aluno->nota;
}

// Compara dois alunos por nome, funciona como strcmp().
int comparaPorNomeAluno(const void* p1, const void* p2) {
	tAluno a1 = *(tAluno*)p1;
	tAluno a2 = *(tAluno*)p2;
	return strcmp(a1->nome, a2->nome);
}


// Operação de destruição de um aluno.
void destruirAluno(tAluno aluno) {
	free(aluno);
}
