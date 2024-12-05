
#include "push_swap.h"

void ra_exe(t_list **head)
{
	if (*head && (*head)->next != *head)
	{
		*head = (*head)->next;
	}
	/*
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
	}*/
}

void ra(t_list **head)
{
	ra_exe(head);
	write(1, "ra\n", 3);
}


void	rb(t_list **head)
{
	ra_exe(head);
	write(1, "rb\n", 3);
}

void rr(t_list **head_a, t_list **head_b)
{
	ra_exe(head_a);
	ra_exe(head_b);
	write(1, "rr\n", 3);
}
