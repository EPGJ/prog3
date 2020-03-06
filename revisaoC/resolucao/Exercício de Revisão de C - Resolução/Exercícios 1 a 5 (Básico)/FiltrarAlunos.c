/*
 * FiltrarAlunos.c
 *
 *  Created on: Aug 5, 2015
 *      Author: vitor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAluno.h"

/* Programa principal. */
int main(int argc, char **argv) {
	char* nomeArquivo;
	char linha[255];

	// Verifica se o nome do arquivo foi passado como argumento.
	if (argc > 1) {
		nomeArquivo = argv[1];
	}

	// Não foi passado o nome do arquivo por argumento. Solicita via entrada padrão.
	else {
		printf("Arquivo de entrada: ");
		nomeArquivo = (char *)malloc(255 * sizeof(char));
		scanf("%s", nomeArquivo);
	}

	// Lê a primeira linha do arquivo, que contém o número de alunos.
	FILE* arquivo = fopen(nomeArquivo, "r");
	int numAlunos = 0;
	fscanf(arquivo, "%d\n", &numAlunos);

	// Aloca espaço para o número de alunos indicado e lê os dados dos alunos do arquivo.
	char nome[50];
	float nota;
	int idx = 0;
	tAluno* alunos = (tAluno*)malloc(numAlunos * sizeof(struct TAluno));
	while (fgets(linha, sizeof(linha), arquivo)) {
		linha[strlen(linha) - 1] = '\0';
		sscanf(linha, "%f %s", &nota, nome);
		alunos[idx++] = criarAluno(nome, nota);
	}
	fclose(arquivo);

	// Calcula a média da turma.
	float media = 0;
	for (idx = 0; idx < numAlunos; idx++) media += obterNotaAluno(alunos[idx]);
	media /= numAlunos;

	// Abre o arquivo saida.csv para escrita e escreve o cabeçalho.
	arquivo = fopen("saida.csv", "w");
	fprintf(arquivo, "Nome,Nota,Situação\n");

	// Imprime na tela os alunos que estão acima da média e no arquivo todos os alunos.
	for (idx = 0; idx < numAlunos; idx++) {
		char* aluno = obterNomeAluno(alunos[idx]);
		nota = obterNotaAluno(alunos[idx]);

		if (nota > media) printf("%s\n", aluno);

		if (nota >= 7.0) fprintf(arquivo, "%s,%.2f,Aprovado\n", aluno, nota);
		else fprintf(arquivo, "%s,%.2f,Prova Final\n", aluno, nota);
	}
	fclose(arquivo);
}
