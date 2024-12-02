
#include "push_swap.h"

void	exe_sa(t_list **head)
{
	write(1, "sa\n", 3);
	sa(head);
}

void	exe_ra(t_list **head)
{
	write(1,"ra\n", 3);
	ra(head);
}

void	exe_rra(t_list **head)
{
	write(1, "rra\n", 4);
	rra(head);
}

void	exe_pa(t_list **head_a, t_list **head_b)
{
	write(1, "pa\n", 3);
	pa(head_a, head_b);
}
