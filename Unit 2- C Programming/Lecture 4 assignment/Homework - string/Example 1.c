#include<stdio.h>
#include<string.h>

int main()
{
	char arr[100], onechar;
	int sum=0;

	printf("enter a string: ");
	fflush(stdout);
	gets(arr);

	printf("enter a character to find frequency: \n");
	fflush(stdout);
	scanf("%c", &onechar);

	for(int i = 0; i<strlen(arr); i++)
	{
		if(arr[i]==onechar)
			sum+=1;
	}

	printf("frequency of %c = %d", onechar, sum);

	return 0;
}
