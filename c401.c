#include <stdbool.h>
#include <stdio.h>
#define MAX 1024

bool write_line(char *buff)
{
	int i = 0;
	int c;

	while ((c = getchar()) != EOF && c != '\n')
		buff[i++] = c;
	buff[i++] = '\n';
	buff[i] = '\0';
	if (c == EOF)
		return 0;
	return 1;
}

bool find_patt(char *str, char *patt)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if (str[i] == patt[0])
		{
			j = 0;
			while (str[i + j] == patt[j])
				j++;
			if (patt[j] == '\0')
				return true;
		}
		i++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int i = 0;
	char str[MAX];
	bool endprogram = false;

	while (!endprogram)
	{
		if (!write_line(str))
		{
			printf("\n");
			endprogram = true;
		}
		if (find_patt(str, av[1]))
			printf("found: %s", str);
	}

}
