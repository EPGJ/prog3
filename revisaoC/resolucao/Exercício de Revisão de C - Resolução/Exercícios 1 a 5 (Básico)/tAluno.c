/*
 * tAluno.c
 *
 *  Created on: Aug 5, 2015
 *      Author: vitor
 */

#include <string.h>
#include "tAluno.h"

// Operação de criação de um aluno.
tAluno criarAluno(char *nome, float nota) {
	tAluno aluno;
	strcpy(aluno.nome, nome);
	aluno.nota = nota;
	return aluno;
}

// Operação de obtenção do nome de um aluno.
char* obterNomeAluno(tAluno aluno) {
	return aluno.nome;
}

// Operação de obtenção da nota de um aluno.
float obterNotaAluno(tAluno aluno) {
	return aluno.nota;
}
