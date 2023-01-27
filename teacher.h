/*
 * Type: Teacher
 * Super: Person
 * Description: Teacher type definition file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef Teacher_H
#define Teacher_H

#include "person.h"

// Teacher type with Person supertype
typedef struct Teacher_ 
{
	Person super;
	char* matter;
	int totalClasses;
} Teacher;

// constructor for type Teacher
Teacher* Teacher_new(char* name, int age, char* matter, int totalClasses);

// destructor for type Professor
void Teacher_free(Teacher* const self);

// virtual method (private)
static void Teacher_virtual_print(const Person* const self);

// implements the IPrint interface
void Teacher_print(const Object* instance);

#endif
