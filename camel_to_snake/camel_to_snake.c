#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		for (int i = 0; s[i]; i++)
		{
			char c = 0;
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] += 32;
				if (i > 0)
					c = 1;
			}
			if (c)
				write(1, "_", 1);
			write(1, &s[i], 1);
		}
	}
	write(1, "\n", 1);
}
