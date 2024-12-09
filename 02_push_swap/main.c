#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_stack_init(&a, argv, true);
		free_argv(argv);
	}
	else
		ft_stack_init(&a, argv + 1, false);
	if (a != NULL)
	{
		if (ft_lenstck(a) == 2)
			ft_two_short(&a);
		if (ft_lenstck(a) == 3)
			ft_ts(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
