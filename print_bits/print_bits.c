#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 128;
	while (i)
	{
		if (octet >= i)
		{
			write(1, "1", 1);
			octet %= i;
		}
		else
		{
			write(1, "0", 1);
		}
		i >>= 1;
	}
}

int main(void)
{
	print_bits(16);
	return (0);
}
