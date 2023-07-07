#include <stdio.h>

int fact(int);


int main()
{
	int num, res;

	printf("enter a positive integer: ");
	fflush(stdout);
	scanf("%d", &num);

	res=fact(num);

	if(num<0)
		printf("Wrong input");
	else printf("Factorial of %d is %d", num, res);



}


int fact(int a)
{
	int res=1;
	if(a>1)
	{
		res=a*fact(a-1);
	}
	return res;
}
