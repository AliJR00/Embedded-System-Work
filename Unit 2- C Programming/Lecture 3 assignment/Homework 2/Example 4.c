#include<stdio.h>

int main()
{
	float var1;

	printf("Enter a number: ");
    fflush(stdout);
    scanf("%f", &var1);

    if (var1>0)
        printf("%.2f is positive", var1);
    else printf("%.2f is negative", var1);

    return 0;
}
