#include <stdio.h>

struct Sdistance
{
	float feet;
	float inches;
};

struct Sdistance readdata(int num);
void displaysum(struct Sdistance d1, struct Sdistance d2);


int main()
{
	struct Sdistance d1, d2;

	d1= readdata(1);
	d2= readdata(2);

	displaysum(d1,d2);

}


struct Sdistance readdata(int num)
{
	struct Sdistance distance;
	printf("Enter information for distance %d:\n", num);

	printf("Enter Feet:");
	fflush(stdout);
	scanf("%f", &distance.feet);

	printf("Enter inch:");
	fflush(stdout);
	scanf("%f", &distance.inches);

	return distance;
}

void displaysum(struct Sdistance d1, struct Sdistance d2)
{
	struct Sdistance sum;

	sum.feet= d1.feet+d2.feet;
	sum.inches = d1.inches+d2.inches;
	if(sum.inches>=12)
	{
		float remain;

		sum.feet = sum.feet + (int) (sum.inches/12)*1;
		sum.inches = sum.inches - (int) (sum.inches/12)*12;
		remain = ((sum.feet- (int) sum.feet)/1)*12;
		sum.inches += remain;
	}

	printf("sum of distances = %d' %.2f\"", (int) sum.feet, sum.inches);
}

