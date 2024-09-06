#include <stdio.h>

int write_input(char *buff)
{
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		buff[i++] = c;
	if (c == '\n')
		buff[i++] = '\n';
	buff[i] = '\0';
	return i;
}

void	reverse(char *str, int len)
{
	int i = 0;
	char c;
	len--;

	while (i < len)
	{
		c = str[i];
		str[i++] = str[len];
		str[len--] = c;
	}
}

int main()
{

	char line[1024];
	int len;

	while ((len = write_input(line)))
	{
		printf("Line: %s\n", line);
		reverse(line, len);
		printf("Reversed: %s\n", line);
	}
	
}
