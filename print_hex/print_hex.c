#include <unistd.h>

void print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	int v = n % 16;
	char c = v >= 10 ? v - 10 + 'a' : v + '0';
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int sum = 0;
		for (int i = 0; s[i]; i++)
		{
			sum *= 10;
			sum += s[i] - '0';
		}
		print_hex(sum);
	}
	write(1, "\n", 1);
}
