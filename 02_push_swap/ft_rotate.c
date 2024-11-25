
#include "push_swap.h"

void	ra(t_list **head)
{
	t_list	*first;
	t_list	*last;

	if (*head && (*head)->next != *head)
	{
		first = *head;
		last = (*head)->prev;
		*head = (*head)->next;
		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}

void	ra(t_list **head)
{
	t_list	*first;
	t_list	*last;

	if (*head && (*head)->next != *head)
	{
		first = *head;
		last = (*head)->prev;
		*head = (*head)->next;
		first->next = NULL;
		first->prev = last;
		last->next = first;
	}
}

void rr(t_list **head_a, t_list **head_b)
{
	ra(head_a);
	rb(head_b);
}
