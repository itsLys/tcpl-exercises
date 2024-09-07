#include <stdio.h>

/* 

n = 30;
"Lorem ipsum dolor sit amet, consectetur adipiscing"
=> "Lorem ipsum dolor sit amet,
consectetur adipiscing"   


*/



int write_line(char *buff)
{
	int i, c;
	i = 0;
	int last_space;
	last_space = -1;
	int n = 30;

	while ((c = getchar()) != EOF && c != '\n')
	{
		if (c == ' ')
			last_space = i;
		if (n == 0)
		{
			if (last_space == -1)
			{
				buff[i++] = '-';
				buff[i++] = '\n';
				buff[i++] = '-';
			} else 
				buff[last_space] = '\n';
			n = 30;
			last_space = -1;
		}
		buff[i] = c;
		n--;
		i++;
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
		printf("\n%s\n", buff);
}
