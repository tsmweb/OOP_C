/*
 * Type: Person
 * Super: Object
 * Description: Person type implementation file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "person.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool Person_new(Person * const self, char *name, int age) 
{
	if (self == NULL)
		return false;

	self->super.klass = "Person";
	
	static struct PersonVtbl vtbl = { &Person_virtual_print }; 

	self->vptr = &vtbl;
	self->name = name;
	self->age = age;

	return true;
}

void Pessoa_free(Person * const self) 
{
	if (self) free(self);
}

static void Person_virtual_print(const Person * const self) 
{
	printf("\t[>] Name: %s\n", self->name);
	printf("\t[>] Age: %d\n", self->age);
}
