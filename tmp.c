#include <stdio.h>
#include <limits.h>


int main()
{
	int i = 0xf0ffffff;
	i = i << 4;
	printf("%d", i >> 4);

}
