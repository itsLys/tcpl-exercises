#include <stdio.h>
int find_in(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return 1;
		str++;
	}
	return 0;
}

void	squeeze(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i])
	{
		if (!find_in(s1[i], s2))
			s1[j++] = s1[i];
		i++;
	}
	s1[j] = '\0';
}
// Hello
// oeH

int main()
{
	char str[] = "Hello";
	squeeze(str, "oeH");
	printf("%s", str);
}
