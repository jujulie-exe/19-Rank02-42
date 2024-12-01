
#include "push_swap.h"

void	ft_ts(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->value;
	b = (*head)->next->value;
	c = (*head)->next->next->value;

	if(a > b && a > c) // a piu grande
		ra(head);
	else if (c < b && c < a) // c piu piccolo
	{
		sa(head);
		rra(head);
	}
	else if (b > a && b > c) // b piu grande
	{
		sa(head);
		ra(head);
	}
	else if (b < c && b < a) //b piu piccolo
	{
		if (a > c)
			sa(head);
		ra(head);
	}

}
