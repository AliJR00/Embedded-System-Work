#include<stdio.h>

int main()
{
	float a, b;

	printf("Enter value of a: ");
    fflush(stdout);
    scanf("%f", &a);

    printf("Enter value of b: ");
        fflush(stdout);
        scanf("%f", &b);

        a=b*a;
        b=a/b;
		a=a/b;


	printf("After swapping, value of a = %f\n", a);
	printf("After swapping, value of b = %f", b);



    return 0;
}
