
#ifndef STUDENT_DATABASE_H_
#define STUDENT_DATABASE_H_

#include "stdio.h"


int add_student_manually();
void show_s();
void find_rl();
void find_fn();
void find_c();
void tot_s();
int del_s();
int up_s();
int add_student_file();

typedef struct
{
	char Fname[30];
	char Lname[30];
	int roll;
	float gpa;
	int Cid[5];
}student;



#endif
