#include <unistd.h>

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int findex(char c)
{
	char *s = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; s[i]; i++)
		if (c == s[i])
			return i;
	return -1;
}

void fatoi(int n)
{
	if (n >= 10)
		fatoi(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	int options = 0, error = 0;
	for (int i = 1; i < ac; i++)
	{
		char *s = av[i];
		if (s[0] == '-')
		{
			for (int j = 1; s[j]; j++)
			{
				int idx = findex(s[j]);
				if (idx == -1)
				{ 
					error = 1;
					break;
				}
				options |= 1 << idx;
			}
		}

	}
	if (error)
		fputstr("Invalid Option");
	else if (ac == 1 || options & 1 << 7)
		fputstr("options: abcdefghijklmnopqrstuvwxyz");
	else
		fatoi(options);
	write(1, "\n", 1);
}
