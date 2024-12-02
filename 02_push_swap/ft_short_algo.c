
#include "push_swap.h"

void	ft_ts(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->value;
	b = (*head)->next->value;
	c = (*head)->next->next->value;

	if(a > b && a > c)
	{
		exe_ra(head);
		if ((*head)->value > (*head)->next->value)
			exe_sa(head);
	}
	else if (c < b && c < a) // c piu piccolo
	{
		exe_sa(head);
		exe_rra(head);

	}
	else if (b > a && b > c) // b piu grande
	{
		exe_sa(head);
		exe_ra(head);
	}
	else if (b < c && b < a) //b piu piccolo
	{
		if (a < c)
			exe_sa(head);
		else 
			exe_ra(head);
	}
}

void	ft_two_short(t_list **head)
{
	int	a;
	int	b;

	a = (*head)->value;
	b = (*head)->next->value;
	if (a < b)
		return ;
	else if (b < a)
		exe_sa(head);
}
