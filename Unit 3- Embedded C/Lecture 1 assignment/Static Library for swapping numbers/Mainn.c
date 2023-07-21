#include "platformtypes.h"

void swap(int* a, int* b);
void print(int* a, int* b);

int main()
{
	int aa = 5, bb = 10;
	int* ptra = &aa, *ptrb = &bb;


	print(ptra, ptrb);
	swap(ptra, ptrb);
	print(ptra, ptrb);


}
