#include "Student_database.h"




student database[50];


int count = 0;

int add_student_manually()
{
	printf("\nAdd student info:\n");
	printf("Enter the roll number: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &(database[count].roll));

	for(int i=0; i<count; i++)
	{
		if(database[i].roll == database[count].roll)
		{
			printf("[ERROR] The student roll number already exists!\n");
			return 0;
		}
	}

	printf("Enter the first name: ");
	fflush(stdout); fflush(stdin);
	scanf("%s", (database[count].Fname));

	printf("Enter the last name: ");
	fflush(stdout); fflush(stdin);
	scanf("%s", (database[count].Lname));

	printf("Enter the GPA: ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &(database[count].gpa));



	for(int i=0; i<sizeof(database[count].Cid);i++)
	{
		database[count].Cid[i] = 0;
	}

	printf("Enter the number of subjects: ");
	fflush(stdout); fflush(stdin);
	int sub;
	scanf("%d", &sub);

	printf("\nEnter the course ID of each course:\n");
	fflush(stdout); fflush(stdin);
	for(int i=0; i<sub; i++)
	{
		printf("Course %d ID: ", i+1);
		fflush(stdout); fflush(stdin);
		scanf("%d", &(database[count].Cid[i]));

		for(int j=0; j<(sizeof(database->Cid)/4); j++)
		{
			if(i==j)
				continue;
			if(database[count].Cid[i] == database[count].Cid[j])
			{
				printf("Already used course ID.\n");
				i--;
				break;
			}
		}
	}
	count++;
	return 1;
}


int add_student_file()
{
	FILE *ptr;

	ptr = fopen("student.txt", "r");

	if(ptr == NULL) {
	  printf("[ERROR] Not able to open the file.\n");
	  fclose(ptr);
	  return 0;
	}


	while(!feof(ptr)){
		int v=0;
		fscanf(ptr,"%d" , &(database[count].roll));
		for(int i=0; i<count; i++)
			{
				if(database[i].roll == database[count].roll)
				{
					printf("[ERROR] The student roll number already exists! (roll number: %d)\n", database[count].roll);
					v=1;
				}
			}
		fscanf(ptr,"%s" , (database[count].Fname));
		fscanf(ptr,"%s" , (database[count].Lname));
		fscanf(ptr,"%f" , &(database[count].gpa));

		for(int i=0; i<sizeof(database[count].Cid)/4;i++)
			{
				database[count].Cid[i] = 0;
			}
		for(int i=0; i<5; i++)
			{

				fscanf(ptr,"%d" , &(database[count].Cid[i]));


			}

		if(v == 0)
			count++;
	}

	fclose(ptr);
	return 1;
}




void show_s()
{
	for(int i=0; i<count; i++)
	{
		printf("\nStudent first name: %s\n", database[i].Fname);
		printf("Student last name: %s\n", database[i].Lname);
		printf("Student roll number: %d\n", database[i].roll);
		printf("Student GPA: %.2f\n", database[i].gpa);
		for(int j=0; database[i].Cid[j] != 0 && j<sizeof(database[count].Cid)/4; j++)
		{
			printf("Course No. %d ID: %d\n",j+1, database[i].Cid[j]);
		}

	}

	printf("--------------------------\n");
	printf("[INFO] The total number of students: %d.\n", count);
	printf("[INFO] You can add up to %d students.\n", sizeof(database)/sizeof(student));
	printf("[INFO] You can add %d more students.", sizeof(database)/sizeof(student) - count);

}



void find_rl()
{
	int search;

	printf("Enter the roll number of the student: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &search);


	int i;
	for(i=0; i<count; i++)
	{
		if(search == database[i].roll)
		{
			printf("The student details are:\n");
			printf("\nStudent first name: %s\n", database[i].Fname);
			printf("Student last name: %s\n", database[i].Lname);
			printf("Student roll number: %d\n", database[i].roll);
			printf("Student GPA: %.2f\n", database[i].gpa);
			for(int j=0; database[i].Cid[j] != 0 && j<sizeof(database[count].Cid)/4; j++)
			{
				printf("Course No. %d ID: %d\n",j+1, database[i].Cid[j]);
			}
			break;
		}
	}
	if(i == count)
	{
		printf("The roll number doesn't exist.\n");
	}

}


void find_fn()
{
	char first[30];
	printf("Enter the first name of the student: ");
	fflush(stdin);  fflush(stdout);
	scanf("%s", first);

	int Nchar=0;
	for(int i=0; i<sizeof(first); i++)
	{
		if(first[i]==0)
			break;
		else Nchar++;
	}

	int arr[count], Narr=0;

	for(int j=0; j<count; j++)
	{
		int num=0;
		for(int i=0; i<Nchar; i++)
		{
			if(first[i] == database[j].Fname[i] || first[i]+32 == database[j].Fname[i] || first[i]-32 == database[j].Fname[i])
			{
				num++;
			}

		}
		if(num == Nchar)
		{
			arr[Narr] = j;
			Narr++;
		}
	}

	if(Narr != 0)
	{
	for(int i=0; i<Narr; i++)
	{
		printf("The student details are:\n");
		printf("\nStudent first name: %s\n", database[arr[i]].Fname);
		printf("Student last name: %s\n", database[arr[i]].Lname);
		printf("Student roll number: %d\n", database[arr[i]].roll);
		printf("Student GPA: %.2f\n", database[arr[i]].gpa);
		for(int j=0; database[arr[i]].Cid[j] != 0 && j<sizeof(database[count].Cid)/4; j++)
		{
			printf("Course No. %d ID: %d\n",j+1, database[arr[i]].Cid[j]);
		}
	}
	}
	else printf("[ERROR] First name %s not found. \n", first);

}


void find_c()
{
	int id;
	printf("Enter the course ID: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &id);


	int arr[count], Narr=0;
	for(int i=0; i<count; i++)
	{
		for(int j=0; j<(sizeof(database->Cid)/4); j++)
		{
			if(id == database[i].Cid[j])
			{
				arr[Narr] = i;
				Narr++;
			}
		}
	}

	for(int i=0; i<Narr; i++)
	{
		printf("\nThe student details are:\n");
		printf("\nStudent first name: %s\n", database[arr[i]].Fname);
		printf("Student last name: %s\n", database[arr[i]].Lname);
		printf("Student roll number: %d\n", database[arr[i]].roll);
		printf("Student GPA: %.2f\n", database[arr[i]].gpa);
	}

	printf("\n[INFO] Total number of students enrolled: %d", Narr);

}




void tot_s()
{
	printf("--------------------------\n");
	printf("[INFO] The total number of students: %d.\n", count);
	printf("[INFO] You can add up to %d students.\n", sizeof(database)/sizeof(student));
	printf("[INFO] You can add %d more students.", sizeof(database)/sizeof(student) - count);
}


int del_s()
{
	int id;
	printf("Enter the roll number which you want to delete: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &id);

	int i;
	for(i=0; i<count; i++)
	{
		if(id == database[i].roll)
		{
			break;
		}
	}

	if(i == count)
	{
		printf("[ERROR] This roll number doesn't exist.\n");
		return 0;
	}


	for(int j=i+1; j<(count); j++)
	{
		database[i] = database[j];
		i++;
	}

	database[i].roll = -1;
	printf("[INFO] The roll number is removed successfully.\n");
	count--;

	return 1;


}



int up_s()
{
	int id;
	printf("Enter the roll number to update the entry: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &id);

	int i;
	for(i=0; i<count; i++)
	{
		if(id == database[i].roll)
			break;
	}

	if(i == count)
	{
		printf("[ERROR] This roll number doesn't exist.\n");
		return 0;
	}

	int num;
	printf("1. first name\n");
	printf("2. last name\n");
	printf("3. roll number\n");
	printf("4. GPA\n");
	printf("5. courses\nEnter the category No.: ");

	fflush(stdout); fflush(stdin);
	scanf("%d", &num);

	int number;

	switch (num)
	{
	case 1:
		printf("Enter the new first name: ");
		fflush(stdout); fflush(stdin);
		scanf("%s", database[i].Fname);
		printf("[INFO] UPDATED SUCCESSFULLY!\n");
		break;

	case 2:
		printf("Enter the new last name: ");
		fflush(stdout); fflush(stdin);
		scanf("%s", database[i].Lname);
		printf("[INFO] UPDATED SUCCESSFULLY!\n");
		break;

	case 3:
		printf("Enter the new roll number: ");
		fflush(stdout); fflush(stdin);
		scanf("%d", &(database[i].roll));
		printf("[INFO] UPDATED SUCCESSFULLY!\n");
		break;

	case 4:
		printf("Enter the new GPA: ");
		fflush(stdout); fflush(stdin);
		scanf("%f", &(database[i].gpa));
		printf("[INFO] UPDATED SUCCESSFULLY!\n");
		break;

	case 5:
		printf("Enter the new number of courses: ");
		fflush(stdout); fflush(stdin);
		scanf("%d", &number);
		for(int k=0; k<number; k++)
		{
			printf("Course %d ID: ", k+1);
			fflush(stdout); fflush(stdin);
			scanf("%d", &(database[i].Cid[k]));
			for(int j=0; j<(sizeof(database->Cid)/4); j++)
			{
				if(k==j)
					continue;
				if(database[i].Cid[k] == database[i].Cid[j])
				{
					printf("Already used course ID.\n");
					k--;
					break;
				}
			}
		}
		printf("[INFO] UPDATED SUCCESSFULLY!\n");
		break;
	}

	return 1;

}





















