#include <unistd.h>

int main()
{
	unsigned char num = 11;
	int i = 0;
	while (i < 8)
	{
		if (num & (1 << (8 - i - 1)))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i++;
	}
}
