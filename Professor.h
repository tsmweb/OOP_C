/*
 * Tipo: Professor
 * Super: Pessoa
 * Descrição: Arquivo de definição do tipo Professor
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef Professor_H
#define Professor_H

#include "Pessoa.h"

// tipo Professor com supertipo Pessoa
typedef struct Professor_ 
{
	Pessoa super;
	char *disciplina;
	int qtdeAulas;
} *Professor;

// construtor para o tipo Professor
Professor Professor_new(char *nome, int idade, char *disciplina, int qtdeAulas);

// destrutor para o tipo Professor
void Professor_free(Professor self);

// método virtual (private)
static void Professor_virtual_imprimi(Pessoa * const self);

// implementa a interface IImprimi
void Professor_imprimi(Object *instance);

#endif
