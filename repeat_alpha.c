#include <string.h>
#include <unistd.h>

void fputchar(char c)
{
	write(1, &c, 1);
}

int fislower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int fisupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int fisalpha(char c)
{
	return (fislower(c) || fisupper(c));
}

int getindex(int c)
{
	if (fislower(c))
		return (c - 'a');
	return (c - 'A');
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int i = 0;
		while (i < strlen(s))
		{
			int j = 0;
			fputchar(s[i]);
			if (fisalpha(s[i]))
			{
				while (j < getindex(s[i]))
				{
					fputchar(s[i]);
					j++;
				}
			}
			i++;
		}
	}
	fputchar('\n');
	return (0);
}
