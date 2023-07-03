#include<stdio.h>

int main()
{
	char op;
	float var1, var2, sum=0;

	printf("Enter operator either +, -, *, / : ");
    fflush(stdout);
    scanf("%c", &op);

    printf("Enter two operands: ");
        fflush(stdout);
        scanf("%f\n%f", &var1, &var2);

        switch(op)
        {
        case('+'):
        		sum=var1+var2;
        break;
        case('-'):
                		sum=var1-var2;
                break;
        case('*'):
                		sum=var1*var2;
                break;
        case('/'):
                		sum=var1/var2;
                break;
        default:
        	printf("You entered wrong operand.");
        	break;
        }

        printf("%.2f %c %.2f = %.2f", var1, op, var2, sum);

    return 0;
}
