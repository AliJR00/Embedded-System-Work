#include <stdio.h>

struct Scomplex
{
	float real;
	float comp;
};

struct Scomplex readdata(int num);
void displaycomplex(struct Scomplex n1, struct Scomplex n2);

int main()
{
	struct Scomplex num1, num2;

	num1= readdata(1);
	num2= readdata(2);

	displaycomplex(num1, num2);

}

struct Scomplex readdata(int num)
{
	struct Scomplex number;
	printf("\nfor complex number (%d)\n", num);
	printf("enter real and imaginary respectively:");
	fflush(stdout);
	scanf("%f\n%f", &number.real, &number.comp);
	return number;
}

void displaycomplex(struct Scomplex n1, struct Scomplex n2)
{
	struct Scomplex sum;
	char op;
	sum.real = n1.real + n2.real;
	sum.comp = n1.comp + n2.comp;
	op= sum.comp>=0 ? '+': '-', sum.comp*=-1;
	printf("Sum = %.2f %c %.2fi", sum.real, op, sum.comp);
}
