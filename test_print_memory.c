#include <stdlib.h>
#include <unistd.h>

void	print_memory(const void *addr, size_t size);

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};
	print_memory(tab, sizeof(tab));
	write(1, "\n", 1);
	char s[] = " Hello	42!!*";
	print_memory(tab, sizeof(s));
	return (0);
}
