#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int find_patt(char *str, char *patt)
{
	unsigned str_l = strlen(str);
	unsigned patt_l = strlen(patt);
	int i = str_l - 1;
	int k = 0;
	int j;
	if (patt_l)
	{
		while (i >= 0)
		{
			if (str[i] == patt[patt_l - 1])
			{
				j = patt_l - 1;
				k = 0;
				while (str[i - k] == patt[j] && j >= 0 && i - k >= 0)
				{
					k++;
					j--;
				}
				if (j == -1)
				{
					return i - k + 1;
				}
			}
			i--;
		}
	}
	return -1;
}

int main(int ac, char **av)
{
	if (ac != 3)
		return 1;
	printf("str: \"%s\"\npatt: \"%s\"\nlast occurence: %d\n", av[1], av[2], find_patt(av[1], av[2]));
}
