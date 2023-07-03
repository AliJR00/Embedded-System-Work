#include<stdio.h>

int main()
{
	float var1, var2, var3, max;

	printf("Enter three numbers: ");
    fflush(stdout);
    scanf("%f\n%f\n%f", &var1, &var2, &var3);

    if (var1>var2 && var1>var3)
        max=var1;
    else if (var2>var1 && var2>var3)
    	max=var2;
    else max = var3;

    printf("Largest number = %f", max);


    return 0;
}
