/*
 * Tipo: Pessoa
 * Super: Object
 * Descrição: Arquivo de definição do tipo Pessoa
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef Pessoa_H
#define Pessoa_H

#include "object.h"

// estrutura de métodos virtuais
struct PessoaVtbl;

// tipo Pessoa com supertipo Object 
typedef struct Pessoa_
{
	Object super;
	struct PessoaVtbl const *vptr;

	char *nome;
	int idade;
} Pessoa;

struct PessoaVtbl 
{
	void (*imprimi)(Pessoa * const self);
};

// construtor para o tipo Pessoa
Pessoa *Pessoa_new(Pessoa * const self, char *nome, int idade);
// destrutor para o tipo Pessoa
void Pessoa_free(Pessoa * const self);

// método virtual
static void Pessoa_virtual_imprimi(Pessoa * const self);

#endif
