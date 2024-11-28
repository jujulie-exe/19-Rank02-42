
#include "push_swap.h"

void	sa(t_list **head)
{
	int	temp;
	if(*head && (*head)->next != *head)
	{
		temp = (*head)->value;
		(*head)->value = (*head)->next->value;
		(*head)->next->value = temp;
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
