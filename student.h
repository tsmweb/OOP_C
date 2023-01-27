/*
 * Type: Student
 * Super: Person
 * Description: Student type definition file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef Student_H
#define Student_H

#include "person.h"

// type Student with supertype Person
typedef struct Student_ 
{
	Person super;
	char* matter;
	int grade;
} Student;

// constructor for type Student
Student* Student_new(char* name, int age, char* matter, int grade);

// destructor for type Student
void Student_free(Student* const self);

// virtual method (private)
static void Student_virtual_print(const Person* const self);

// implements the IPrint interface
void Student_print(const Object* instance);

#endif
