#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		for (int i = 0; s[i]; i++)
		{
			char c;
			if (s[i] == 90)
				c = 'A';
			else if (s[i] == 122)
				c = 'a';
			else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
				c = s[i] + 1;
			else
				c = s[i];
			write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
}
