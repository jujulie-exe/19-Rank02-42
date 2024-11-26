
#include "push_swap.h"

void	rra(t_list **head)
{
	t_list *last;
	t_list *second_last;

	if(*head && (*head)->next != head)
	{
		last = (*head)->prev;
		second_last = last->prev;
		second_last->next = *head;
		(*head)->prev = second_last;
		last->prev = NULL;
		last->next = (*head);
		(*head)->prev = last;
		head = last;
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
