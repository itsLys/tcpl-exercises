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

int any(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
	{
		if (find_in(s1[i], s2))
			return i;
		i++;
	}
	return -1;

}

int main(void)
{
	printf("%d\n", any("Hello", "e"));
}
