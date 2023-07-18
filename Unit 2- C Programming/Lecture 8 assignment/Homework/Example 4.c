#include <stdio.h>


struct Semployee
{
	char name[50];
	int ID;
};


int main()
{
	struct Semployee emp1 = {"asfasf", 5555}, emp2 = {"sfcscscssc", 44444}, emp3 = {"ghghghgh", 3333333};
	struct Semployee (*arr[]) = {&emp1, &emp2, &emp3};
	struct Semployee (*(*Parr)[3]) = &arr;



	printf("Employee name: %s\n", (*(*Parr+1))->name);
	printf("Employee ID: %d", (*(*Parr+1))->ID);



}
