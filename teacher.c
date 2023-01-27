/*
 * Type: Teacher
 * Super: Person
 * Description: Teacher type implementation file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "teacher.h"

#include <stdlib.h>
#include <stdio.h>

Teacher* Teacher_new(char* name, int age, char* matter, int totalClasses) 
{
	Teacher* self = malloc(sizeof *self);

	static struct PersonVtbl const vtbl = { &Teacher_virtual_print };

	Person_new(&self->super, name, age);

	self->super.vptr = &vtbl;
	self->matter = matter;
	self->totalClasses = totalClasses;

	return self;
}

void Teacher_free(Teacher* const self)
{
	if (self) free(self);
}

static void Teacher_virtual_print(const Person* const self) 
{
	Teacher* teacher = (Teacher*)self;
	printf("\t[>] Name: %s\n", teacher->super.name);
	printf("\t[>] Age: %d\n", teacher->super.age);
	printf("\t[>] Matter: %s\n", teacher->matter);
	printf("\t[>] Total Classes: %d\n\n", teacher->totalClasses);
}

void Teacher_print(const Object* instance)
{
	Teacher* teacher = (Teacher*)instance;
	printf("\t[>] Name: %s\n", teacher->super.name);
	printf("\t[>] Age: %d\n", teacher->super.age);
	printf("\t[>] Matter: %s\n", teacher->matter);
	printf("\t[>] Total Classes: %d\n\n", teacher->totalClasses);
}