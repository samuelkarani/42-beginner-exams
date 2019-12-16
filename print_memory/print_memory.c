#include <unistd.h>
#include <stdio.h>

void fputchar(char c)
{
	write(1, &c, 1);
}

int	fisprint(char c)
{
	return (c > 31 && c < 127);
}

void converthex(int n, char hexnum[], int idx)
{
	if (n >= 16)
		converthex(n / 16, hexnum, idx - 1);
	int mod = n % 16;
	hexnum[idx] = mod < 10 ? mod + '0' : mod - 10 + 'a';
}

int getlen(int n)
{
	int i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void zerofill(char hexnum[])
{
	int i = 0;
	while (i < 8)
		hexnum[i++] = 0;
}

void print_dots(const void *addr, int i, int last)
{
	int j = last;
	while (j < i)
	{
		int p = fisprint(((int *)addr)[j]);
		if (p)
			fputchar(((int *)addr)[j]);
		int k = 0;
		while (k++ < 4 - p)
			fputchar('.');
		j++;
	}
	fputchar('\n');
}

void	print_memory(const void *addr, size_t size)
{
	int len = size / sizeof(int);
	int i = 0;
	int last = 0;
	char hexnum[8] = {0};
	int lastdots = 0;
	while (i < len)
	{
		if (i > 0 && i % 4 == 0)
		{
			print_dots(addr, i, last);
			last = i;
		}
		int nlen = getlen(((int *)addr)[i]);
		if (nlen)
			converthex(((int *)addr)[i], hexnum, nlen - 1);
		int j = 0;
		int k = 0;
		while (j < 9)
		{
			if (nlen == 1 && j == 0)
				fputchar('0');
			else if (j == 4)
				fputchar(' ');
			else if (j < 8 && k < nlen)
				fputchar(((char *)hexnum)[k++]);
			else
				fputchar('0');
			j++;
		}
		fputchar(' ');
		i++;
		zerofill(hexnum);
	}
	if (i > 0 && i % 4 != 0)
	{
		int j = 0;
		while (j < 4 - i % 4)
		{
			int k = 0;
			while (k++ < 9)
				fputchar(' ');
			fputchar(' ');
			j++;
		}
	}
	print_dots(addr, i, last);
}

