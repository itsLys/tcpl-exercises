#include <ctype.h>
#include <stdio.h>
#define MAX 1024


unsigned expand_notation(char *str, char first, char last)
{
	unsigned i = 0;
	if (first < last)
	{
		first++;
		while (first <= last)
			str[i++] = first++;
	}
	return i;
}

char *expand(const char *str, char *expanded)
{
	unsigned i = 0;
	unsigned j = 0;
	while (str[i])
	{
		while (str[i] && !isalpha(str[i]) && !isdigit(str[i]))
			expanded[j++] = str[i++];
		while (str[i] && str[i] != '-')
			expanded[j++] = str[i++];
		printf("i: %u, str[i]: %c\n", i, str[i]);

	}
	expanded[j] = '\0';
	return expanded;
}


int main()
{
	char str[MAX];
	printf("%s\n", expand("a-z", str));
	printf("%s\n", expand("y-z", str));
}


// a-a => a-a
// a--z => a--z
// a-z => abcdefghejklmnopqrstuvwxyz
// A-Z => ABCDEFGHEJKLMNOPQRSTUVWXYZ
// a-b-c => abc
// a-d => abcd
// a-eh-m => abcdehejklmnop
// a-eh-m => abcdehejklmnop
// 0-9 => 0123456789
// a-z0-9 => abcdefghejklmnopqrstuvwxyz0123456789
// -a-e => -abcdef
// -a-e- => -abcdef-

