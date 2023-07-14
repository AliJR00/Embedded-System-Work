#include <stdio.h>

struct student
{
	char name[50];
	int roll;
	float marks;
};

struct student readdata(char name[]);
void displaydata(struct student info);


int main()
{
	struct student student_1;

	student_1=readdata("student 1");

	displaydata(student_1);


}

struct student readdata(char name[])
{
	struct student info;
	printf("Enter information of %s: \n", name);
	printf("enter name: ");
	fflush(stdout);
	fgets(info.name, 50, stdin);

	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d", &info.roll);

	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f", &info.marks);

	return info;
}

void displaydata(struct student info)
{
	printf("Displaying information:\n");
	printf("name: %s", info.name);
	printf("Roll: %d\n", info.roll);
	printf("Marks: %.2f\n", info.marks);

}
