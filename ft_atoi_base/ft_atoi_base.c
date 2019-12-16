int valid_index(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	const char *s = "0123456789abcdef";
	for (int i = 0; s[i]; i++)
		if (c == s[i])
			return i;
	return -1;
}

int     ft_atoi_base(const char *str, int str_base)
{
	if (!str || str_base > 16)
		return 0;
	int i = 0, neg = str[0] == '-';
	if (neg)
		i++;
	int sum = 0;
	for (; str[i]; i++)
	{
		sum *= str_base;
		int v = valid_index(str[i]);
		if (v == -1)
			return 0;
		sum += v;
	}
	return sum * (neg ? -1 : 1);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
}
*/
