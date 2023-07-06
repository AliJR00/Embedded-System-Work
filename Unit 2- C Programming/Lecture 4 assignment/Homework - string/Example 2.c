#include<stdio.h>
#include<string.h>

int main()
{
	char arr[100];
	int sum=0;

	printf("enter a string: ");
	fflush(stdout);
	gets(arr);

	for(int i = 0; i<100; i++)
	{
		if(arr[i]==0)
			break;
		else sum+=1;
	}

	printf("length of string = %d", sum);

	return 0;
}
