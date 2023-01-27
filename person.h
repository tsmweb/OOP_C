/*
 * Type: Person
 * Super: Object
 * Description: Person type definition file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef Person_H
#define Person_H

#include "object.h"

#include <stdbool.h>

// structure of virtual methods
struct PersonVtbl;

// type Person with supertype Object
typedef struct Person_
{
	Object super;
	const struct PersonVtbl* vptr;

	char* name;
	int age;
} Person;

struct PersonVtbl 
{
	void (*print)(const Person* const self);
};

// constructor for type Person
bool Person_new(Person* const self, char* name, int age);
// destructor for type Person
void Person_free(Person* const self);

// virtual method (private)
static void Person_virtual_print(const Person* const self);

#endif
