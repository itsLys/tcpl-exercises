#include <stdio.h>


// print n elements of an array, 10 per line, each col seperated by blank
void print_elements(int *arr, unsigned size, unsigned n)
{
	int i = 0;
	while (i < n && i < size)
	{
		printf("%6d%c", arr[i], ((i + 1) % 10 != 0) && (i + 1 != n) ? ' ' : '\n');
		i++;
	}
}

int main()
{
	int arr[100] = {1,3,4,5,2,6,222,5,123,1,
				3,4,5,2,6,222,5,123,321,0,
				312,55,11,32,1,5,3,4,321,0,
				3121,3,4,5,2,6,222,5,123,321,
				0,312,55,11,32,1,5,3,4,55,
				11,32,1,5,3,4};
	print_elements(arr, 100, 34);
}
