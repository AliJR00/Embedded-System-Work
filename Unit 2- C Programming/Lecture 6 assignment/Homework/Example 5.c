#include <stdio.h>
#define PI 3.14159
#define CIRCLEAREA(r) (PI*r*r)

int main()
{
	int num;
	float area;

	printf("enter the radius: ");
	fflush(stdout);
	scanf("%d", &num);


	area = CIRCLEAREA(num);
	printf("Area = %.2f", area);


}
