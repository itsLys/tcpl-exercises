#include <stdio.h>
#include <string.h>

unsigned int writeline(char *buff)
{
	int i = 0;
	char c;
	while ((c = getchar()) != EOF && c != '\n')
		buff[i++] = c;
	buff[i] = '\0';
	return i;
}
int main()
{
	unsigned int len, longest, c;
	char line[1024];
	char longest_line[1024];
	longest = 0;

	while ((len = writeline(line)))
	{
		if (len > longest)
		{
			longest = len;
			strcpy(longest_line, line);
		}
	}
	if (longest)
		printf("\nLongest: %s \nLength: %d", longest_line, longest);
}
