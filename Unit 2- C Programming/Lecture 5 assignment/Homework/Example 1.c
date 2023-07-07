#include<stdio.h>
int primenum(int);


int main()
{
	int first, second;

	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%d\n%d", &first, &second);

	printf("Prime numbers between %d and %d are:\n", first, second);

	for(int i=first; i<=second; i++)
	{
		int prime;
		prime = primenum(i);
		if(prime==1)
		printf("%d ", i);
	}

	return 0;
}


int primenum(int a)
{
	int count=0;
	for(int i=a; i>1; i--)
	{
		if(a%i==0)
			count+=1;
	}
	return count;
}
