/*
 * tAluno.h
 *
 *  Created on: Aug 5, 2015
 *      Author: vitor
 */

#ifndef TALUNO_H_
#define TALUNO_H_

// Define o tipo tAluno como sendo equivalente a uma estrutura que será definida em tAluno.c.
typedef struct TAluno {
	char nome[50];
	float nota;
} tAluno;

// Operação de criação de um aluno.
tAluno criarAluno(char *nome, float nota);

// Operação de obtenção do nome de um aluno.
char* obterNomeAluno(tAluno aluno);

// Operação de obtenção da nota de um aluno.
float obterNotaAluno(tAluno aluno);

#endif
/* TALUNO_H_ */
