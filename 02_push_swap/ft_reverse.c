
#include "push_swap.h"

void rra(t_list **head)
{
	t_list	*last;
	t_list	*current;
	int	tmp;
	if (*head && (*head)->next != *head) 
	{
		last = (*head)->prev;
		tmp = last->value;
		current = last;
		while (current != *head)
		{
			current->value = current->prev->value;
			current = current->prev;
		}
		(*head)->value = tmp;
	}
}

void	rrb(t_list **head)
{
	rra(head);
}

void rrr(t_list **head_a, t_list **head_b)
{
	rra(head_a);
	rrb(head_b);
}
