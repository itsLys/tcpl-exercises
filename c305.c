#include <assert.h>
#include <stdio.h>
#include <string.h>
#define MAX 1024

// converts white space into its correspondent escape sequnce
char *escape(const char *str, char *esc)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		switch (str[i])
		{
			case '\n':
				esc[j++] = '\\';
				esc[j] = 'n';
				break;
			case '\t':
				esc[j++] = '\\';
				esc[j] = 't';
				break;
			default:
				esc[j] = str[i];
				break;
		}
		i++;
		j++;
	}
	esc[j] = '\0';
	return esc;
}

char *unescape(const char *str, char *unesc)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		switch (str[i]) {
			case '\\':
				switch (str[i + 1]) {
					case 'n': 
						unesc[j] = '\n';
						i++;
						break;
					case 't':
						unesc[j] = '\t';
						i++;
						break;
				}
				break;
			default: 
				unesc[j] = str[i];
		}
		i++;
		j++;
	}
	unesc[j] = '\0';
	return unesc;
}

void test_esc(const char *str)
{
	static unsigned case_n;
	char esc[MAX];
	char unesc[MAX];
	printf("\n----------	case no: %d	---------- \n", case_n++);
	printf("str:\t\t\"%s\" \n", str);
	printf("escaped:\t\"%s\" \n", escape(str, esc));
	printf("unescaped:\t\"%s\" \n", unescape(esc, unesc));
	assert(strcmp(str, unesc) == 0);
}

void test_unesc(const char *str, const char* exp)
{
	static unsigned case_n;
	char unesc[MAX];
	printf("\n----------	unesc case no: %d	---------- \n", case_n++);
	printf("str:\t\t\"%s\" \n", str);
	printf("expected :\t\"%s\" \n", exp);
	printf("unescaped:\t\"%s\" \n", unescape(str, unesc));
	assert(strcmp(exp, unesc) == 0);
}



int main()
{
	// test_esc("Hello");
	// test_esc("\tHello");
	// test_esc("\nHello");
	// test_esc("\n\tHello");
	// test_esc("\t\nHello");
	// test_esc("\t\tHello");
	// test_esc("\n\nHello");
	// test_esc("Hello\t");
	// test_esc("Hello\n");
	// test_esc("Hello\t\n");
	// test_esc("Hello\t\t");
	// test_esc("Hello\n\n");
	// test_esc("Hel\nlo");
	// test_esc("Hel\tlo");
	// test_esc("Hel\t\nlo");
	// test_esc("Hel\n\tlo");
	// test_esc("\rHello");
	// test_esc("\t");
	// test_esc("\n");
	// test_esc("\n\t");
	// test_esc("\t\n");
	// test_esc("\t\t");
	// test_esc("\n\n");
	// test_esc("");
	// test_esc(" \t");


	test_unesc("Hello", "Hello");
	test_unesc("\\tHello", "\tHello");
	test_unesc("\\nHello", "\nHello");
	test_unesc("\\n\\tHello", "\n\tHello");
	test_unesc("\\t\\nHello", "\t\nHello");
	test_unesc("\\t\\tHello", "\t\tHello");
	test_unesc("\\n\\nHello", "\n\nHello");
	test_unesc("Hello\\t", "Hello\t");
	test_unesc("Hello\\n", "Hello\n");
	test_unesc("Hello\\t\\n", "Hello\t\n");
	test_unesc("Hello\\t\\t", "Hello\t\t");
	test_unesc("Hello\\n\\n", "Hello\n\n");
	test_unesc("Hel\\nlo", "Hel\nlo");
	test_unesc("Hel\\tlo", "Hel\tlo");
	test_unesc("Hel\\t\\nlo", "Hel\t\nlo");
	test_unesc("Hel\\n\\tlo", "Hel\n\tlo");
	test_unesc("\\t", "\t");
	test_unesc("\\n", "\n");
	test_unesc("\\n\\t", "\n\t");
	test_unesc("\\t\\n", "\t\n");
	test_unesc("\\t\\t", "\t\t");
	test_unesc("\\n\\n", "\n\n");
	test_unesc("", "");
	test_unesc(" \\t", " \t");
}
