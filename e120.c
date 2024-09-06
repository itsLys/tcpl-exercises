#include <stdio.h>

int	write_input(char *buff)
{
	int c, i;
	int tabstop = 4;
	i = 0;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (c == '\t')
		{
			while (tabstop > 0)
			{
				buff[i++] = ' ';
				tabstop--;
			}
			tabstop = 4;
		} else
		{
			buff[i++] = c;
			tabstop--;
		}
		if (tabstop == 0)
				tabstop = 4;
	}
	if (c == '\n')
		buff[i++] = '\n';
	buff[i] = '\0';
	return i;

}

int main()
{
	char buff[1024];

	while (write_input(buff))
		printf("\n%s\n", buff);

}

// hello		hello
// hello........hello
// h		h
// h........h
// he		h
// he.......h
// hell		h
