#include <stdio.h>
int get_index(char c)
{
	char hex[] = "0123456789abcdef";
	char HEX[] = "0123456789ABCDEF";
	int i = 0;
	while (i < 16)
	{
		if (hex[i] == c || HEX[i] == c)
			return i;
		i++;
	}
	return -1;
}

int htoa(char *s)
{
	int i = 0;
	int n = 0;
	if (s[i] && s[i] == '0' && s[i + 1] && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		i += 2;
	while (s[i])
		n = n * 16 + get_index(s[i++]);
	return n;
}

int main()
{
	printf("%d\n", htoa("f"));;
}
