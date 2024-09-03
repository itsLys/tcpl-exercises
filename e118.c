#include <ctype.h>
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

void remove_trailing(char *buff)
{
	int i, j;
	i = 0;
	while (buff[i])
	{
		while (buff[i] && !isspace(buff[i]))
			i++;
		j = i;
		while (buff[i] && isspace(buff[i]))
			i++;
		if (buff[i] == '\0')
		{
			buff[j] = '\0';
			return ;
		}
	}
}
int main()
{
	char line[1024];

	while (write_input(line))
	{
		printf("Trailing: %s;\n", line);
		remove_trailing(line);
		printf("Removed: %s;\n", line);
	}

}


		
