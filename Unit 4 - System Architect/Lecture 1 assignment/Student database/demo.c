#include "linked_list.h"



void main(void)
{
	while(1)
	{
		int num;

		printf("1: Add a student.\n");
		printf("2: search for a student by ID.\n");
		printf("3: search for a student by index.\n");
		printf("4: search for a student by index from the end.\n");
		printf("5: modify a student info.\n");
		printf("6: delete a student.\n");
		printf("7: view all students.\n");
		printf("8: view the middle of the list.\n");
		printf("9: reverse the list.\n");
		printf("10: delete all students.\n");

		printf("enter option number: ");
		fflush(stdout);

		scanf("%d", &num);


		switch (num)
		{
		case 1:
			AddStudent();
			break;
		case 2:
			SearchStudent();
			break;
		case 3:
			GetNth();
			break;
		case 4:
			GetNth_end();
			break;
		case 5:
			ModifyStudent();
			break;
		case 6:
			DeleteStudent();
			break;
		case 7:
			ViewStudents();
			break;
		case 8:
			Middle();
			break;
		case 9:
			Reverse();
			break;
		case 10:
			DeleteAll();
			break;
		default:
			printf("Wrong input!\n");
			break;
		}

	}





}



