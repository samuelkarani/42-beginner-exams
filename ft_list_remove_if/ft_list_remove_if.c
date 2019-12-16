#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list)
		return;
	t_list *prev = 0, *cur = *begin_list;
	while (cur)
	{
		if ((*cmp)(cur->data, data_ref) == 0)
		{
			if (!prev)
				*begin_list = cur->next;
			else
				prev->next = cur->next;
		}
		else
			prev = cur;
		cur = cur->next;
	}
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	t_list b = (t_list){0, "a"};
	t_list a = (t_list){&b, "a"};
	t_list *_a = &a;
	ft_list_remove_if(&_a, "a", &strcmp);
	for (t_list *i = _a; i; i = i->next)
		printf("%s\n", i->data);
}
*/
