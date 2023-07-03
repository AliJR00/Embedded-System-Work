#include<stdio.h>

int main()
{
	int var1, sum=0;

	printf("Enter an integer: ");
    fflush(stdout);
    scanf("%d", &var1);

   for(int i=1; i<=var1 ; i++)
	   sum+=i;
printf("Sum = %d", sum);

    return 0;
}
