
#include "push_swap.h"

void ra(t_list **head)
{
	t_list	*current;
	t_list	*first;
	int	tmp;
	
	if (*head && (*head)->next != *head)
	{
		first = *head;
		tmp = first->value;
		current = first;
		while (current->next != *head)
		{
			current->value = current->next->value;
			current = current->next;
		}
		current->value = tmp;
	}
}


void	rb(t_list **head)
{
	ra(head);
}

void rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
}
