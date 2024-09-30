#include <ctype.h>
#include <stdio.h>
#define BRO 31

int count_largest(int *arr)
{
	int largest;
	int i;

	largest = arr[0];
	i = 1;
	while (i < 50)
	{
		if (arr[i] > largest)
			largest = arr[i];
		i++;
	}
	return largest;
}
void write_input(char *buff)
{
	int c;
	int i = 0;
	while ((c = getchar()) != EOF)
	{
		buff[i] = c;
		i++;
	}
	buff[i] = '\0';
}

int count_lengths(char * buff, int *len_arr)
{
	int i = 0;
	int length = 0;
	int longest_length = 0;
	while (buff[i])
	{
		while (buff[i] && isspace(buff[i]))
			i++;
		while (buff[i] && !isspace(buff[i]))
		{
			length++;
			i++;
		}
		len_arr[length]++;
		if (longest_length < length)
			longest_length = length;
		length = 0;
	}
	return longest_length;
}

void print_histogram(int *len_arr)
{
	int i = 1;
	printf("\nLenghts | Count\n");
	printf("------- | -----");
	int largest = count_largest(len_arr);
	while (largest > 5)
	{
		printf("-");
		largest--;
	}
	printf("\n");
	while (i < 50)
	{
		if (len_arr[i])
		{
			printf("%7d | ", i);
			while (len_arr[i] > 0)
			{
				printf("*");
				len_arr[i]--;
			}
			printf("\n");
		}
		i++;
	}
}

int count_lens_num(int *lens_arr)
{
	int i, lens_num;

	lens_num = 0;
	i = 1;
	while (i < 50)
		if (lens_arr[i++])
			lens_num++;
	return lens_num;
}


void print_upper(int lens_num, int largest_len, int *lens_arr)
{
	int i;

	i = 1;
	printf("\n");
	while (largest_len > 0)
	{
		if (largest_len == 1)
			printf("Count   | ");
		else
			printf("        | ");
		i = 1;
		while (i < 50)
		{
			if (lens_arr[i])
			{
				if(lens_arr[i] >= largest_len)
					printf(" *");
				else
					printf("  ");
				printf(" ");
			}
			i++;
		}
		printf("\n");
		largest_len--;
	}
}

void print_bot(int lens_num, int *lens_arr)
{
	int i = 1;
	printf("------- |  ");
	while (lens_num > 1)
	{
		printf("---");
		lens_num--;
	}
	printf("-");
	printf("\n");
	printf("Lenghts |  ");
	while (i < 50)
	{
		if (lens_arr[i])
			printf("%.2d ", i);
		i++;
	}
}

void print_histo_hori(int longest_len, int *lens_arr)
{

	int lens_num, largest_len;

	lens_num = count_lens_num(lens_arr);
	largest_len = count_largest(lens_arr);
	print_upper(lens_num, largest_len, lens_arr);
	print_bot(lens_num, lens_arr);
}

int main()
{
	char buff[1024];
	int len_arr[50] = {0};
	int longest_length;

	write_input(buff);
	longest_length = count_lengths(buff, len_arr);
	print_histo_hori(longest_length, len_arr);
	printf("\n");
	print_histogram(len_arr);
}
