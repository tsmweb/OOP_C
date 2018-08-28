/*
 * Tipo: Pessoa
 * Super: Object
 * Descrição: Arquivo de implementação do tipo Pessoa
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "Pessoa.h"

#include <stdlib.h>
#include <stdio.h>

Pessoa *Pessoa_new(Pessoa * const self, char *nome, int idade) 
{
	self->super.klass = "Pessoa";
	
	static struct PessoaVtbl vtbl = { &Pessoa_virtual_imprimi }; 

	self->vptr 	= &vtbl;
	self->nome 	= nome;
	self->idade = idade;

	return self;
}

void Pessoa_free(Pessoa * const self) 
{
	if (self) free(self);
}

static void Pessoa_virtual_imprimi(Pessoa * const self) 
{
	printf("\t[>] Nome: %s\n", self->nome);
	printf("\t[>] Idade: %d\n", self->idade);
}

