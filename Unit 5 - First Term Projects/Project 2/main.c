#include "Student_database.h"



student database[50];

void main()
{
	while(1)
	{
		int num;
		printf("\n------------------\n");
		printf("Choose the task you want to perform:\n");
		printf("1. Add a student details manually.\n");
		printf("2. Add student details from text file.\n");
		printf("3. Find student details by roll number.\n");
		printf("4. Find student details by first name.\n");
		printf("5. Find student details by course ID.\n");
		printf("6. Find the total number of students.\n");
		printf("7. Delete student details by roll number.\n");
		printf("8. Update student details by roll number. \n");
		printf("9. Show all information.\n");
		printf("0. to exit.\n");
		printf("\nEnter your choice to perform the task: ");



		int h=1;


		fflush(stdout); fflush(stdin);
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			add_student_manually();
			break;

		case 2:
			add_student_file();
			break;

		case 3:
			find_rl();
			break;

		case 4:
			find_fn();
			break;

		case 5:
			find_c();
			break;

		case 6:
			tot_s();
			break;

		case 7:
			del_s();
			break;

		case 8:
			up_s();
			break;


		case 9:
			show_s();
			break;

		case 0:
			h=0;
			break;


		}


		if(h==0)
			break;



	}
}
