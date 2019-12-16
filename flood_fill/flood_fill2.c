#include <unistd.h>
#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char same = 0;
	char c;
	int i = begin.y - 1;
	while (i < size.y)
	{
		int j = begin.x - 1;
		while (j < size.x)
		{
			c = tab[i][j];
			if (!same)
				same = c;
			if (c == same)
				tab[i][j] = 'F';
			if (c != same)
				break ;
			j++;
		}
		i++;
	}
}
