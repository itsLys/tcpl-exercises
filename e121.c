
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

	while ((c = getchar()) != EOF && c != '\n')
	{
		if (c == '.')
		{
			space++;
			while ((c = getchar()) == '.')
				space++;
			while (space > 0)
			{
				if (space >= 4)
				{
					buff[i] = '>';
					space -= 4;
				}
				else
			{
					buff[i] = '.';
					space--;
				}
				i++;
			}
			if (c == '\n')
				break;
		}
		buff[i++] = c;
	}

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
