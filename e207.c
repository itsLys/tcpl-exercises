#include "stdio.h"
#define BITS 32U

unsigned invert(unsigned x, unsigned p, unsigned n)
{
	return x ^ (((~0U) << (BITS - n)) >> (BITS - p - 1U));
}

int main()
{
	printf("%o\n", invert(036, 3, 2)); //
	printf("%o\n", invert(036, 6, 3)); //0xee
}


// x == 0001 1110 (0036)
// n == 3
// p == 6
// result == 0110 1110 (0156)
//
// y == x
// y == 1001 1110
// << bits - p - 1
// 0011 1100
// >> bits (p - n + 1) - 1
// 0000 0001
// << bits - (p - n + 1) - 1
// ~0001 0000
// 1110 1111
