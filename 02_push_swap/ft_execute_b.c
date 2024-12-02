
#include "push_swap.h"

void	exe_sb(t_list **head)
{
	write(1, "sb\n",3);
	sb(head);
}

void	exe_rb(t_list **head)
{
	write(1, "rb\n", 3);
	rb(head);
}

void	exe_rrb(t_list **head)
{
	write(1, "rrb\n", 4);
	rrb(head);
}

void	exe_pb(t_list **head_b, t_list **head_a)
{
	write(1, "pb\n", 3);
	pb(head_b, head_a);
}
