#include "push_swap.h"

void	pa(t_list **head_a, t_list **head_b)
{
	int		tmp;
	t_list	*old_head_b;

	if (empty(head_b) == 0)
		return ;
	old_head_b = *head_b;
	tmp = (*head_b)->value;
	if (*head_a == NULL)
		*head_a = lstnew(tmp);
	else
		lstadd_head(head_a, tmp);
	lstdelone(head_b, old_head_b);
	write(1, "pa\n", 3);
}

void	pb(t_list **head_b, t_list **head_a)
{
	int		tmp;
	t_list	*old_head_a;

	if (empty(head_a) == 0)
		return ;
	old_head_a = *head_a;
	tmp = (*head_a)->value;
	if (*head_b == NULL)
		*head_b = lstnew(tmp);
	else
		lstadd_head(head_b, tmp);
	lstdelone(head_a, old_head_a);
	write(1, "pb\n", 3);
}
