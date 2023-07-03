#include<stdio.h>

void main()
{
	int input1, input2;

	printf("Enter two integers: ");
    fflush(stdout);

    scanf("%d\n%d", &input1,&input2);

	printf("Sum: %d", input1+input2);


}
