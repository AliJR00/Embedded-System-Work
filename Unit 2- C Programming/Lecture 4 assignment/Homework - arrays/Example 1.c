#include<stdio.h>

int main()
{
	float matrix1[2][2], matrix2[2][2];
	printf("enter the elements of matrix 1\n");

	for (int i=0; i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("enter a%d%d: ", i, j);
			fflush(stdout);
			scanf("%f", &matrix1[i][j]);
		}

	}


	printf("enter the elements of matrix 2\n");

	for (int i=0; i<2;i++)
			{
				for (int j=0;j<2;j++)
				{
					printf("enter b%d%d: ", i, j);
					fflush(stdout);
					scanf("%f", &matrix2[i][j]);
				}

	}

   printf("Sum Of Matrix:\n");

	for (int i=0; i<2;i++)
			{
				for (int j=0;j<2;j++)
				{
					float sum = matrix1[i][j]+matrix2[i][j];
					printf("%.2f", sum);
					printf("\t");

				}
	printf("\n");
	}


	return 0;
}
