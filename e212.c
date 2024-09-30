#include <stdio.h>
#include <string.h>


char *lower(char *str)
{
	char *copy = strdup(str);
	int i = 0;
	while (copy[i])
	{
		copy[i] += (copy[i] >= 'A') && (copy[i] <= 'Z') ? 'a' - 'A' : 0;
		i++;
	}
	return copy;
}

int main()
{
	printf("%s\n", lower("Hello"));
}
