#include <stdio.h>
#define INTBITS 32U

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
	unsigned x_mask = ~((~(0U) << (INTBITS - n)) >> (INTBITS - n - p + 1));
	printf("%o\n", x_mask);
	y = (y << (INTBITS - n)) >> (INTBITS - (n + p - 1));
	return (x & x_mask) | y;
}

int main()
{
	printf("%o\n", setbits(0227, 4, 2, 071));

}

