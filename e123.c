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
	int in_comment = false;
	bool in_qoute = false;
	i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '^')
		{
			if ((c = getchar()))
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
