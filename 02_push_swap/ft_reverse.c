
#include "push_swap.h"

void	rra(t_list **head)
{
	t_list *second;
	t_list *first_last;
	t_list	*end;

	if(*head && (*head)->next != *head)
	{
		first_last = (*head)->prev;
		*head = first_last->next;
		second = (*head)->next;
		end = (*head)->prev;
		(*head)->next = second->next;
		second->next->prev = *head;
		second->next = *head;
		(*head)->prev = second;
		end->next = second;
		second->prev = end;
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
