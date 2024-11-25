
#include "push_swap.h"

void	pa(t_list **head_a, t_list **head_b)
{
	t_list	*to_move;

	if (*head_b == NULL)
	{
		to_move = *head_b;
		head_b = (*head_b)->next;

		if (*head_b != null)
			(*head_b)->prev = to_move->prev;
	}
	to_move->next = *head_a;
	to_move->prev = (*head_a)->prev;
	(*head_a)->prev = to_move;
	head_a = to_move;
}

void	pb(t_list **head_b, t_list **head_a)
{
	t_list	*to_move;

	if (*head_a == NULL)
	{
		to_move = *head_a;
		head_a = (*head_a)->next;

		if (*head_a != null)
			(*head_a)->prev = to_move->prev;
	}
	to_move->next = *head_b;
	to_move->prev = (*head_b)->prev;
	(*head_b)->prev = to_move;
	head_b = to_move;
}
