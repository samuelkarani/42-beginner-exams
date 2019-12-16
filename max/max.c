int             max(int* tab, unsigned int len)
{
	int mx = 0;
	for (unsigned int i = 0; i < len; i++)
		if (tab[i] > mx)
			mx = tab[i];
	return mx;
}

/**
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	int arr[ac - 1];
	for (int i = 1; i < ac; i++)
		arr[i - 1] = atoi(av[i]);
	printf("%d\n", max(arr, ac - 1));
}
**/
