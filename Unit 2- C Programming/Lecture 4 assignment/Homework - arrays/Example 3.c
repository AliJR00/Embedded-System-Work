#include<stdio.h>

int main()
{
	int rows, cols;
	printf("enter rows and columns of matrix:");
	fflush(stdout);
	scanf("%d\n%d", &rows, &cols);

	float matrix[rows][cols], T[cols][rows];


	printf("enter the elements of matrix:\n");

	for (int i=0; i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			printf("enter elements a%d%d: ", i, j);
			fflush(stdout);
			scanf("%f", &matrix[i][j]);
		}

	}

	printf("\nentered matrix:\n");

	for (int i=0; i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			printf("%.2f\t", matrix[i][j]);
		}
	printf("\n");
	}

	printf("Transpose of Matrix:\n");

	for (int i=0; i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			T[j][i]=matrix[i][j];
		}

	}

	for (int i=0; i<cols;i++)
	{
		for (int j=0;j<rows;j++)
		{
			printf("%.2f\t", T[i][j]);
		}
	printf("\n");
	}


return 0;


	return 0;
}
