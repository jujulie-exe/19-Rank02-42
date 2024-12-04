
#include "push_swap.h"

void	sa_exe(t_list **head)
{
	int	temp;
	if(*head && (*head)->next != *head)
	{
		temp = (*head)->value;
		(*head)->value = (*head)->next->value;
		(*head)->next->value = temp;
	}
}

void	sa(t_list **head)
{
	sa_exe(head);
	write(1, "sa\n", 3);
}


void	sb(t_list **head)
{
	sa_exe(head);
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	sa_exe(head_a);
	sa_exe(head_b);
	write(1, "ss\n", 3);
}
