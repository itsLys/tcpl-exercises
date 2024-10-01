#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 1024


unsigned expand_notation(char *str, char first, char last)
{
	unsigned i = 0;
	first++;
	while (first <= last)
		str[i++] = first++;
	return i;
}

bool is_match(char first, char last)
{
	if (islower(first) && islower(last))
		return 1;
	if (isdigit(first) && isdigit(last))
		return 1;
	if (isupper(first) && isupper(last))
		return 1;
	return 0;
}

char *expand(const char *str, char *expanded)
{
	unsigned i = 0;
	unsigned j = 0;
	char first;

	while (str[i])
	{
		while (str[i] && !isalpha(str[i]) && !isdigit(str[i]))
			expanded[j++] = str[i++];
		while (str[i] && str[i] != '-')
		{
			first = str[i];
			expanded[j++] = str[i++];
		}
		while (str[i] && str[i] == '-')
		{
			i++;
			if (str[i] && str[i + 1] && str[i + 2] && str[i + 1] == '-')
			{
				i++;
				continue ;
			}
			if (str[i] && first < str[i] && is_match(first, str[i]))
				j += expand_notation(expanded + j, first, str[i]);
			else
			{
				expanded[j++] = '-';
				if (str[i])
					expanded[j++] = str[i];
			}
		}
		if (str[i])
			i++;
	}
	expanded[j] = '\0';
	return expanded;
}

void test_expand(char *notation, char *exp)
{
	static unsigned case_n;
	char str[MAX];
	printf("\n-------- case no: %u ---------\n", case_n++);
	printf("str: %s\n", notation);
	printf("expected: %s\n", exp);
	printf("expanded: %s\n", expand(notation, str));
	assert(strcmp(exp, str) == 0);

}

int main()
{
	test_expand("a-z", "abcdefghijklmnopqrstuvwxyz");

	test_expand("a-z", "abcdefghijklmnopqrstuvwxyz");
	test_expand("x-z", "xyz");
	test_expand("0-9", "0123456789");
	test_expand("2-5", "2345");
	test_expand("A-Z", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	test_expand("B-X", "BCDEFGHIJKLMNOPQRSTUVWX");

	// Notations inside a phrase
	test_expand("Hello-t", "Hellopqrst");
	test_expand("world", "world");

	// Chained notations inside a phrase
	test_expand("a-d-h", "abcdefgh");
	test_expand("a-zA-Z0-9", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

	// Wrong notations
	test_expand("a-a", "a-a");
	test_expand("z-a", "z-a");
	test_expand("a-A", "a-A");

	// Leading and trailing -
	test_expand("-a-f", "-abcdef");
	test_expand("-a-f-", "-abcdef-");

	// Normal text without notation
	test_expand("Just text", "Just text");

	// Empty strings
	test_expand("", "");

	// Uncompleted notation
	test_expand("a-", "a-");

	// Additional tests
	test_expand("1-3 and a-f", "123 and abcdef");
	test_expand("M-P-Q-R", "MNOPQR");
	test_expand("x-y-z", "xyz");
	test_expand("-y-z-", "-yz-");
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

