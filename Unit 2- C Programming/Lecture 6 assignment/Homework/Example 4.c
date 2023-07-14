#include <stdio.h>

struct student
{
	char name[50];
	int roll;
	float marks;
};

struct student readdata(int numm);
void displaydata(struct student info, int num);


int main()
{

	struct student student[10];
	printf("Enter 0 in the name to stop inputting:\n");

	for(int i=0; i<10; i++)
	student[i]=readdata(i);

	for(int i=0; i<10; i++)
	displaydata(student[i], i+1);


}

struct student readdata(int numm)
{
	struct student info;
	printf("Enter information of student %d: \n", numm+1);
	printf("enter name: ");
	fflush(stdout);
	scanf("%s", &info.name);
	fflush(stdin);

	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d", &info.roll);
	fflush(stdin);


	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f", &info.marks);
	fflush(stdin);


	return info;
}

void displaydata(struct student info, int num)
{
	printf("Displaying information of student %d:\n", num);
	printf("name: %s\n", info.name);
	printf("Roll: %d\n", info.roll);
	printf("Marks: %.2f\n", info.marks);

}
