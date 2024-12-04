
#include "push_swap.h"

void rra_exe(t_list **head)
{
	
	if (*head && (*head)->next != *head) 
		*head = (*head)->prev;
/*	t_list	*last;
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
	}*/
}

void rra(t_list **head)
{
	rra_exe(head);
	write(1, "rra\n", 4);
}

void	rrb(t_list **head)
{
	rra_exe(head);
	write(1, "rrb\n", 4);
}

void rrr(t_list **head_a, t_list **head_b)
{
	rra_exe(head_a);
	rra_exe(head_b);
	write(1, "rrr\n", 4);
}
