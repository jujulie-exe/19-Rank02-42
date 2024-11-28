
#include "push_swap.h"


void	pa(t_list **head_a, t_list **head_b)
{
	int	tmp;
	t_list	*new_head;

	
	if(*head_b == NULL)
		return ;
	tmp = (*head_b)->value;
	lstadd_head(head_a, tmp);
	new_head = *head_b;
	lstdelone(head_b, *head_b);
}


void	pb(t_list **head_b, t_list **head_a)
{
	t_list	*to_move;
	t_list	*last_a;

	if (*head_a == NULL)
		return ;
	to_move = *head_a;
	if((*head_a)->next == *head_a)
	{
		*head_a = NULL;
	}
	else
	{
		last_a = (*head_a)->prev;
		(*head_a)->prev = last_a;
		last_a->next = *head_a;
	}
}
