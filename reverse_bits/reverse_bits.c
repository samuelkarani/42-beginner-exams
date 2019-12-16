#include <stdio.h>

unsigned int reversebits(unsigned int num) 
{
	int i = 0;
	int rev = 0;

	while (i < 8)
	{
		if (num & (1 << i))
			rev |= (1 << (8 - i - 1));
		i++;
	}
	return rev;
}

int main(void)
{
	printf("%d\n", reversebits(11));
	return (0);
}
