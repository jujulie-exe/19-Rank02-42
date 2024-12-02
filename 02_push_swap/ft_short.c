
#include "push_swap.h"

int	empty(t_list **head)
{
	if(head == NULL || *head == NULL)
		return (0);
	else
		return (1);
}

long	min(t_list **head)
{
	long	min;
	t_list	*current;
	if (head == NULL || *head == NULL)
		return (LONG_MAX);
	min = (*head)->value;
	current = *head;
	while ((1))
	{
		current = current->next;
		if (min > current->value)
			min = current->value;
		if (current == *head)
			return (min) ;
	}
	return (min);
}
void	insertion_short(t_list **head_a, t_list **head_b)
{
	long min_value;

	while (empty(head_a))
	{
		min_value = min(head_a);
		if (min_value == LONG_MAX)
			break ;
		while ((*head_a)->value != min_value)
			exe_ra(head_a);
		exe_pb(head_b, head_a);
	}
	while (empty(head_b))
		exe_pa(head_a, head_b);
}

