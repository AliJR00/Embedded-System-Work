#include "platformtypes.h"

void swap(int* a, int* b);
void print(int* a, int* b, int c);

int main()
{
	int aa = 5, bb = 10;
	int* ptra = &aa, *ptrb = &bb;


	print(ptra, ptrb, 1);
	swap(ptra, ptrb);
	print(ptra, ptrb, 0);


}
