/*
 * Tipo: Aluno
 * Super: Pessoa
 * Descrição: Arquivo de implementação do tipo Aluno
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "Aluno.h"

#include <stdlib.h>
#include <stdio.h>

Aluno Aluno_new(char *nome, int idade, char *turma, int nota) 
{
	Aluno self = malloc(sizeof *self);

	static struct PessoaVtbl const vtbl = { &Aluno_virtual_imprimi };

	Pessoa_new(&self->super, nome, idade);

	self->super.vptr = &vtbl;
	self->turma = turma;
	self->nota = nota;

	return self;
}

void Aluno_free(Aluno self) 
{
	if (self) free(self);
}

static void Aluno_virtual_imprimi(Pessoa * const self) 
{
	Aluno aluno = (Aluno)self;
	printf("\t[>] Nome: %s\n", aluno->super.nome);
	printf("\t[>] Idade: %d\n", aluno->super.idade);
	printf("\t[>] Turma: %s\n", aluno->turma);
	printf("\t[>] Nota: %d\n\n", aluno->nota);
}

void Aluno_imprimi(Object *instance)
{
	Aluno aluno = (Aluno)instance;
	printf("\t[>] Nome: %s\n", aluno->super.nome);
	printf("\t[>] Idade: %d\n", aluno->super.idade);
	printf("\t[>] Turma: %s\n", aluno->turma);
	printf("\t[>] Nota: %d\n\n", aluno->nota);
}