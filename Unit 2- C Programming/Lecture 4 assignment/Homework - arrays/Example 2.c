#include <stdio.h>

int main()
{
	int var;
	float average, sum=0;
	printf("enter the number of data: ");
	fflush(stdout);
	scanf("%d", &var);

	float arr[var];

	for (int i=0; i < var; i++)
	{
		printf("%d. enter number: ", i+1);
		fflush(stdout);
		scanf("%f", &arr[i]);
	}

	for (int i=0; i < var; i++)    //array is not needed
		{
		sum+= arr[i];
		}

	average = sum / var;
	printf("Average: %.2f", average);
}
