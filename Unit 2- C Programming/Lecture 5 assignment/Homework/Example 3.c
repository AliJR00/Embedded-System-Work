#include <stdio.h>
#include <string.h>

void rev11(char sentence[]);

int main()
{
	char sen[100];

	printf("enter a sentence: ");
	fflush(stdout);
	fgets(sen, 100, stdin);

	rev11(sen);

}


void rev11(char sentence[])
{
	char c = sentence[0];

	if(c!=0)
	{
	rev11(sentence+1);
	printf("%c", c);
	}
}
