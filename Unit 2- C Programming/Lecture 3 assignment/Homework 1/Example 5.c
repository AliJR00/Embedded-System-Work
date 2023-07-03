#include<stdio.h>

int main()
{
	char input1;

	printf("Enter a character: ");
    fflush(stdout);

    scanf("%c", &input1);

	printf("ASCII value of %c = %d ", input1, input1);

    return 0;
}
