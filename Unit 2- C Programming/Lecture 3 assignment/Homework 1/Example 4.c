#include<stdio.h>

void main()
{
	float input1, input2;

	printf("Enter two numbers: ");
    fflush(stdout);

    scanf("%f\n%f", &input1,&input2);

	printf("Product: %f", input1*input2);


}
