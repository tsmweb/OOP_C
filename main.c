/*
 * Description: Main method (main) that demonstrates the use of defined types (Professor and Student) 
 * following the OOP paradigm.
 * 
 * To compile: gcc -o oop print.h object.h person.c student.c teacher.c main.c
 * 
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#include "student.h"
#include "teacher.h"
#include "print.h"

#include <stdio.h>

static inline void override_print(const Person* const person) 
{
	(person->vptr->print)(person);
}

static inline void print(IPrint imp)
{
	imp.print(imp.instance);
}

int main(int argc, char** argv) 
{
	// Teacher type object
	printf("[*] TEACHER \n");
	Teacher* teacher = Teacher_new("Saulo", 45, "SO II", 2);
	override_print(&teacher->super);
	
	printf("[*] TEACHER (interface)\n");
	IPrint iTeacher = {
		(Object*)teacher,
		Teacher_print
	};

	print(iTeacher);
	Teacher_free(teacher);
	
	// object of type Student
	printf("[*] STUDENT\n");
	Student* student = Student_new("Jonas", 16, "SO II", 9);
	override_print(&student->super);

	printf("[*] STUDENT (interface)\n");
	IPrint iStudent = {
		(Object*)student,
		Student_print
	};

	print(iStudent);
	Student_free(student);
	
	return 0;
}
