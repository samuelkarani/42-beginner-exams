#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int fiss(char c)
{
	return c == ' ' || c == '\t';
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char *fstrsub(char *s, int start, int end)
{
	char *r = malloc(end - start);
	int i = 0;
	while (start < end)
		r[i++] = s[start++];
	r[i] = 0;
	return r;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int n = fstrlen(s),  start = 0, idx = 0;
		char *words[n];
		for (int i = 0; s[i]; i++)
		{
			if (fiss(s[i]) && !fiss(s[i - 1]))
			{
				words[idx++] = fstrsub(s, start, i);
				words[idx++] = fstrsub(s, i, i + 1);
				start = i + 1;
			}
		}
		words[idx] = fstrsub(s, start, n);
		for (int i = idx; i >= 0; i--)
			fputstr(words[i]);
	}
	write(1, "\n", 1);
}
