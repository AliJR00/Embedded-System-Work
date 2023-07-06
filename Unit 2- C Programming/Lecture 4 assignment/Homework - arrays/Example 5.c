#include<stdio.h>

int main()
{
	int elements;
	float search;
	printf("enter no of elements: ");
	fflush(stdout);
	scanf("%d", &elements);
	float arr[elements];



		for (int j=0;j<elements;j++)
		{
			printf("\nenter element no %d: ", (j+1));
			fflush(stdout);
			scanf("%f", &arr[j]);

		}


		printf("\nenter the element to be searched: ");
		fflush(stdout);
		scanf("%f", &search);


		int i;
		for(i=0; i<elements; i++)
		{
			if(arr[i] == search)
			{
				printf("Number is found at the location: %d", i+1);
				break;
			}

			else if(i == elements-1)
				printf("Number Not Found!");
		}




	return 0;
}
