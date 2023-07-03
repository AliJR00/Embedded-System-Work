#include<stdio.h>

int main()
{
	char var1;

	printf("Enter a character: ");
    fflush(stdout);
    scanf("%c", &var1);

    if ((var1>'a' && var1<'z') || (var1>'A' && var1<'Z') )
        printf("%c is an alphabet", var1);
    else printf("%c is not an alphabet", var1);

    return 0;
}
