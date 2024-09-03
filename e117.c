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
int main()
{
	char line[1024];
	int len = 0;

	while ((len = write_input(line)))
	{
		if (len > 22)
			printf("%s", line);
	}
}
