#ifndef	PUSH_SWAP_H
#define	PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
typedef	struct s_list
{
	int		value;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

void	rra(t_list **head);
void	rrb(t_list **head);
void	rrr(t_list **head_a, t_list **head_b);

void	sa(t_list **head);
void	sb(t_list **head);
void	ss(t_list **head_a, t_list **head_b);

void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_b, t_list **head_a);

void	ra(t_list **head);
void	rb(t_list **head);
void	rr(t_list **head_a, t_list **head_b);

t_list	*lstnew(int value);
void	lstadd(t_list **head, int value);
void	lstdelone(t_list **head, t_list *node);
void	lstclear(t_list **head);

#endif
