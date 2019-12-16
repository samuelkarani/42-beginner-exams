#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!av[2][1] && !av[3][1])
		{
			char *s = av[1];	
			for (int i = 0; s[i]; i++)
				if (s[i] == av[2][0])
					s[i] = av[3][0];
			int i = 0;
			while (s[i])
				write(1, s++, 1);
		}
	}
	write(1, "\n", 1);
}
