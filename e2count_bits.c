#include <stdio.h>

unsigned count_bits(unsigned x)
{
	unsigned bcount = 0;
	while (x != 0)
	{
		if (x & 1)
			bcount++;
		x >>= 1;
	}

	return bcount;
}

unsigned the_faster_count_bits(unsigned x)
{
	unsigned bcount = 0;
	while (x != 0)
	{
		bcount++;
		x &= (x - 1);
	}

	return bcount;
}

int main()
{
	printf("%u %u\n", count_bits(0x5E), the_faster_count_bits(0x5E));//5
	printf("%u %u\n", count_bits(0xff), the_faster_count_bits(0xff));//8
	printf("%u %u\n", count_bits(1), the_faster_count_bits(1));//1
	printf("%u %u\n", count_bits(7), the_faster_count_bits(7));//3
	printf("%u %u\n", count_bits(0), the_faster_count_bits(0));//0
}
