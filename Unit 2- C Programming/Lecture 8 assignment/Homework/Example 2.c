#include <stdio.h>


int main()
{
	char arr[27];
	char* Parr;
	Parr = arr;

	printf("The alphabets are:\n");
	for(int i=0; i<26; i++)
	{
		*Parr = i + 'A';
		Parr++;
	}

	Parr = arr;

	for(int i=0; i<26; i++)
	{
		printf("%c\t", *Parr);
		Parr++;
		if(i==9 || i==19)
			printf("\n");
	}



}
