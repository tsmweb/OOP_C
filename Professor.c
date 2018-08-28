/*
 * Tipo: Professor
 * Super: Pessoa
 * Descrição: Arquivo de implementação do tipo Professor
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "Professor.h"

#include <stdlib.h>
#include <stdio.h>

Professor Professor_new(char *nome, int idade, char *disciplina, int qtdeAulas) 
{
	Professor self = malloc(sizeof *self);

	static struct PessoaVtbl const vtbl = { &Professor_virtual_imprimi };

	Pessoa_new(&self->super, nome, idade);

	self->super.vptr = &vtbl;
	self->disciplina = disciplina;
	self->qtdeAulas = qtdeAulas;

	return self;
}

void Professor_free(Professor self) 
{
	if (self) free(self);
}

static void Professor_virtual_imprimi(Pessoa * const self) 
{
	Professor professor = (Professor)self;
	printf("\t[>] Nome: %s\n", professor->super.nome);
	printf("\t[>] Idade: %d\n", professor->super.idade);
	printf("\t[>] Disciplina: %s\n", professor->disciplina);
	printf("\t[>] Qtde Aulas: %d\n\n", professor->qtdeAulas);
}

void Professor_imprimi(Object *instance)
{
	Professor professor = (Professor)instance;
	printf("\t[>] Nome: %s\n", professor->super.nome);
	printf("\t[>] Idade: %d\n", professor->super.idade);
	printf("\t[>] Disciplina: %s\n", professor->disciplina);
	printf("\t[>] Qtde Aulas: %d\n\n", professor->qtdeAulas);
}