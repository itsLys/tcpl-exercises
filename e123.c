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
void write_buff(char *buff)
{
	int i,c;
	i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '"' )
		{
			buff[i++] = c;
			while ((c = getchar()) != EOF && c != '"')
				buff[i++] = c;
		}
		if (c == '^')
		{
			if ((c = getchar()) == '^')
				while ((c = getchar()) != '\n' && c != EOF)
					continue ;
			else if (c == '&')
				{
					while ((c = getchar()) != '&' && c != EOF)
					{
						if ((c = getchar()) == '^' || c == EOF )
							break;
						else
							continue ;
					}
				}
			else
				buff[i++] = '^';
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
