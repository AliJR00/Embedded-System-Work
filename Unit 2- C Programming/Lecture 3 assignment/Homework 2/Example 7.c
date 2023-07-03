#include<stdio.h>

int main()
{
	int var1, sum=1;

	printf("Enter an integer: ");
    fflush(stdout);
    scanf("%d", &var1);

if(var1==0)
	sum=1;
else if(var1<0)
{
	sum=0;
	printf("Error! The number can't be negative");
}
	else
   for(int i=1; i<=var1 ; i++)
	   sum*=i;
if(sum!=0)
printf("Factorial = %d", sum);

    return 0;
}
