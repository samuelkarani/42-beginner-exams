#include <stdio.h>

int swap(int n)
{
	return ((n >> 4) | (n << 4));
}

int main(void)
{
	printf("%d\n", swap(6));
	printf("%d\n", swap(100));
	return (0);
}
