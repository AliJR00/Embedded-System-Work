#include<stdio.h>

int main()
{
	int elements, loc;
	float insert;
	printf("enter no of elements: ");
	fflush(stdout);
	scanf("%d", &elements);
	float arr[elements+1];



		for (int j=0;j<elements;j++)
		{
			printf("\nenter element no %d: ", (j+1));
			fflush(stdout);
			scanf("%f", &arr[j]);

		}


		printf("\nenter the element to be inserted: ");
		fflush(stdout);
		scanf("%f", &insert);

		printf("\nenter the location: ");
		fflush(stdout);
		scanf("%d", &loc);


		for(int i=(elements-1); i>=(loc-1); i--)
		{
			arr[i+1]=arr[i];
		}

		arr[loc-1]=insert;

		for(int i=0; i<=elements; i++)
		{
			printf("%.2f ", arr[i]);
		}


	return 0;
}
