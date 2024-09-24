#include <stdio.h>
#define BITS 32


unsigned rightrot(unsigned x, unsigned n)
{
	return (((~0) & x) << (BITS - n)) | (((~0) & x) >> n);
}

int main()
{
	printf("%x\n", rightrot(0xfffffffa, 4));
}
