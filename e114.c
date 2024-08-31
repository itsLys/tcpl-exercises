#include <ctype.h>
#include <stdio.h>

int count_largest(int *arr)
{
	int largest;
	int i;

	largest = arr[0];
	i = 1;
	while (i < 255)
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

void count_freq(char *buff, int *freq_arr)
{
	int i = 0;
	int length = 0;
	int longest_length = 0;
	while (buff[i])
	{
		if (isprint(buff[i]))
			freq_arr[buff[i]]++;
		i++;
	}
}

void print_histogram(int *freq_arr)
{
	int i = 1;
	printf("\nCharacter | Frequency\n");
	printf("--------- | ---------");
	int largest = count_largest(freq_arr);
	while (largest > 9)
	{
		printf("-");
		largest--;
	}
	printf("\n");
	while (i < 255)
	{
		if (freq_arr[i])
		{
			printf("      '%c' | ", i);
			while (freq_arr[i] > 0)
			{
				printf("*");
				freq_arr[i]--;
			}
			printf("\n");
		}
		i++;
	}
}

int count_char_num(int *freq_arr)
{
	int i, char_num;

	char_num = 0;
	i = 1;
	while (i < 255)
		if (freq_arr[i++])
			char_num++;
	return char_num;
}


void print_upper(int largest_char, int *freq_arr)
{
	int i;

	i = 1;
	printf("\n");
	while (largest_char > 0)
	{
		if (largest_char == 1)
			printf("Frequency | ");
		else
			printf("          | ");
		i = 1;
		while (i < 255)
		{
			if (freq_arr[i])
			{
				if(freq_arr[i] >= largest_char)
					printf("*");
				else
					printf(" ");
				printf(" ");
			}
			i++;
		}
		printf("\n");
		largest_char--;
	}
}

void print_bot(int char_num, int *freq_arr)
{
	int i = 1;
	printf("--------- | ");
	while (char_num > 1)
	{
		printf("--");
		char_num--;
	}
	printf("-");
	printf("\n");
	printf("Character | ");
	while (i < 255)
	{
		if (freq_arr[i])
			printf("%c ", i);
		i++;
	}
}

void print_histo_hori(int *freq_arr)
{

	int char_num, largest_char;

	char_num = count_char_num(freq_arr);
	largest_char = count_largest(freq_arr);
	print_upper(largest_char, freq_arr);
	print_bot(char_num, freq_arr);
}

int main()
{
	char buff[1024];
	int freq_arr[255] = {0};
	int longest_length;

	write_input(buff);
	count_freq(buff, freq_arr);
	print_histo_hori(freq_arr);
	printf("\n");
	print_histogram(freq_arr);
}
