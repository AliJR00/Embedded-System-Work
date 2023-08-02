
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Sstudent
{
	int ID;
	char name[30];
	float height;
	struct Sstudent* Pnext;
}student;


student* firstmember = NULL;
int count = 0;

int recorddata(student* member)
{
	int num;
	printf("enter the student ID: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &(num));

	student* current = firstmember;
	while(current)
	{
		if(current->ID == num && current != member)
			{
			printf("The student ID already exists.\n");
			free(member);
			return 0;
			}
		else
			{
			member->ID = num;
			current = current->Pnext;
			}
	}

	printf("enter the student name: ");
	fflush(stdout); fflush(stdin);
	gets(member->name);

	printf("enter the student height: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &(member->height));

	return 1;


}

void AddStudent()
{


	student* newstudent;
	newstudent = (student*) malloc(sizeof(student));

	student* lap = firstmember;
	if(firstmember)
	{
		while(lap->Pnext)
			lap = lap->Pnext;
		lap->Pnext = newstudent;
	}
	else
	{
		firstmember = newstudent	;
	}
	newstudent->Pnext = NULL;

	if(recorddata(newstudent) == 1)
	count++;

}


int DeleteStudent()
{
	int entered;

	printf("Enter student ID number to be deleted: ");
	fflush(stdout);
	scanf("%d", &entered);


	if(firstmember == NULL)
	{
		printf("There are no students in the base!\n");
		return 0;
	}

	student* pre;
	student* current = firstmember;

	while(current)
	{
		if(current->ID == entered)
		{
			if(current == firstmember)
				firstmember = current->Pnext;
			else
			{
				pre->Pnext = current->Pnext;
			}
			free(current);
			count--;
			return 1;

		}
		pre = current;
		current = current->Pnext;
	}
	printf("the entered ID couldn't be found!\n");
	return 0;

}



int ViewStudents()
{
	student* current = firstmember;

	if(current == NULL)
	{
		printf("There are no students!\n");
		return 0;
	}

	printf("The number of students is %d.\n", count);

	while(current)
	{
		printf("ID: %d\n", current->ID);
		printf("Name: %s\n", current->name);
		printf("Height: %.2f\n", current->height);
		printf("\n");

		current = current->Pnext;
	}
	return 1;


}


int DeleteAll()
{
	student* current = firstmember;
	char entered;
	if(current == NULL)
	{
		printf("There are no students!\n");
		return 0;
	}

	printf("Are you sure of deleting all data?\nEnter Y or N: 	");
	fflush(stdout); fflush(stdin);
	scanf("%c", &entered);


	if(entered == 'Y')
	{
		while(current)
		{
			student* temp;
			temp = current;
			current = current->Pnext;
			free(temp);
		}
		firstmember = NULL;
		return 1;
	}

	return 0;


}


int SearchStudent()
{
	if(firstmember == NULL)
	{
		printf("The list is empty.\n");
		return 0;
	}
	int num;
	printf("Please enter the student ID: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num);

	student* current = firstmember;

	while(current)
	{
		if(current->ID == num)
		{
			printf("ID: %d\n", current->ID);
			printf("Name: %s\n", current->name);
			printf("Height: %.2f\n", current->height);
			printf("\n");

			return 1;
		}
		current = current->Pnext;

	}
	printf("There's no student with that ID.\n");
	return 0;
}

int ModifyStudent()
{
	int num;
	printf("Please enter the student ID to be modified: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num);

	student* current = firstmember;
	while(current)
	{
		if(current->ID == num)
		{
			recorddata(current);
			return 1;
		}
		current = current->Pnext;

	}

	printf("The student doesn't exist.\n");
	return 0;
}

int GetNth()
{
	int num;

	printf("Please enter the number to be searched for the chronological order\n ");
	printf("starting with zero: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num);

	if(num>=count)
	{
		printf("There's no such number.\n");
		return 0;
	}

	student* current = firstmember;

	while(num--)
	{
		current = current->Pnext;
	}

	printf("ID: %d\n", current->ID);
	printf("Name: %s\n", current->name);
	printf("Height: %.2f\n", current->height);
	printf("\n");
	return 1;

}

int GetNth_end()
{
	int num, counter=0;

	printf("Please enter the number to be searched for the end chronological order\n ");
	printf("starting with zero: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num);

	if(num>=count)
	{
		printf("There's no such number.\n");
		return 0;
	}

	student* current = firstmember;
	student* offset = firstmember;

	while(current)
	{
		current = current->Pnext;
		if(counter > num)
			offset = offset->Pnext;
		counter++;
	}

	printf("ID: %d\n", offset->ID);
	printf("Name: %s\n", offset->name);
	printf("Height: %.2f\n", offset->height);
	printf("\n");
	return 1;

}


void Middle()
{
	int counter = 1;
	student* current = firstmember;
	student* pre = firstmember;

	while(current)
	{
		current = current->Pnext;
		if(counter%2==0)
			pre = pre->Pnext;

		counter++;
	}


	printf("The middle of the list is at index %d.\n", ((counter-1)/2));
	printf("ID: %d\n", pre->ID);
	printf("Name: %s\n", pre->name);
	printf("Height: %.2f\n", pre->height);
	printf("\n");

}

int Reverse()
{
	student* current ;
	student* pre = NULL ;
	student* temp = firstmember ;

	if(firstmember == NULL)
		{
			printf("The list is empty.\n");
			return 0;
		}

	while(temp)
	{
		current = temp;
		temp = temp->Pnext;
		current->Pnext = pre;
		pre = current;
	}
	firstmember = pre;
	return 1;
}



#endif
