#include "push_swap.h"

void	exe_rrr(t_list **head_a, t_list **head_b)
{
	write(1, "rrr\n", 4);
	rrr(head_a, head_b);
}

void	exe_ss(t_list **head_a, t_list **head_b)
{
	write(1, "ss\n", 3);
	ss(head_a, head_b);
}

void	exe_rr(t_list **head_a, t_list **head_b)
{
	write(1, "rr\n", 3);
	rr(head_a, head_b);
}
