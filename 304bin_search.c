#include <stdio.h>
unsigned search_arr(int x, int *arr, unsigned size)
{
	int low = 0;
	int high = size - 1;
	int i;
	while (low <= high)
	{
		i = (high + low) / 2;
		if (arr[i] > x)
			high = i;
		else if (arr[i] < x)
			low = i + 1;
		else
			return i;
	}
	return -1;
}

int main()
{

	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d\n", search_arr(6, arr, 10));
	printf("%d\n", search_arr(1, arr, 10));
	printf("%d\n", search_arr(0, arr, 10));
	printf("%d\n", search_arr(2, arr, 10));
	printf("%d\n", search_arr(7, arr, 10));
	printf("%d\n", search_arr(10, arr, 10));//-1
}
