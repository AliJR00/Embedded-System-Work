#include <stdio.h>


int main()
{
	char arr[50];
	char revarr[50];
	char* Parr;
	Parr = arr;
	char* rev;
	rev = revarr;

	printf("Input a string:\n");
	fflush(stdout);
	fgets(arr, 50, stdin);

	int len=0;
	while(*Parr!=0)
	{
		Parr++;
		len++;
	}

	Parr--;
	for(int i=0; i<len; i++)
	{
		*rev = *Parr;
		Parr--;
		rev++;

	}
	*rev=0;

	rev = revarr;

	printf("Reverse of the string is: %s", rev);



}
