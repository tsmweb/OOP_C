/*
 * Tipo: Aluno
 * Super: Pessoa
 * Descrição: Arquivo de definição do tipo Aluno
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef Aluno_H
#define Aluno_H

#include "Pessoa.h"

// tipo Aluno com supertipo Pessoa
typedef struct Aluno_ 
{
	Pessoa super;
	char *turma;
	int nota;
} *Aluno;

// construtor para o tipo Aluno
Aluno Aluno_new(char *nome, int idade, char *turma, int nota);

// destrutor para o tipo Aluno
void Aluno_free(Aluno self);

// método virtual (private)
static void Aluno_virtual_imprimi(Pessoa * const self);

// implementa a interface IImprimi
void Aluno_imprimi(Object *instance);

#endif
