
#include "push_swap.h"

void	ft_pa(t_list **head_a, t_list **to_move)
{
	t_list	*last_a;

	if(head_a == NULL)
	{
		*head_a = to_move;
		to_move->next = to_move;
		to_move->prev = to_move;
	}
	else
	{
		last_a = (*head_a)->prev;
		to_move->next = *head_a;
		to_move->prev = last_a;
		last_a->next = to_move;
		(*head_a)->prev = to_move;
		*head_a = to_move;
	}
}

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*to_move;
	t_list	*last_b;

	if (*head_b == NULL)
		return ;
	to_move = *head_b;
	if((*head_b)->next == *head_b)
	{
		*head_b = NULL;
	}
	else
	{
		last_b = (*head_b)->prev;
		(*head_b)->prev = last_b;
		last_b->next = *head_b;
	}
	ft_pa(head_a, to_move);
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
	ft_pa(head_a, to_move);
}
