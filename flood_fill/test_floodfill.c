#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "flood_fill2.h"

void flood_fill(char **tab, t_point size, t_point begin);

void fputchar(char c)
{
	write(1, &c, 1);
}

void fputstr(char *s)
{
	while (*s)
	{
		fputchar(*s++);
		fputchar(' ');
	}
}

void print_tab(char **area)
{
	while (*area)
	{
		fputstr(*area++);
		fputchar('\n');
	}
}

char **make_area(char *zone[], int l)
{
	char **area = (char **)malloc(1 + l * sizeof(char *));
	area[l] = NULL;
	int i = 0;
	while (i < l)
	{
		int slen = strlen(zone[i]);
		area[i] = (char *)malloc(1 + slen * sizeof(char));
		area[i][slen] = 0;
		strcpy(area[i], zone[i]);
		i++;
	}
	return (area);
}

int main(void)
{
	char **area;
	t_point size = {2, 3};
	t_point begin = {1, 1};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"};

	char *zone2[] = {
		"00",
		"00",
		"01"};
	area = make_area(zone2, size.y);
	print_tab(area);
	flood_fill(area, size, begin);
	fputchar('\n');
	print_tab(area);
	return (0);
}
