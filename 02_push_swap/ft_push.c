
#include "push_swap.h"


void	pa(t_list **head_a, t_list **head_b)
{
	int	tmp;
	
	if(*head_b == NULL)
		return ;
	tmp = (*head_b)->value;
	if (*head_a == NULL)
		*head_a = lstnew(tmp);
	else
		lstadd_head(head_a, tmp);
	lstdelone(head_b, *head_b);
}


void	pb(t_list **head_b, t_list **head_a)
{
	int	tmp;
	
	if(*head_a == NULL)
		return ;
	tmp = (*head_a)->value;
	if (*head_b == NULL)
		*head_b = lstnew(tmp);
	else
		lstadd_head(head_b, tmp);
	lstdelone(head_a, *head_b);
}
