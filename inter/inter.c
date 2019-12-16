#include <unistd.h>

int contains(char *s, char c)
{
	for (int i = 0; s[i]; i++)
		if (s[i] == c)
			return i;
	return -1;
}

int fstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void zero(char *s, int n)
{
	for (int i = 0; i < n; i++)
		s[i] = 0;
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *s = av[1];
		char *r = av[2];
		int idx = 0, n = fstrlen(s);
		char mem[n];
		zero(mem, n);
		for (int i = 0; s[i]; i++)
		{
			if (contains(mem, s[i]) == -1 && contains(r, s[i]) != -1)
			{
				write(1, &s[i], 1);
				mem[idx++] = s[i];
			}
		}
	}
	write(1, "\n", 1);
}
