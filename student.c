/*
 * Type: Student
 * Super: Person
 * Description: Student-type implementation file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "student.h"

#include <stdlib.h>
#include <stdio.h>

Student* Student_new(char* name, int age, char* matter, int grade) 
{
	Student* self = malloc(sizeof *self);

	static struct PersonVtbl const vtbl = { &Student_virtual_print };

	Person_new(&self->super, name, age);

	self->super.vptr = &vtbl;
	self->matter = matter;
	self->grade = grade;

	return self;
}

void Student_free(Student* const self) 
{
	if (self) free(self);
}

static void Student_virtual_print(const Person* const self) 
{
	Student* student = (Student*)self;
	printf("\t[>] Name: %s\n", student->super.name);
	printf("\t[>] Age: %d\n", student->super.age);
	printf("\t[>] Matter: %s\n", student->matter);
	printf("\t[>] Grade: %d\n\n", student->grade);
}

void Student_print(const Object* instance)
{
	Student* student = (Student*)instance;
	printf("\t[>] Name: %s\n", student->super.name);
	printf("\t[>] Age: %d\n", student->super.age);
	printf("\t[>] Matter: %s\n", student->matter);
	printf("\t[>] Grade: %d\n\n", student->grade);
}