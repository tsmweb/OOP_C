/*
 * Descrição: Método principal (main) que demonstra a utilização dos tipos definidos (Professor e Aluno) 
 * seguindo o paradigma de OOP.
 * 
 * Compilar: gcc -o oop imprimir.h object.h pessoa.c aluno.c professor.c main.c
 * 
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "aluno.h"
#include "professor.h"
#include "imprimir.h"

#include <stdio.h>

static inline void imprimi_override(Pessoa * const pessoa) 
{
	(pessoa->vptr->imprimi)(pessoa);
}

static inline void imprimi(IImprimir imp)
{
	imp.imprimi(imp.instance);
}

int main(int argc, char **argv) 
{
	// objeto do tipo Professor
	printf("[*] PROFESSOR \n");
	Professor professor = Professor_new("Saulo", 45, "SO II", 2);
	imprimi_override(&professor->super);
	
	printf("[*] PROFESSOR (interface)\n");
	IImprimir iProfessor = {
		(Object*)professor,
		Professor_imprimi
	};

	imprimi(iProfessor);
	Professor_free(professor);
	
	// objeto do tipo Aluno
	printf("[*] ALUNO\n");
	Aluno aluno = Aluno_new("Jonas", 16, "2A", 9);
	imprimi_override(&aluno->super);

	printf("[*] ALUNO (interface)\n");
	IImprimir iAluno = {
		(Object*)aluno,
		Aluno_imprimi
	};

	imprimi(iAluno);
	Aluno_free(aluno);
	
	return 0;
}
