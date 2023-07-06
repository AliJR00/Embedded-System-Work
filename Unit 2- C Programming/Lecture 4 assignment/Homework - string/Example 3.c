#include<stdio.h>

int main()
{
	char arr[100], rev[100];
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

	for(int i=0; i<100; i++)
	{
		if(arr[i]==0)
		{
			rev[i]=0;
			break;
		}
		else
			{
			rev[i]=arr[sum-1];
			sum--;
			}
	}

	printf("Reverse string is: %s", rev);



	return 0;
}
