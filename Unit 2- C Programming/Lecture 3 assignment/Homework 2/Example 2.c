#include<stdio.h>

int main()
{
	char var;

	printf("Enter an alphabet: ");
    fflush(stdout);
    scanf("%c", &var);

    if (var=='a' || var=='e'  || var=='i' || var=='u' || var=='o' || var=='A' || var=='E'  || var=='I' || var=='U' || var=='O')
    	printf("%c is a vowel", var);
    else printf("%c is consonant", var);

    return 0;
}
