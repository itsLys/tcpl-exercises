#include <stdio.h>

unsigned getbits(int x, unsigned p, unsigned n)
{
	return (x >> (p-n+1)) & ~(~0 << n);
}

int main()
{
	printf("%u", getbits(027, 5, 3));
}

