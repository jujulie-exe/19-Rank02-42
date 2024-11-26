
#include "push_swap.h"

void	sa(t_list **head)
{
	t_list	*first;
	t_list	*second;
	if(*head && (*head)->next != *head)
	{
		first = head;
		second = (*head)->next;
		first->next = second->next;
		first->next->prev = first;
		second->prev = first->prev;
		second->next = first;
		first->prev = second;
		*head = second;
	}
}

void	sb(t_list **head)
{
	sa(head);
}


void	ss(t_list **head_a, t_list **head_b)
{
	sa(head_a);
	sb(head_b);
}
