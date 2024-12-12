/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:42:53 by jfranco           #+#    #+#             */
/*   Updated: 2024/12/10 10:43:03 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_check(t_list **a, t_list **b)
{
	if (ft_lenstck(*a) == 2)
		ft_two_short(a);
	if (ft_lenstck(*a) == 3)
		ft_ts(a);
	else
		push_swap(a, b);
}

void	err(char ***str)
{
	free(str);
	write(2, "Error\n", 6);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv || !argv[0])
			err(&argv);
		ft_stack_init(&a, argv, true);
		free_argv(argv);
	}
	else
		ft_stack_init(&a, argv + 1, false);
	if (a != NULL && ft_sorted(&a) == 0)
		algo_check(&a, &b);
	free_stack(&a);
}
