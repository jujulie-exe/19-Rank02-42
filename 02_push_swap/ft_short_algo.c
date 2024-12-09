#include "push_swap.h"

void	ft_ts(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->value;
	b = (*head)->next->value;
	c = (*head)->next->next->value;
	if (a > b && a > c)
	{
		ra(head);
		if ((*head)->value > (*head)->next->value)
			sa(head);
	}
	else if (c < b && c < a)
		rra(head);
	else if (b > a && b > c)
	{
		sa(head);
		ra(head);
	}
	else if (b < c && b < a)
	{
		if (a < c)
			sa(head);
		else
			ra(head);
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
		sa(head);
}
