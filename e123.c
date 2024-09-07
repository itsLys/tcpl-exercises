/*

^^ Remove me
^^ and me ^^ and me
^^ (and me)
^^ "and me"
^^ 'and me'
^& and me &^
^& don't
	forget
	me &^
^& 
	don't
	forget
	me 
&^
#include <stdio.h>

int main() {
	int i, n = 10;
	printf("Numbers from 1 to %d:\n", n);
	for (i = 1; i <= n; i++) 
		printf("%d ", i);

	int sum = 0;
	printf("Sum of numbers from 1 to %d is %d\n", n, sum);
	printf("^^ don't remove me");
	printf("^& nor me &^");
	printf("^& nor me ");
	printf(" nor me &^");

	return 0;
}

*/
#include <stdio.h>
#include <stdbool.h>

int	write_qoute(char *buff, int i)
{
	int c;
	while((c = getchar()) != '"' && c != EOF)
		buff[i++] = c;
	if (c == '"')
		buff[i++] = '"';
	return i;
}

void	skip_line_comment()
{
	int c;
	while ((c = getchar()) != EOF && c != '\n')
		continue;

}

void	skip_block_comment()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c == '&')
		{
			if ((c = getchar()) == '^')
				break ;
			else
				continue;
		}
		continue;
	}
}

void write_buff(char *buff)
{
	int i,c;
	i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '"')
			i = write_qoute(buff, i);
		if (c == '^')
		{
			if ((c = getchar()) == '^')
				skip_line_comment();
			else if (c == '&')
				skip_block_comment();
			else 
			{
				buff[i++] = '^';
				buff[i++] = c;
			}
			continue;
		}
		buff[i++] = c;
	}
	buff[i] = '\0';
}

int main()
{
	char buff[1024];

	write_buff(buff);
	printf("\n\n%s", buff);
}
