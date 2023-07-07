#include <stdio.h>
#include <string.h>

float power(float a, int b);

int main()
{
	float num;
	int pow;

	printf("enter base number: ");
	fflush(stdout);
	scanf("%f", &num);

	printf("enter power number: ");
	fflush(stdout);
	scanf("%d", &pow);

	printf("(%.2f)^%d = %.2f", num, pow, power(num, pow));


}


float power(float a, int b)
{
	float res;

	if(b!=0)
	res=a*power(a,b-1);
	else return 1;
	return res;

}
