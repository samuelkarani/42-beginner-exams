typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	int x = begin.x, y = begin.y;
	int sx = size.x, sy = size.y;
	int c = tab[y][x];
	tab[y][x] = 'F';

	if (x < sx - 1 && tab[y][x + 1] == c)
		flood_fill(tab, size, (t_point){x + 1, y});
	if (y < sy - 1 && tab[y + 1][x] == c)
		flood_fill(tab, size, (t_point){x, y + 1});
	if (x > 0 && tab[y][x - 1] == c)
		flood_fill(tab, size, (t_point){x - 1, y});
	if (y > 0 && tab[y - 1][x] == c)
		flood_fill(tab, size, (t_point){x, y - 1});
}

