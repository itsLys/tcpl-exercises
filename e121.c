
// a...a => a...a
// a....a => a>a
// a.....a => a>.a
// a......a => a>..a
// a.......a => a>...a
// a........a => a>>a

#include <stdio.h>

int write_line(char *buff)
{
	int i, c;
	int space;
	i = 0;
	space = 0;

	// code..
	if (c == '\n')
		buff[i++] = '\n';
	buff[i] = '\0';
	return i;
}

int main()
{
	char buff[1024];

	while (write_line(buff))
		printf("%s\n", buff);
}
